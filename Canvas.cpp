#include "Canvas.hpp"
#include "Circle.hpp"
#include <QPainter>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    Circle *circle = new Circle();
    QColor fillColor(255, 50, 50);
    circle->setFillColor(fillColor);

    QColor outlineColor(0, 150, 250);
    circle->setLineColor(outlineColor);

    circle->setlineThickness(5);
    circle->setRadius(15);
    circle->setPosition(QPoint(150, 50));

    Circle *circle2 = new Circle();

    circle2->setFillColor(QColor(100, 250, 50));
    circle2->setLineColor(QColor(200, 50, 250));

    circle2->setlineThickness(3);
    circle2->setRadius(35);
    circle2->setPosition(QPoint(50, 80));

    m_visuals.push_back(circle);
    m_visuals.push_back(circle2);
}

Canvas::~Canvas()
{
    for (VisualEntity *visual : m_visuals) {
        delete visual;
    }
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    for (VisualEntity *visual : m_visuals) {
        visual->draw(painter);
    }

    delete painter;
}

