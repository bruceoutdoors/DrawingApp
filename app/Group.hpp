#pragma once

#include "AbstractGroup.hpp"
#include "VisualEntity.hpp"

class Group : public AbstractGroup, public VisualEntity
{
public:
    Group();
    ~Group();

    int add(VisualEntity *val) override;

    VisualEntity* getClicked(int x, int y);

    void draw(QPainter *painter) override;
    bool contains(int x, int y) override;

    // as visual entity inherits IDrawable and ITransformable, we need to
    // reimplement it again (just reuse implementation from AbstractGroup)
    QRect getBoundary() override          { return AbstractGroup::getBoundary(); }
    void setPosition(QPoint pos) override { AbstractGroup::setPosition(pos);     }
    QPoint getPosition() override         { return AbstractGroup::getPosition(); }
};
