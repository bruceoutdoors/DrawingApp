#pragma once

#include "Command.hpp"
#include <QPoint>
#include <QColor>

class Shape;
class Group;

class DrawShapeCommand : public Command
{
public:
    DrawShapeCommand(Group *group, QPoint pos,
                      QColor fill, QColor outline,
                      int thickness);
    DrawShapeCommand(Shape *s);
    ~DrawShapeCommand();

    void undo()    override;

protected:
    void shapeSet(Shape *s);

private:
    int m_index;
    Group *m_group;
    QPoint m_pos;
    QColor m_fill;
    QColor m_outline;
    int m_thickness;
};

