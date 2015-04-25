#include "Circle.hpp"
#include <QPainter>

Circle::Circle(QPainter *painter) :
    Shape(painter)
{

}

Circle::~Circle()
{

}

void Circle::draw()
{
    QBrush brush(getFillColor());
    QPen pen(getLineColor());
    pen.setWidth(getlineThickness());

    m_painter->setBrush(brush);
    m_painter->setPen(pen);

    m_painter->drawEllipse(150,20, 100,100);
}

