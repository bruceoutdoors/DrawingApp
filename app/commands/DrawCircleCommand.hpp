#pragma once

#include "DrawShapeCommand.hpp"
#include <QPoint>
#include <QColor>

class Circle;
class Group;

class DrawCircleCommand : public DrawShapeCommand
{
public:
    DrawCircleCommand(Group *group, QPoint pos,
                      QColor fill, QColor outline,
                      int thickness, int radius);
    DrawCircleCommand(Circle *c);
    ~DrawCircleCommand();

    void execute() override;

private:
    int m_radius;

};

