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
    QRect b = QRect(m_p1, m_p2);
//    int l = getlineThickness()/2 + 2;
//    b += QMargins(l, l, l, l);
    return b;
}

bool Line::contains(int x, int y)
{
    float r = getlineThickness() <= 4 ? 4 : getlineThickness(); // impact margin

    if (!getBoundary().contains(x, y)) return false;

    // calculate whether line is clicked using circle-line intersection:
    float A, B, C, m, f, discriminant;

    float dx = m_p2.x() - m_p1.x();
    if (dx == 0) return true;

    // convert points m_p1 and m_p2 to the equation of the line y = mx + f
    m = float(m_p2.y() - m_p1.y()) / dx;
    f = m_p1.y() - m * m_p1.x();

    A = m*m + 1;
    B = 2 * (m*f - m*y - x);
    C = y*y - r*r + x*x - 2*f*y + f*f;

    discriminant = B*B - 4*A*C;

    return discriminant >= 0;
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



