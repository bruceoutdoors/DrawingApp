#pragma once
#include <QPushButton>
#include <functional>

class Canvas;

class PropertyColorButton : public QPushButton
{
public:
    PropertyColorButton(QWidget *parent,
                        Canvas *canvas,
                        std::function<QColor()> getter,
                        std::function<void(QColor)> setter);
    void setGetterSetter(std::function<QColor()> getter,
                         std::function<void(QColor)> setter);
    QColor getColor() const;
    ~PropertyColorButton();

private:
    QMetaObject::Connection m_connection;
    Canvas *m_canvas;
    QColor m_color;
};

