#include "SelectionTool.hpp"
#include "Selection.hpp"
#include "Group.hpp"

#include <QMouseEvent>

SelectionTool::SelectionTool(Group *mainGroup) :
    m_mainGroup(mainGroup)
{
    m_selection = &Selection::getInstance();
}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event)
{
    VisualEntity *clicked = m_mainGroup->getClicked(event->pos().x(), event->pos().y());

    if (clicked != nullptr) {
        m_selection->deselectAll();
        clicked->setSelected(true);
    } else {
        m_selection->deselectAll();
    }
}

