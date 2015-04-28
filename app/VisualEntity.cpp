#include "VisualEntity.hpp"
#include "Group.hpp"
#include <exception>
#include <stdexcept>

VisualEntity::VisualEntity() :
    m_parentGroup(nullptr)
{
    m_index = -1;
    m_position = QPoint(0, 0);
}

VisualEntity::~VisualEntity()
{

}

void VisualEntity::setPosition(QPoint pos)
{
    m_position = pos;
}

QPoint VisualEntity::getPosition()
{
    return m_position;
}

void VisualEntity::setParentGroup(Group *val)
{
    if (m_parentGroup != nullptr) {
        m_parentGroup->removeVisualEntity(m_index);
    }

    m_parentGroup = val;
}

void VisualEntity::selfDestruct()
{
    if (m_parentGroup == nullptr) {
        throw std::runtime_error("Self-destruct only works if Visual Entity is under a parent group!");
    }

    m_parentGroup->destroyVisualEntity(m_index);
}

int VisualEntity::getIndex() const
{
    return m_index;
}

void VisualEntity::setIndex(int value)
{
    m_index = value;
}


