#pragma once

#include "Tool.hpp"

class Group;
class Selection;
class GlobalDrawProperties;

class SelectionTool : public Tool
{
public:
    SelectionTool(Canvas *canvas);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;

private:
    Selection *m_selection;
    GlobalDrawProperties *m_gp;
};

