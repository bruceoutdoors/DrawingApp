#pragma once

class QEvent;
class QMouseEvent;
class QKeyEvent;

class Tool
{
public:
    Tool();
    ~Tool();

    bool handleEvent(QEvent *event);

protected:
    virtual void mousePress(QMouseEvent *event) {}
    virtual void keyPress(QKeyEvent *event) {}
};

