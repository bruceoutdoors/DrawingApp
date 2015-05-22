#pragma once

#include "Command.hpp"
#include <QPoint>
#include <QColor>

class Circle;
class Group;

class DrawCircleCommand : public Command
{
public:
    DrawCircleCommand(Group *group, QPoint pos,
                      QColor fill, QColor outline,
                      int thickness, int radius);
    DrawCircleCommand(Circle *c);
    ~DrawCircleCommand();

    void execute() override;
    void undo()    override;

private:
    Group *m_group;
    Circle *m_circle;
    QPoint m_pos;
    QColor m_fill;
    QColor m_outline;
    int m_thickness;
    int m_radius;

};

