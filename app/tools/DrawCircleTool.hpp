#pragma once

#include "Tool.hpp"

#include <QPoint>

class ActiveSelection;
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
    ActiveSelection *m_selection;
    Circle *m_circle;
    bool m_clickPressed;
    QPoint m_startPosition;
};
