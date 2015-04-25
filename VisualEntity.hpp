#pragma once

#include "ISelectable.hpp"
#include "IDrawable.hpp"

class QPainter;

class VisualEntity : public IDrawable
{
public:
    VisualEntity(QPainter *painter);
    virtual ~VisualEntity();

protected:
    QPainter *m_painter;
};

