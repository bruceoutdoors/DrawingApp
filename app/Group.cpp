#include "Group.hpp"
#include <exception>
#include <algorithm>

Group::Group()
{

}

Group::~Group()
{
    clear();
}

// returns index of added visual entity
void Group::add(VisualEntity *val)
{
    if (val->getParentGroup()) {
        Group *xparent = val->getParentGroup();
        xparent->remove(val);
    }

    val->setParentGroup(this);
    m_children.push_back(val);
    int index = m_children.size() - 1;
    val->setIndex(index);
}

void Group::draw(QPainter *painter)
{
    for (VisualEntity *visual : m_children) {
        visual->draw(painter);
    }
}

bool Group::contains(int x, int y)
{
    return AbstractGroup::contains(x, y);
}

void Group::remove(int index)
{
    remove(get(index));
}

void Group::remove(VisualEntity *val)
{
    AbstractGroup::remove(val);
    val->setParentGroup(nullptr);
    val->setSelected(false);
}

void Group::clear()
{
    for (VisualEntity *visual : m_children) {
        delete visual;
    }

    m_children.clear();
}

// first in order gets sent back
VisualEntity *Group::getClicked(int x, int y)
{
    // last drawn visual entity is in the most front
    for (int i = m_children.size() - 1; i >= 0; i--) {
        if (m_children[i]->contains(x, y)) return m_children[i];
    }

    return nullptr;
}
