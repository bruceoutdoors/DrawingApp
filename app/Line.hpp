#pragma once

#include "ILine.hpp"
#include "VisualEntity.hpp"
#include "ITransformable.hpp"

class Line : public VisualEntity, public ILine, public ITransformable
{
public:
    Line();
    ~Line();
    void setLineColor(QColor val) override;
    QColor getLineColor() override;

    void setlineThickness(int val) override;
    int getlineThickness() override;

    void draw(QPainter *painter) override;
    QRect getBoundary() override;
    bool contains(int x, int y) override;

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

    QPoint getP1() const;
    void setP1(const QPoint &value);

    QPoint getP2() const;
    void setP2(const QPoint &value);

protected:
    QColor m_lineColor;
    QPoint m_p1;
    QPoint m_p2;
    int m_lineThickness;
};
