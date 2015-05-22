#pragma once

#include <QRect>

class QPainter;

class IDrawable
{
public:
    virtual void draw(QPainter *painter) = 0;
    virtual QRect getBoundary() = 0;
};


