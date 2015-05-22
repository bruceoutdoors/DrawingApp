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
    std::vector<VisualEntity*>::iterator find(VisualEntity *val);
    VisualEntity* get(int index) const;
    void remove(int index);
    void remove(VisualEntity *val);
    void destroy(int index);
    int getSize() const;
    QRect getBoundary() override;

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

protected:
    std::vector<VisualEntity*> m_children;
};
