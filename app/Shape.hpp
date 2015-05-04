#pragma once

#include "IFillable.hpp"
#include "ILine.hpp"
#include "VisualEntity.hpp"

class Shape : public VisualEntity, public IFillable, public ILine
{
public:
    Shape();
    virtual ~Shape();

    void setFillColor(QColor val) override;
    QColor getFillColor() override;

    void setLineColor(QColor val) override;
    QColor getLineColor() override;

    void setlineThickness(int val) override;
    int getlineThickness() override;

    void setPosition(QPoint pos);
    QPoint getPosition();

protected:
    QPoint m_position;
    QColor m_fillColor;
    QColor m_lineColor;
    int m_lineThickness;
};

