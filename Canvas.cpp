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

    QColor fillColor(255, 50, 50);
    circle->setFillColor(fillColor);

    QColor outlineColor(0, 150, 250);
    circle->setLineColor(outlineColor);

    circle->setlineThickness(5);
    circle->setRadius(15);
    circle->setPosition(QPoint(150, 50));

    circle->draw();

    delete circle;
    delete painter;
}

