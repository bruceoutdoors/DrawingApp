#include "Canvas.hpp"
#include "Circle.hpp"
#include <QPainter>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{

}

Canvas::~Canvas()
{
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    Circle *circle = new Circle(painter);

    QColor fillColor(255, 0, 0);
    circle->setFillColor(fillColor);

    QColor outlineColor(0, 255, 0);
    circle->setLineColor(outlineColor);

    circle->setlineThickness(10);

    circle->draw();

    delete circle;
    delete painter;
}

