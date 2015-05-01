#pragma once

#include "ISelectable.hpp"
#include "IDrawable.hpp"
#include "ITransformable.hpp"

class QPainter;
class Group;

class VisualEntity : public IDrawable, public ITransformable, public ISelectable
{
public:
    VisualEntity();
    virtual ~VisualEntity();

    void drawSelection(QPainter *painter) override;

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

    void setParentGroup(Group *val);
    Group* getParentGroup();
    void selfDestruct();

    int getIndex() const;
    void setIndex(int value);

protected:
    Group *m_parentGroup;
    QPoint m_position;
    int m_index;
};

