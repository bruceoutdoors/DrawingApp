#pragma once

#include "ISelectable.hpp"
#include "IDrawable.hpp"
#include "ITransformable.hpp"

class QPainter;
class Group;
class Selection;

class VisualEntity : public IDrawable, public ISelectable, public ITransformable
{
public:
    VisualEntity();
    virtual ~VisualEntity();

    void setSelected(bool val) override;
    void toogleSelect() override;
    bool isSelected() override;

    void setParentGroup(Group *val);
    Group* getParentGroup();
    void selfDestruct();

    int getIndex() const;
    void setIndex(int value);

protected:
    Group *m_parentGroup;
    Selection *m_selection;

    int m_index;
};

