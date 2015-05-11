#include "SelectionTool.hpp"
#include "Selection.hpp"
#include "Group.hpp"
#include "Canvas.hpp"

#include <QMouseEvent>

SelectionTool::SelectionTool(Canvas *canvas) :
    Tool(canvas)
{
    m_selection = &Selection::getInstance();
}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event)
{
    VisualEntity *clicked = m_canvas->getVEFromPosition(event->pos().x(), event->pos().y());

    if (clicked != nullptr) {
        m_selection->deselectAll();
        clicked->setSelected(true);
    } else {
        m_selection->deselectAll();
    }
}

