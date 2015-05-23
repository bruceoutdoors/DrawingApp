#pragma once

#include "Command.hpp"

#include <vector>
#include <QColor>

class Selection;

class ChangeLineThicknessCommand : public Command
{
public:
    ChangeLineThicknessCommand();
    ~ChangeLineThicknessCommand();

    void setThickness(int thickness);

    void execute() override;
    void undo() override;

private:
    Selection *m_currentSelection;
    std::vector<int> m_savedThickness;
    int m_thickness;
};

