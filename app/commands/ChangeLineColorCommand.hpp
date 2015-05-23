#pragma once

#include "Command.hpp"

#include <vector>
#include <QColor>

class Selection;

class ChangeLineColorCommand : public Command
{
public:
    ChangeLineColorCommand();
    ~ChangeLineColorCommand();

    void setColor(QColor color);

    void execute() override;
    void undo() override;

private:
    Selection *m_currentSelection;
    std::vector<QColor> m_savedColors;
    QColor m_color;
};

