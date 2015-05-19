#include "DrawLineTool.hpp"

#include "Selection.hpp"
#include "Line.hpp"
#include "Canvas.hpp"

#include <QMouseEvent>

DrawLineTool::DrawLineTool(Canvas *canvas) :
    Tool(canvas),
    m_clickPressed(false)
{
    m_selection = &Selection::getInstance();
}

DrawLineTool::~DrawLineTool()
{

}

void DrawLineTool::mousePress(QMouseEvent *event)
{
    m_clickPressed = true;
    m_startPosition = event->pos();

    m_line = new Line();
    m_canvas->addVisualEntity(m_line);
    m_line->setP1(m_startPosition);
    m_line->setP2(m_startPosition);
}

void DrawLineTool::mouseMove(QMouseEvent *event)
{
    if (m_clickPressed) {
        m_line->setP2(event->pos());
    }
}

void DrawLineTool::mouseRelease(QMouseEvent *event)
{
    m_clickPressed = false;
    m_selection->removeAll();
    m_selection->add(m_line);
}

