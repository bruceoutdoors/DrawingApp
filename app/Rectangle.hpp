#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle();
    virtual ~Rectangle();

    void draw(QPainter *painter) override;
    QRect getBoundary() override;
    bool contains(int x, int y) override;

private:
    QRect m_rect;
};

