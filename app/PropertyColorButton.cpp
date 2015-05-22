#include "PropertyColorButton.hpp"
#include "Canvas.hpp"

#include <QColorDialog>

PropertyColorButton::PropertyColorButton(QWidget *parent,
                                         Canvas *canvas, QColor startColor) :
    QPushButton(parent),
    m_canvas(canvas),
    m_color(startColor)
{
    setGetterSetter([=]() { return m_color; },
                    [=](QColor c) { m_color = c; });
}

PropertyColorButton::PropertyColorButton(QWidget *parent, Canvas *canvas,
                                         std::function<QColor()> getter,
                                         std::function<void(QColor)> setter) :
    QPushButton(parent),
    m_canvas(canvas)
{
    setGetterSetter(getter, setter);
}

void PropertyColorButton::setGetterSetter(std::function<QColor()> getter,
                                          std::function<void(QColor)> setter)
{
    QObject::disconnect(m_connection);

    setColor(getter());

    m_connection = connect(this, &QPushButton::clicked,
            [=]() {
                QColor before = getter();
                QColorDialog d(getter());

                connect(&d, &QColorDialog::currentColorChanged,
                        [=](QColor color) {
                    if (color.isValid()) {
                        setColor(getter());
                        setter(color);
                        m_canvas->repaint();
                    }
                });

                if (d.exec() == 0) {
                    setColor(before);
                    setter(before);
                    m_canvas->repaint();
                }
            }
    );
}

void PropertyColorButton::setColor(QColor color)
{
    m_color = color;
    setText(color.name());
    setStyleSheet(QString("background-color: %1")
                               .arg(color.name()));
    setPalette(QPalette(color));
}

QColor PropertyColorButton::getColor() const
{
    return m_color;
}

PropertyColorButton::~PropertyColorButton()
{

}

