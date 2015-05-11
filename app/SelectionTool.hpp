#pragma once

#include "Tool.hpp"

class Group;
class Selection;

class SelectionTool : public Tool
{
public:
    SelectionTool(Canvas *canvas);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;

private:
    Selection *m_selection;
};

