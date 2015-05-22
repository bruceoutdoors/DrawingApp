#pragma once

#include "Tool.hpp"
#include <QPoint>

class ActiveSelection;
class Line;

class DrawLineTool : public Tool
{
public:
    DrawLineTool(Canvas *canvas);
    ~DrawLineTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    ActiveSelection *m_selection;
    Line *m_line;
    bool m_clickPressed;
    QPoint m_startPosition;
};
