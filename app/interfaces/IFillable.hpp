#pragma once

#include <QColor>

class IFillable
{
public:
    virtual void setFillColor(const QColor &val) = 0;
    virtual QColor getFillColor() const = 0;

    virtual ~IFillable() {}
};


