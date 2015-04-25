#pragma once

class QPainter;

class IDrawable
{
public:
    virtual void draw(QPainter *painter) = 0;
};


