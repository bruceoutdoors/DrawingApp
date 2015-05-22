#pragma once

#include "DrawShapeCommand.hpp"

#include <QPoint>
#include <QColor>

class Group;
class Rectangle;

class DrawRectangleCommand : public DrawShapeCommand
{
public:
    DrawRectangleCommand(Group *group, QPoint pos,
                         QColor fill, QColor outline,
                         int thickness, int width, int height);
    DrawRectangleCommand(Rectangle *r);
    ~DrawRectangleCommand();

    void execute() override;

private:
    int m_width;
    int m_height;
};
