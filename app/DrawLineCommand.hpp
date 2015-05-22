#pragma once

#include "Command.hpp"
#include <QPoint>
#include <QColor>

class Line;
class Group;

class DrawLineCommand : public Command
{
public:
    DrawLineCommand(Group *group,
                    QPoint p1, QPoint p2, QColor outline,
                    int thickness);
    DrawLineCommand(Line *l);
    ~DrawLineCommand();

    void execute() override;
    void undo()    override;

private:
    Group *m_group;
    Line *m_line;
    QPoint m_p1;
    QPoint m_p2;
    QColor m_fill;
    QColor m_outline;
    int m_thickness;
};

