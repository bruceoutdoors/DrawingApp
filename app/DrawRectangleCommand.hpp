#pragma once

#include "Command.hpp"

#include <QPoint>
#include <QColor>

class Group;
class Rectangle;

class DrawRectangleCommand : public Command
{
public:
    DrawRectangleCommand(Group *group, QPoint pos,
                         QColor fill, QColor outline,
                         int thickness, int width, int height);
    DrawRectangleCommand(Rectangle *r);
    ~DrawRectangleCommand();

    void execute() override;
    void undo()    override;

private:
    Group *m_group;
    Rectangle *m_rect;
    int m_width;
    int m_height;
    int m_thickness;
    QPoint m_pos;
    QColor m_fill;
    QColor m_outline;
};

