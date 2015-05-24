#pragma once

#include "IDrawable.hpp"
#include "ITransformable.hpp"
#include <vector>

class VisualEntity;

class AbstractGroup : public IDrawable, public ITransformable
{
public:
    AbstractGroup();
    virtual ~AbstractGroup();

    virtual int add(VisualEntity *val) = 0;
    virtual void remove(int index);
    virtual void remove(VisualEntity *val);
    virtual bool contains(int x, int y);

    void swap(int idx1, int idx2);
    std::vector<VisualEntity*>::iterator find(VisualEntity *val);
    bool isInside(VisualEntity *val);
    VisualEntity* get(int index) const;
    void destroy(int index);
    int getSize() const;
    QRect getBoundary() override;

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

protected:
    void reindexChildren();
    std::vector<VisualEntity*> m_children;
};
