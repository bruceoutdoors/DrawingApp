#include "DrawDialogFactory.hpp"
#include "DrawDialog.hpp"
#include "GlobalDrawProperties.hpp"

#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"

DrawDialogFactory::DrawDialogFactory()
{

}

DrawDialogFactory::~DrawDialogFactory()
{

}

DrawDialog *DrawDialogFactory::CreateShapeDrawDialog(MainWindow *parent, Shape *shape)
{
    DrawDialog *d = new DrawDialog(parent);

    GlobalDrawProperties::getInstance().setVEProperties(shape);

    d->appendSpinBox("Position X",
                  [=]() { return shape->getPosition().x(); },
                  [=](int x) { shape->setPosition(QPoint(x, shape->getPosition().y())); });

    d->appendSpinBox("Position Y",
                  [=]() { return shape->getPosition().y(); },
                  [=](int y) { shape->setPosition(QPoint(shape->getPosition().x(), y)); });

    d->appendColorPicker("Fill Color",
                      std::bind(&Shape::getFillColor, shape),
                      std::bind(&Shape::setFillColor, shape, std::placeholders::_1));

    d->appendColorPicker("Outline Color",
                      std::bind(&Shape::getLineColor, shape),
                      std::bind(&Shape::setLineColor, shape, std::placeholders::_1));

    d->appendSpinBox("Outline Thickness",
                  std::bind(&Shape::getLineThickness, shape),
                  std::bind(&Shape::setLineThickness, shape, std::placeholders::_1));

    return d;
}

DrawDialog *DrawDialogFactory::CreateDrawDialog(MainWindow *parent, Circle *c)
{
    DrawDialog *d = CreateShapeDrawDialog(parent, c);

    d->appendSpinBox("Radius",
                     [=]() { return c->getRadius(); },
                     [=](int r) { c->setRadius(r); });

    return d;
}

DrawDialog *DrawDialogFactory::CreateDrawDialog(MainWindow *parent, Rectangle *r)
{
    DrawDialog *d = CreateShapeDrawDialog(parent, r);

    d->appendSpinBox("Width",
                     [=]() { return r->getWidth(); },
                     [=](int w) { r->setWidth(w); });

    d->appendSpinBox("Height",
                     [=]() { return r->getHeight(); },
                     [=](int h) { r->setHeight(h); });

    return d;
}

DrawDialog *DrawDialogFactory::CreateDrawDialog(MainWindow *parent, Line *l)
{
    DrawDialog *d = new DrawDialog(parent);

    GlobalDrawProperties::getInstance().setVEProperties(l);

    d->appendSpinBox("P1.x",
                     [=]() { return l->getP1().x(); },
                     [=](int x) { l->setP1(QPoint(x, l->getP1().y())); });

    d->appendSpinBox("P1.y",
                     [=]() { return l->getP1().y(); },
                     [=](int y) { l->setP1(QPoint(l->getP1().x(), y)); });

    d->appendSpinBox("P2.x",
                     [=]() { return l->getP2().x(); },
                     [=](int x) { l->setP2(QPoint(x, l->getP2().y())); });

    d->appendSpinBox("P2.y",
                     [=]() { return l->getP2().y(); },
                     [=](int y) { l->setP2(QPoint(l->getP2().x(), y)); });

    d->appendColorPicker("Line Color",
                         [=]() { return l->getLineColor(); },
                         [=](QColor c) { l->setLineColor(c); });

    d->appendSpinBox("Line Thickness",
                     [=]() { return l->getLineThickness(); },
                     [=](int t) { l->setLineThickness(t); });

    return d;
}

