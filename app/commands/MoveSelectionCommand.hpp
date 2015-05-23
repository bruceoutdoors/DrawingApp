#pragma once

#include "Command.hpp"
#include <vector>
#include <QPoint>

class Selection;

class MoveSelectionCommand : public Command
{
public:
    MoveSelectionCommand(QPoint start);
    virtual ~MoveSelectionCommand();

    void setPosition(QPoint target);

    void execute() override;
    void undo()    override;

private:
    QPoint m_start;
    QPoint m_target;
    Selection *m_sel;
    std::vector<QPoint> m_VEPos;
};

