#ifndef GROUP_H
#define GROUP_H

#include "VisualEntity.hpp"
#include <vector>

class Group : public VisualEntity
{
public:
    Group();
    ~Group();
    void removeVisualEntity(int index);
    void destroyVisualEntity(int index);
    void drawSelectedSelection(QPainter *painter);
    void deselectAll();
    int addVisualEntity(VisualEntity *val);
    int getSize();
    VisualEntity* getClicked(int x, int y);

    void draw(QPainter *painter) override;
    QRect getBoundary() override;
    bool contains(int x, int y) override;

    void setPosition(QPoint val) override;
    QPoint getPosition() override;

private:
    std::vector<VisualEntity*> m_visuals;
};

#endif // GROUP_H
