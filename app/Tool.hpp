#pragma once

class QEvent;
class QMouseEvent;
class QKeyEvent;
class Canvas;

class Tool
{
public:
    Tool(Canvas *canvas);
    ~Tool();

    bool handleEvent(QEvent *event);

protected:
    virtual void mousePress(QMouseEvent *event) {}
    virtual void keyPress(QKeyEvent *event) {}

    Canvas *m_canvas;
};

