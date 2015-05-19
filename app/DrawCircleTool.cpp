#include "DrawCircleTool.hpp"
#include "Selection.hpp"
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
    m_selection = &Selection::getInstance();
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

void DrawCircleTool::mouseRelease(QMouseEvent *event)
{
    m_clickPressed = false;
    m_selection->removeAll();
    m_selection->add(m_circle);
}

