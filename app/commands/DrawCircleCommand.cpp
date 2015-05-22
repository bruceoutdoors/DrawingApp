#include "DrawCircleCommand.hpp"
#include "Circle.hpp"
#include "Group.hpp"

DrawCircleCommand::DrawCircleCommand(Group *group,
                                     QPoint pos,
                                     QColor fill, QColor outline,
                                     int thickness, int radius) :
    DrawShapeCommand(group, pos, fill, outline, thickness),
    m_radius(radius)
{
}

DrawCircleCommand::DrawCircleCommand(Circle *c) :
    DrawShapeCommand(c),
    m_radius(c->getRadius())
{
}

DrawCircleCommand::~DrawCircleCommand()
{

}

void DrawCircleCommand::execute()
{
    Circle *c = new Circle();
    c->setRadius(m_radius);

    shapeSet(c);
}
