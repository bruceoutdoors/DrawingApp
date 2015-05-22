#include "DrawLineCommand.hpp"
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
                    l->getlineThickness())
{
    m_line = l;
}

void DrawLineCommand::execute()
{
    m_line = new Line();
    m_line->setP1(m_p1);
    m_line->setP2(m_p2);
    m_line->setLineColor(m_outline);
    m_line->setlineThickness(m_thickness);

    m_group->add(m_line);
}

void DrawLineCommand::undo()
{
    m_line->selfDestruct();
}

