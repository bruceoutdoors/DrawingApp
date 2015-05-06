#pragma once

#include "AbstractGroup.h"

class VisualEntity;
class Group;

// singleton
class Selection : public AbstractGroup
{
public:
    static Selection& getInstance();

    void draw(QPainter *painter) override;
    int add(VisualEntity *val) override;

    bool isSelected(VisualEntity *val);
    void toggleSelect(VisualEntity *val);
    void deselectAll();
//    Group* makeGroup();

private:
    Selection();
    ~Selection();
    Selection(Selection const&) {}
    Selection& operator=(Selection const&) {}
};

