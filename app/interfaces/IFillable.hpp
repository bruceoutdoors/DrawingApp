#pragma once

#include <QColor>

class IFillable
{
public:
    virtual void setFillColor(QColor val) = 0;
    virtual QColor getFillColor() = 0;

    virtual ~IFillable() {}
};


