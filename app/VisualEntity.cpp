#include "VisualEntity.hpp"
#include "Group.hpp"

#include <exception>
#include <stdexcept>
#include <QPainter>

VisualEntity::VisualEntity() :
    m_parentGroup(nullptr)
{
    setSelected(false);

    m_index = -1;
    m_position = QPoint(0, 0);
}

VisualEntity::~VisualEntity()
{

}

void VisualEntity::drawSelection(QPainter *painter)
{
    QBrush brush;
    QPen pen(Qt::DashLine);

    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(2);

    painter->setBrush(brush);
    painter->setPen(pen);

    painter->drawRect(getBoundary());
}

void VisualEntity::setSelected(bool val)
{
    m_selected = val;
}

void VisualEntity::toogleSelect()
{
    m_selected = !m_selected;
}

bool VisualEntity::isSelected()
{
    return m_selected;
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
    m_parentGroup = val;
}

Group *VisualEntity::getParentGroup()
{
    return m_parentGroup;
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


