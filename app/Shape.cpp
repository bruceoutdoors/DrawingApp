#include "Shape.hpp"
#include "GlobalDrawProperties.hpp"

Shape::Shape()
{
    GlobalDrawProperties *gp = &GlobalDrawProperties::getInstance();

    if (gp->isSetup()) {
        setlineThickness(gp->getThickness());
        setLineColor(gp->getLineColor());
        setFillColor(gp->getFillColor());
    } else {
        setFillColor(QColor(50, 150, 0));
        setLineColor(QColor(0, 0, 0));
        setlineThickness(2);
    }
}

Shape::~Shape()
{

}

void Shape::setPosition(QPoint pos)
{
    m_position = pos;
}

QPoint Shape::getPosition()
{
    return m_position;
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

