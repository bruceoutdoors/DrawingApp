#include "DrawLineTool.hpp"
#include "DrawLineCommand.hpp"

#include "GlobalDrawProperties.hpp"
#include "ActiveSelection.hpp"
#include "Line.hpp"
#include "Canvas.hpp"

#include <QMouseEvent>

DrawLineTool::DrawLineTool(Canvas *canvas) :
    Tool(canvas),
    m_clickPressed(false)
{
    m_selection = &ActiveSelection::getInstance();
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

void DrawLineTool::mouseRelease(QMouseEvent *)
{
    m_clickPressed = false;
    m_selection->deselectAll();
    m_line->setSelected(true);

    DrawLineCommand *comm = new DrawLineCommand(m_line);
    comm->addtoCommandStack();
}

