#include "Shape.hpp"

Shape::Shape()
{
    setFillColor(QColor(50, 150, 0));
    setLineColor(QColor(0, 0, 0));
    setLineThickness(2);
}

Shape::~Shape()
{

}

void Shape::setPosition(const QPoint &pos)
{
    m_position = pos;
}

QPoint Shape::getPosition()
{
    return m_position;
}

void Shape::setFillColor(const QColor &val)
{
    m_fillColor = val;
}

QColor Shape::getFillColor() const
{
    return m_fillColor;
}

void Shape::setLineColor(const QColor &val)
{
    m_lineColor = val;
}

QColor Shape::getLineColor() const
{
    return m_lineColor;
}

void Shape::setLineThickness(const int &val)
{
    m_lineThickness = val;
}

int Shape::getLineThickness() const
{
    return m_lineThickness;
}

