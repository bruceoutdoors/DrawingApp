#include "PropertySpinBox.hpp"
#include "MainWindow.hpp"
#include "Canvas.hpp"

PropertySpinBox::PropertySpinBox(QWidget *parent, Canvas *canvas,
                                 std::function<int()> getter,
                                 std::function<void(int)> setter) :
    QSpinBox(parent),
    m_canvas(canvas)
{
    setMaximum(999);
    setGetterSetter(getter, setter);
}

void PropertySpinBox::setGetterSetter(std::function<int()> getter,
                                      std::function<void(int)> setter)
{
    QObject::disconnect(m_connection);

    setValue(getter());

    m_connection =
            connect(this, static_cast<void (QSpinBox::*) (int)>(&QSpinBox::valueChanged),
               [ = ](int v) {
                   setter(v);
                   m_canvas->repaint();
               });
}

PropertySpinBox::~PropertySpinBox()
{

}

