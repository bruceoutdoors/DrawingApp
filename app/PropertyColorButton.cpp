#include "PropertyColorButton.hpp"
#include "Canvas.hpp"

#include <QColorDialog>

PropertyColorButton::PropertyColorButton(QWidget *parent, Canvas *canvas) :
    QPushButton(parent),
    m_canvas(canvas)
{
    m_colorDialog = new QColorDialog();
}

PropertyColorButton::PropertyColorButton(QWidget *parent,
                                         Canvas *canvas, QColor startColor) :
    PropertyColorButton(parent, canvas)
{
    m_color = startColor;
    unlink();
}

PropertyColorButton::PropertyColorButton(QWidget *parent, Canvas *canvas,
                                         std::function<QColor()> getter,
                                         std::function<void(QColor)> setter) :
    PropertyColorButton(parent, canvas)
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
                m_colorDialog->setCurrentColor(getter());
                QColor before = getter();

                auto dlgLink =
                    connect(m_colorDialog, &QColorDialog::currentColorChanged,
                        [=](QColor color) {
                            if (color.isValid()) {
                                setColor(color);
                                setter(color);
                                m_canvas->repaint();
                            }
                        });

                if (m_colorDialog->exec() == 0) {
                    setColor(before);
                    m_canvas->repaint();
                }

                QObject::disconnect(dlgLink);
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

void PropertyColorButton::unlink()
{
    setGetterSetter([=]() { return m_color; },
                    [=](QColor c) { m_color = c; });
}

QColorDialog *PropertyColorButton::getColorDialog() const
{
    return m_colorDialog;
}

PropertyColorButton::~PropertyColorButton()
{
    delete m_colorDialog;
}



