#include "DrawCircleTool.hpp"
#include "DrawCircleCommand.hpp"
#include "GlobalDrawProperties.hpp"
#include "ActiveSelection.hpp"
#include "Group.hpp"
#include "Canvas.hpp"
#include "Circle.hpp"

#include <QMouseEvent>
#include <cmath>
#include <QDebug>

DrawCircleTool::DrawCircleTool(Canvas *canvas) :
    Tool(canvas),
    m_clickPressed(false)
{
    m_selection = &ActiveSelection::getInstance();
}

DrawCircleTool::~DrawCircleTool()
{

}

void DrawCircleTool::mousePress(QMouseEvent *event)
{
    m_clickPressed = true;
    m_startPosition = event->pos();

    m_circle = new Circle();
    m_canvas->addVisualEntity(m_circle);
    m_circle->setPosition(m_startPosition);
    m_circle->setRadius(2);

}

void DrawCircleTool::mouseMove(QMouseEvent *event)
{
    if (m_clickPressed) {
        // calculate distance:
        int distX = event->x() - m_startPosition.x();
        int distY = event->y() - m_startPosition.y();
        int dist = std::sqrt(distX*distX + distY*distY);

        m_circle->setRadius(dist);
    }
}

void DrawCircleTool::mouseRelease(QMouseEvent *)
{
    m_clickPressed = false;
    m_selection->deselectAll();
    m_circle->setSelected(true);

    DrawCircleCommand *comm = new DrawCircleCommand(m_circle);
    comm->addtoCommandStack();
}

