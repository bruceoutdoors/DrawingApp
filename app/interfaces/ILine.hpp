#pragma once

#include <QColor>

class ILine
{
public:
    virtual void setLineColor(const QColor &val) = 0;
    virtual QColor getLineColor() const = 0;

    virtual void setLineThickness(const int &val) = 0;
    virtual int getLineThickness() const = 0;

    virtual ~ILine() {}
};


