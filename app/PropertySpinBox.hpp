#pragma once

#include <QSpinBox>
#include <functional>

class Canvas;

class PropertySpinBox : public QSpinBox
{
public:
    PropertySpinBox(QWidget *parent,
                    Canvas *canvas, int startVal);
    PropertySpinBox(QWidget *parent,
                    Canvas *canvas,
                    std::function<int()> getter,
                    std::function<void(int)> setter);
    void setGetterSetter(std::function<int()> getter,
                         std::function<void(int)> setter);
    void unlink();
    ~PropertySpinBox();

private:
    Canvas *m_canvas;
    QMetaObject::Connection m_connection;
};
