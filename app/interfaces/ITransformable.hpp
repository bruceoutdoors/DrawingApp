#pragma once

#include <QPointF>
#include <QPoint>

class ITransformable
{
public:
//    virtual void setRotate(int deg) = 0;
//    virtual int getRotate() = 0;

//    virtual void setScale(QPointF scale) = 0;
//    virtual QPointF getScale() = 0;

    virtual void setPosition(QPoint pos) = 0;
    virtual QPoint getPosition() = 0;

    virtual ~ITransformable() {}
};

