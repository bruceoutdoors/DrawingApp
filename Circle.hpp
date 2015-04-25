#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(QPainter *painter);
    virtual ~Circle();

    void draw() override;
};

