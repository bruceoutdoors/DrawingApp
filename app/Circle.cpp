#include "Circle.hpp"
#include <QPainter>
#include <QDebug>

Circle::Circle() :
    m_radius(50)
{
    setPosition(QPoint(50,50));

    setFillColor(QColor(50, 150, 0));
    setLineColor(QColor(0, 0, 0));

    setlineThickness(3);
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

QRect Circle::getBoundary()
{
    int rad = m_radius + m_lineThickness;

    int x = m_position.x() - rad;
    int y = m_position.y() - rad;
    int w = rad * 2;
    int h = w;

    return QRect(x, y, w, h);
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
    int relX = x - m_position.x();
    int relY = y - m_position.y();
    int distanceFromOrigin = (relX * relX) + (relY * relY);

//    qDebug() << "distance: " << distanceFromOrigin;

    // not quite sure why the offset is needed, but it clicks better...
    int rad = m_radius + m_lineThickness - 3;

//    qDebug() << "radius: " << rad*rad;

    return distanceFromOrigin <= (rad * rad);
}


