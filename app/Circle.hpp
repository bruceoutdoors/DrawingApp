#pragma once

#include "Shape.hpp"

class Circle : public Shape, public ISelectable
{
public:
    Circle();
    virtual ~Circle();

    void draw(QPainter *painter) override;

    int getRadius() const;
    void setRadius(int value);

    bool contains(int x, int y) override;
    void setSelected(bool val) override;
    bool isSelected() override;

private:
    int m_radius;
};

