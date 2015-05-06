#pragma once

#include "AbstractGroup.h"
#include "VisualEntity.hpp"

#include <vector>

class Group : public AbstractGroup, public VisualEntity
{
public:
    Group();
    ~Group();

    int add(VisualEntity *val) override;

    VisualEntity* getClicked(int x, int y);

    void draw(QPainter *painter) override;
    bool contains(int x, int y) override;

    // as visual entity inherits IDrawable, we need to
    // reimplement it again (just reuse implementation from AbstractGroup)
    QRect getBoundary() override;
};
