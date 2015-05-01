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
    int getSize();

    void draw(QPainter *painter) override;
    QRect getBoundary() override;

    bool contains(int x, int y) override;

private:
    std::vector<VisualEntity*> m_visuals;
};

#endif // GROUP_H
