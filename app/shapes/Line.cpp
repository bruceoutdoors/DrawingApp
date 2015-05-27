#include "Line.hpp"
#include <QPainter>
#include <cmath>
#include "GlobalDrawProperties.hpp"

Line::Line()
{
    m_p1 = QPoint(5, 5);
    m_p2 = QPoint(75, 75);

    GlobalDrawProperties *gp = &GlobalDrawProperties::getInstance();

    if (gp->isSetup()) {
        setLineThickness(gp->getThickness());
        setLineColor(gp->getLineColor());
    } else {
        setLineThickness(2);
    }
}

Line::~Line()
{

}

void Line::setLineColor(const QColor &val)
{
    m_lineColor = val;
}

QColor Line::getLineColor() const
{
    return m_lineColor;
}

void Line::setLineThickness(const int &val)
{
    m_lineThickness = val;
}

int Line::getLineThickness() const
{
    return m_lineThickness;
}

void Line::draw(QPainter *painter)
{
    QPen pen(getLineColor());
    pen.setWidth(getLineThickness());

    painter->setPen(pen);

    painter->drawLine(m_p1, m_p2);
}

QRect Line::getBoundary()
{
    int margin = getLineThickness() <= 4 ? 4 : getLineThickness()/2+2;

    int x = m_p1.x() < m_p2.x() ? m_p1.x() : m_p2.x();
    int y  = m_p1.y() < m_p2.y() ? m_p1.y() : m_p2.y();
    int w = std::abs(m_p1.x() - m_p2.x());
    int h = std::abs(m_p1.y() - m_p2.y());

    return QRect(x-margin, y-margin, w+margin*2, h+margin*2);;
}

bool Line::contains(int x, int y)
{
    float r = getLineThickness() <= 4 ? 4 : getLineThickness(); // impact margin

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

void Line::setPosition(const QPoint &pos)
{
    QPoint diff = pos - getPosition();
    m_p1 += diff;
    m_p2 += diff;
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



