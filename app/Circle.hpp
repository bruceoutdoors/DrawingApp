#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle();
    virtual ~Circle();

    void draw(QPainter *painter) override;
    QRect getBoundary() override;

    int getRadius() const;
    void setRadius(int value);

    bool contains(int x, int y) override;

private:
    int m_radius;
};

