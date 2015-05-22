#include "SelectionTool.hpp"
#include "ActiveSelection.hpp"
#include "Group.hpp"
#include "Canvas.hpp"
#include "GlobalDrawProperties.hpp"

#include <QMouseEvent>

SelectionTool::SelectionTool(Canvas *canvas) :
    Tool(canvas)
{
    m_selection = &ActiveSelection::getInstance();
    m_gp = &GlobalDrawProperties::getInstance();
}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event)
{
    VisualEntity *clicked =
            m_canvas->getVEFromPosition(event->pos().x(), event->pos().y());

    if (clicked != nullptr) {
        if (!(event->modifiers() & Qt::ShiftModifier)) {
            m_selection->deselectAll();
        }

        clicked->setSelected(true);
    } else {
        m_selection->deselectAll();
        m_gp->unlinkProperties();
    }
}

