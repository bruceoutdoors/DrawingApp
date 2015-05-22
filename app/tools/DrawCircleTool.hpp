#pragma once

#include "Tool.hpp"

#include <QPoint>

class Selection;
class Circle;

class DrawCircleTool : public Tool
{
public:
    DrawCircleTool(Canvas *canvas);
    ~DrawCircleTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Selection *m_selection;
    Circle *m_circle;
    bool m_clickPressed;
    QPoint m_startPosition;
};
