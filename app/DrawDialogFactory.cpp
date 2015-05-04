#include "DrawDialogFactory.hpp"
#include "DrawDialog.hpp"
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

DrawDialogFactory::DrawDialogFactory()
{

}

DrawDialogFactory::~DrawDialogFactory()
{

}

DrawDialog *DrawDialogFactory::CreateShapeDrawDialog(MainWindow *parent, Shape *shape)
{
    DrawDialog *d = new DrawDialog(parent);

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
                  std::bind(&Shape::getlineThickness, shape),
                  std::bind(&Shape::setlineThickness, shape, std::placeholders::_1));

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

