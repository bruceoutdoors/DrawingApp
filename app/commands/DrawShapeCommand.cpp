#include "DrawShapeCommand.hpp"
#include "GlobalDrawProperties.hpp"
#include "ActiveSelection.hpp"
#include "Shape.hpp"
#include "Group.hpp"

DrawShapeCommand::DrawShapeCommand(Group *group,
                                   QPoint pos,
                                   QColor fill, QColor outline,
                                   int thickness) :
    m_group(group),
    m_pos(pos),
    m_fill(fill), m_outline(outline),
    m_thickness(thickness)
{
}

DrawShapeCommand::DrawShapeCommand(Shape *s) :
    DrawShapeCommand(s->getParentGroup(),
                     s->getPosition(),
                     s->getFillColor(),
                     s->getLineColor(),
                     s->getLineThickness())
{
    m_index = s->getIndex();
}

DrawShapeCommand::~DrawShapeCommand()
{

}

void DrawShapeCommand::undo()
{
    m_group->destroy(m_index);
    GlobalDrawProperties::getInstance().unlinkProperties();
}

void DrawShapeCommand::shapeSet(Shape *s)
{
    s->setPosition(m_pos);
    s->setFillColor(m_fill);
    s->setLineColor(m_outline);
    s->setLineThickness(m_thickness);

    m_index = m_group->add(s);
    ActiveSelection::getInstance().deselectAll();
    s->setSelected(true);
}


