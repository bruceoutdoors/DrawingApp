#include "PropertySpinBox.hpp"
#include "MainWindow.hpp"
#include "Canvas.hpp"

PropertySpinBox::PropertySpinBox(QWidget *parent, Canvas *canvas,
                                 std::function<int()> getter,
                                 std::function<void(int)> setter) :
    QSpinBox(parent),
    m_canvas(canvas)
{
    setGetterSetter(getter, setter);
}

void PropertySpinBox::setGetterSetter(std::function<int()> getter,
                                      std::function<void(int)> setter)
{
    QObject::disconnect(m_connection);

    m_connection =
            connect(this, static_cast<void (QSpinBox::*) (int)>(&QSpinBox::valueChanged),
               [ = ](int v) {
                   setter(v);
                   m_canvas->repaint();
               });

    setMaximum(999);

    setValue(getter());
}

PropertySpinBox::~PropertySpinBox()
{

}

