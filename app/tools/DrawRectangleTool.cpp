#include "GlobalDrawProperties.hpp"
#include "DrawRectangleTool.hpp"
#include "DrawRectangleCommand.hpp"
#include "ActiveSelection.hpp"
#include "Rectangle.hpp"
#include "Canvas.hpp"

#include <QMouseEvent>

DrawRectangleTool::DrawRectangleTool(Canvas *canvas) :
    Tool(canvas),
    m_clickPressed(false)
{
    m_selection = &ActiveSelection::getInstance();
}

DrawRectangleTool::~DrawRectangleTool()
{

}

void DrawRectangleTool::mousePress(QMouseEvent *event)
{
    m_clickPressed = true;
    m_startPosition = event->pos();

    m_rectangle = new Rectangle();
    m_canvas->addVisualEntity(m_rectangle);
    m_rectangle->setPosition(m_startPosition);

    m_rectangle->setWidth(2);
    m_rectangle->setHeight(2);
}

void DrawRectangleTool::mouseMove(QMouseEvent *event)
{
    if (m_clickPressed) {
        int distX = event->x() - m_startPosition.x();
        int distY = event->y() - m_startPosition.y();

        if (distX < 0) {
            m_rectangle->setPosition(
                        QPoint(event->x(), m_rectangle->getPosition().y()));
        } else {
            m_rectangle->setPosition(
                        QPoint(m_startPosition.x(), m_rectangle->getPosition().y()));
        }

        if (distY < 0) {
            m_rectangle->setPosition(
                        QPoint(m_rectangle->getPosition().x(), event->y()));
        } else {
            m_rectangle->setPosition(
                        QPoint(m_rectangle->getPosition().x(), m_startPosition.y()));
        }

        m_rectangle->setWidth(std::abs(distX));
        m_rectangle->setHeight(std::abs(distY));
    }
}

void DrawRectangleTool::mouseRelease(QMouseEvent *event)
{
    m_clickPressed = false;
    m_selection->deselectAll();
    m_rectangle->setSelected(true);

    DrawRectangleCommand *comm = new DrawRectangleCommand(m_rectangle);
    comm->addtoCommandStack();
}

