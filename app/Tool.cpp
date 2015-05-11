#include "Tool.hpp"

#include <QEvent>
#include <QWidget>

Tool::Tool()
{

}

Tool::~Tool()
{

}

bool Tool::handleEvent(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = reinterpret_cast<QKeyEvent *>(event);
        keyPress(ke);
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        mousePress(me);
        return true;
    }

    return true;
}

