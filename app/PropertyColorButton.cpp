#include "PropertyColorButton.hpp"
#include "Canvas.hpp"

#include <QColorDialog>

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
    m_color = getter();

    setText(getter().name());
    setStyleSheet(QString("background-color: %1")
                               .arg(getter().name()));

    setPalette(QPalette(getter()));

    m_connection = connect(this, &QPushButton::clicked,
            [=]() {
                QColorDialog d(getter());

                connect(&d, &QColorDialog::currentColorChanged,
                        [=](QColor color) {
                    if (color.isValid()) {
                        m_color = color;
                        setter(color);
                        setText(color.name());
                        setStyleSheet(QString("background-color: %1")
                                                   .arg(color.name()));
                        setPalette(QPalette(color));
                        m_canvas->repaint();
                    }
                });

                d.exec();
            }
    );
}

QColor PropertyColorButton::getColor() const
{
    return m_color;
}

PropertyColorButton::~PropertyColorButton()
{

}

