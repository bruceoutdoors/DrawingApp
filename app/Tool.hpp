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
    virtual void mousePress(QMouseEvent*) {}
    virtual void mouseMove(QMouseEvent*) {}
    virtual void mouseRelease(QMouseEvent*) {}
    virtual void keyPress(QKeyEvent*) {}

    Canvas *m_canvas;
};

