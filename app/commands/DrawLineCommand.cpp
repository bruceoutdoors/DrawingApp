#include "DrawLineCommand.hpp"
#include "GlobalDrawProperties.hpp"
#include "ActiveSelection.hpp"
#include "Line.hpp"
#include "Group.hpp"

DrawLineCommand::DrawLineCommand(Group *group,
                                 QPoint p1, QPoint p2,
                                 QColor outline,
                                 int thickness) :
    m_group(group),
    m_p1(p1), m_p2(p2),
    m_outline(outline),
    m_thickness(thickness)
{

}

DrawLineCommand::~DrawLineCommand()
{

}

DrawLineCommand::DrawLineCommand(Line *l) :
    DrawLineCommand(l->getParentGroup(),
                    l->getP1(), l->getP2(),
                    l->getLineColor(),
                    l->getLineThickness())
{
    m_index = l->getIndex();
}

void DrawLineCommand::execute()
{
    Line *l = new Line();
    l->setP1(m_p1);
    l->setP2(m_p2);
    l->setLineColor(m_outline);
    l->setLineThickness(m_thickness);

    m_index = m_group->add(l);
    ActiveSelection::getInstance().deselectAll();
    l->setSelected(true);
}

void DrawLineCommand::undo()
{
    m_group->destroy(m_index);
    GlobalDrawProperties::getInstance().unlinkProperties();
}

