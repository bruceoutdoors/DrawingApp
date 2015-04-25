#include "Shape.hpp"

Shape::Shape(QPainter *painter) : VisualEntity(painter)
{

}

Shape::~Shape()
{

}

void Shape::setFillColor(QColor val)
{
    m_fillColor = val;
}

QColor Shape::getFillColor()
{
    return m_fillColor;
}

void Shape::setLineColor(QColor val)
{
    m_lineColor = val;
}

QColor Shape::getLineColor()
{
    return m_lineColor;
}

void Shape::setlineThickness(int val)
{
    m_lineThickness = val;
}

int Shape::getlineThickness()
{
    return m_lineThickness;
}

