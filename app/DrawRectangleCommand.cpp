#include "DrawRectangleCommand.hpp"
#include "Rectangle.hpp"
#include "Group.hpp"

DrawRectangleCommand::DrawRectangleCommand(Group *group,
                                           QPoint pos,
                                           QColor fill, QColor outline,
                                           int thickness, int width, int height) :
    m_group(group),
    m_pos(pos),
    m_fill(fill), m_outline(outline),
    m_thickness(thickness), m_width(width), m_height(height)
{

}

DrawRectangleCommand::DrawRectangleCommand(Rectangle *r) :
    DrawRectangleCommand(r->getParentGroup(),
                         r->getPosition(),
                         r->getFillColor(),
                         r->getLineColor(),
                         r->getlineThickness(),
                         r->getWidth(),
                         r->getHeight())
{
    m_rect = r;
}

DrawRectangleCommand::~DrawRectangleCommand()
{
}

void DrawRectangleCommand::execute()
{
    m_rect = new Rectangle();
    m_rect->setPosition(m_pos);
    m_rect->setFillColor(m_fill);
    m_rect->setLineColor(m_outline);
    m_rect->setlineThickness(m_thickness);
    m_rect->setWidth(m_width);
    m_rect->setHeight(m_height);

    m_group->add(m_rect);
}

void DrawRectangleCommand::undo()
{
    m_rect->selfDestruct();
}

