#include "Group.hpp"
#include <exception>

Group::Group()
{

}

Group::~Group()
{
    for (VisualEntity *visual : m_visuals) {
        delete visual;
    }
}

// returns index of added visual entity
int Group::addVisualEntity(VisualEntity *val)
{
    val->setParentGroup(this);
    m_visuals.push_back(val);
    int index = m_visuals.size() - 1;
    val->setIndex(index);

    return index;
}

// removes the pointer from container; does not delete the actual entity
void Group::removeVisualEntity(int index)
{
    if (index > (m_visuals.size() - 1) || index < 0) {
        throw std::runtime_error("There is no such index in Group: " + index);
    }

    m_visuals[index]->setIndex(-1);
    m_visuals.erase(m_visuals.begin() + index);
}

// removes and destroy the entity
void Group::destroyVisualEntity(int index)
{
    auto v = m_visuals[index];

    removeVisualEntity(index);

    delete v;
}

void Group::draw(QPainter *painter)
{
    for (VisualEntity *visual : m_visuals) {
        visual->draw(painter);
    }
}

int Group::getSize()
{
    return m_visuals.size();
}

