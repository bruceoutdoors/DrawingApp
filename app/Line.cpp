#include "Line.hpp"
#include <QPainter>

Line::Line()
{
    m_p1 = QPoint(5, 5);
    m_p2 = QPoint(75, 75);
    setlineThickness(2);
}

Line::~Line()
{

}

void Line::setLineColor(QColor val)
{
    m_lineColor = val;
}

QColor Line::getLineColor()
{
    return m_lineColor;
}

void Line::setlineThickness(int val)
{
    m_lineThickness = val;
}

int Line::getlineThickness()
{
    return m_lineThickness;
}

void Line::draw(QPainter *painter)
{
    QPen pen(getLineColor());
    pen.setWidth(getlineThickness());

    painter->setPen(pen);

    painter->drawLine(m_p1, m_p2);
}

QRect Line::getBoundary()
{
    return QRect();
}

bool Line::contains(int x, int y)
{
    return false;
}

void Line::setPosition(QPoint pos)
{
    // TODO: implement this...
}

QPoint Line::getPosition()
{
    return QPoint((m_p1.x() + m_p2.x())/2,
                  (m_p1.y() + m_p2.y())/2);
}
QPoint Line::getP1() const
{
    return m_p1;
}

void Line::setP1(const QPoint &value)
{
    m_p1 = value;
}
QPoint Line::getP2() const
{
    return m_p2;
}

void Line::setP2(const QPoint &value)
{
    m_p2 = value;
}



