#include "DrawRectangleCommand.hpp"
#include "Rectangle.hpp"
#include "Group.hpp"

DrawRectangleCommand::DrawRectangleCommand(Group *group,
                                           QPoint pos,
                                           QColor fill, QColor outline,
                                           int thickness, int width, int height) :
    DrawShapeCommand(group, pos, fill, outline, thickness),
    m_width(width), m_height(height)
{

}

DrawRectangleCommand::DrawRectangleCommand(Rectangle *r) :
    DrawShapeCommand(r),
    m_width(r->getWidth()), m_height(r->getHeight())
{
}

DrawRectangleCommand::~DrawRectangleCommand()
{
}

void DrawRectangleCommand::execute()
{
    Rectangle *rect = new Rectangle();
    rect->setWidth(m_width);
    rect->setHeight(m_height);

    shapeSet(rect);

}
