#pragma once

#include "Command.hpp"
#include <QPoint>
#include <QColor>

class VisualEntity;
class Group;

class DrawCommand : public Command
{
public:
    DrawCommand(VisualEntity *c);
    virtual ~DrawCommand();

    void execute() override;
    void undo()    override;

private:
    VisualEntity *m_ve;
    Group *m_parent;
};

