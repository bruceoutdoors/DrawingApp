#include "Circle.hpp"
#include <QPainter>

Circle::Circle() :
    m_radius(50)
{
    setPosition(QPoint(50,50));
}

Circle::~Circle()
{

}

void Circle::draw(QPainter *painter)
{
    QBrush brush(getFillColor());
    QPen pen(getLineColor());
    pen.setWidth(getlineThickness());

    painter->setBrush(brush);
    painter->setPen(pen);

    painter->drawEllipse(getPosition(), m_radius, m_radius);
}

int Circle::getRadius() const
{
    return m_radius;
}

void Circle::setRadius(int value)
{
    m_radius = value;
}

bool Circle::contains(int x, int y)
{
    return true;
}

void Circle::setSelected(bool val)
{

}

bool Circle::isSelected()
{
    return true;
}


