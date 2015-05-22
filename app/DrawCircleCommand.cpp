#include "DrawCircleCommand.hpp"
#include "Circle.hpp"
#include "Group.hpp"

DrawCircleCommand::DrawCircleCommand(Group *group,
                                     QPoint pos,
                                     QColor fill, QColor outline,
                                     int thickness, int radius) :
    m_group(group),
    m_pos(pos),
    m_fill(fill), m_outline(outline),
    m_thickness(thickness), m_radius(radius)
{

}

DrawCircleCommand::DrawCircleCommand(Circle *c) :
    DrawCircleCommand(c->getParentGroup(),
                      c->getPosition(),
                      c->getFillColor(),
                      c->getLineColor(),
                      c->getlineThickness(),
                      c->getRadius())
{
    m_circle = c;
}

DrawCircleCommand::~DrawCircleCommand()
{

}

void DrawCircleCommand::execute()
{
    m_circle = new Circle();
    m_circle->setPosition(m_pos);
    m_circle->setFillColor(m_fill);
    m_circle->setLineColor(m_outline);
    m_circle->setRadius(m_radius);
    m_circle->setlineThickness(m_thickness);

    m_group->add(m_circle);
}

void DrawCircleCommand::undo()
{
    m_circle->selfDestruct();
}

