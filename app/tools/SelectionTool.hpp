#pragma once

#include "Tool.hpp"

class Group;
class ActiveSelection;
class GlobalDrawProperties;

class SelectionTool : public Tool
{
public:
    SelectionTool(Canvas *canvas);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;

private:
    ActiveSelection *m_selection;
    GlobalDrawProperties *m_gp;
};

