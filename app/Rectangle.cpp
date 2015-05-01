#include "Rectangle.hpp"
#include <QPainter>

Rectangle::Rectangle()
{
    m_rect = QRect(10, 10, 100, 60);
}

Rectangle::~Rectangle()
{

}

void Rectangle::draw(QPainter *painter)
{
    QBrush brush(getFillColor());
    QPen pen(getLineColor());
    pen.setWidth(getlineThickness());

    painter->setBrush(brush);
    painter->setPen(pen);

    painter->drawRect(m_rect);
}

QRect Rectangle::getBoundary()
{
    int margin = 4;
    return QRect(m_rect.x() - margin, m_rect.y() - margin,
                 m_rect.width()  + margin*2 + 1,
                 m_rect.height() + margin*2 + 1);
}

bool Rectangle::contains(int x, int y)
{
    return m_rect.contains(x, y);
}

