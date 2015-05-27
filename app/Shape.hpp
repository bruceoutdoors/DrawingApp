#pragma once

#include "IFillable.hpp"
#include "ILine.hpp"
#include "VisualEntity.hpp"

class Shape : public VisualEntity, public IFillable, public ILine
{
public:
    Shape();
    virtual ~Shape();

    void setFillColor(const QColor &val) override;
    QColor getFillColor() const override;

    void setLineColor(const QColor &val) override;
    QColor getLineColor() const override;

    void setLineThickness(const int &val) override;
    int getLineThickness() const override;

    void setPosition(const QPoint &pos) override;
    QPoint getPosition();

protected:
    QPoint m_position;
    QColor m_fillColor;
    QColor m_lineColor;
    int m_lineThickness;
};

