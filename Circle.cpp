#include "Circle.hpp"
#include <QPainter>

Circle::Circle(QPainter *painter) :
    Shape(painter),
    m_radius(50)
{
    setPosition(QPoint(50,50));
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

    m_painter->drawEllipse(getPosition(), m_radius, m_radius);
}

int Circle::getRadius() const
{
    return m_radius;
}

void Circle::setRadius(int value)
{
    m_radius = value;
}


