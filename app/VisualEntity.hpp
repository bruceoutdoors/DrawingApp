#pragma once

#include "ISelectable.hpp"
#include "IDrawable.hpp"
#include "ITransformable.hpp"

class QPainter;
class Group;

class VisualEntity : public IDrawable, public ITransformable
{
public:
    VisualEntity();
    virtual ~VisualEntity();

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

    void setParentGroup(Group *val);
    void selfDestruct();

    int getIndex() const;
    void setIndex(int value);

protected:
    Group *m_parentGroup;
    QPoint m_position;
    int m_index;
};

