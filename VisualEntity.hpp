#pragma once

#include "ISelectable.hpp"
#include "IDrawable.hpp"
#include "ITransformable.hpp"

class QPainter;

class VisualEntity : public IDrawable, public ITransformable
{
public:
    VisualEntity(QPainter *painter);
    virtual ~VisualEntity();

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

protected:
    QPainter *m_painter;
    QPoint m_position;
};

