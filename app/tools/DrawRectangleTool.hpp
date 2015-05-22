#pragma once

#include "Tool.hpp"
#include <QPoint>

class ActiveSelection;
class Rectangle;

class DrawRectangleTool : public Tool
{
public:
    DrawRectangleTool(Canvas *canvas);
    ~DrawRectangleTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    ActiveSelection *m_selection;
    Rectangle *m_rectangle;
    bool m_clickPressed;
    QPoint m_startPosition;
};
