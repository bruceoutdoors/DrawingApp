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

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

private:
    int m_width;
    int m_height;
};

