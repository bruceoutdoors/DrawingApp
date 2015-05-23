#pragma once

#include "Tool.hpp"
#include <QPoint>

class Group;
class ActiveSelection;
class GlobalDrawProperties;
class MoveSelectionCommand;
class VisualEntity;

class SelectionTool : public Tool
{
public:
    SelectionTool(Canvas *canvas);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent*) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    ActiveSelection *m_selection;
    MoveSelectionCommand *m_movComm;
    VisualEntity *m_clicked;
    bool m_isMousePressed;
    bool m_hasMoved;
    QPoint m_mousePressedLoc;
    QPoint m_p;
    GlobalDrawProperties *m_gp;
};

