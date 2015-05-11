#pragma once

#include "Tool.hpp"

class Group;
class Selection;

class SelectionTool : public Tool
{
public:
    SelectionTool(Group *mainGroup);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;

private:
    Group *m_mainGroup;
    Selection *m_selection;
};

