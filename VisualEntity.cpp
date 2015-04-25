#include "VisualEntity.hpp"

VisualEntity::VisualEntity(QPainter *painter) :
    m_painter(painter)
{

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

