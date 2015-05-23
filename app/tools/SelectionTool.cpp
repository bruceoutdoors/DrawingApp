#include "SelectionTool.hpp"
#include "ActiveSelection.hpp"
#include "Group.hpp"
#include "Canvas.hpp"
#include "GlobalDrawProperties.hpp"
#include "MoveSelectionCommand.hpp"

#include <QMouseEvent>

SelectionTool::SelectionTool(Canvas *canvas) :
    Tool(canvas),
    m_movComm(nullptr), m_clicked(nullptr),
    m_isMousePressed(false), m_hasMoved(false)
{
    m_selection = &ActiveSelection::getInstance();
    m_gp = &GlobalDrawProperties::getInstance();
}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event)
{
    m_isMousePressed = true;
    m_mousePressedLoc = event->pos();

    VisualEntity *clicked =
            m_canvas->getVEFromPosition(event->pos().x(), event->pos().y());

    if (clicked != nullptr
            && m_selection->getSize() <= 1
            && !(event->modifiers() & Qt::ShiftModifier)) {
                m_selection->deselectAll();
                clicked->setSelected(true);
    }

    if (m_selection->getSize() > 0
            && m_selection->contains(event->pos().x(), event->pos().y())) {
        m_movComm = new MoveSelectionCommand(m_mousePressedLoc);
    }
}

void SelectionTool::mouseMove(QMouseEvent *event)
{
    if (m_isMousePressed
            && m_movComm) {
        m_movComm->setPosition(event->pos());
        m_movComm->execute();
        m_hasMoved = true;
    }
}

void SelectionTool::mouseRelease(QMouseEvent *event)
{
    VisualEntity *clicked =
            m_canvas->getVEFromPosition(event->pos().x(), event->pos().y());

    if (clicked != nullptr) {
        if (!m_hasMoved) {
            if ((event->modifiers() & Qt::ShiftModifier)) {
                clicked->toogleSelect();
            } else {
                m_selection->deselectAll();
                clicked->setSelected(true);
            }
        }
    } else {
        m_selection->deselectAll();
        m_gp->unlinkProperties();
    }

    if (m_hasMoved) {
        m_movComm->addtoCommandStack();
        m_movComm = nullptr;
        m_hasMoved = false;
    } else if (m_movComm) {
        delete m_movComm;
        m_movComm = nullptr;
    }

    m_isMousePressed = false;
}

