#ifndef GROUP_H
#define GROUP_H

#include "VisualEntity.hpp"
#include <vector>

class Group : public VisualEntity
{
public:
    Group();
    ~Group();
    int addVisualEntity(VisualEntity *val);
    void removeVisualEntity(int index);
    void destroyVisualEntity(int index);
    void draw(QPainter *painter) override;
    int getSize();

private:
    std::vector<VisualEntity*> m_visuals;
};

#endif // GROUP_H
