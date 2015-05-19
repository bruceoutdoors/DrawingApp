#include "Selection.hpp"
#include "Group.hpp"
#include <QPainter>

Selection &Selection::getInstance()
{
    static Selection instance;
    return instance;
}

void Selection::draw(QPainter *painter)
{
    QBrush brush;
    QPen pen(Qt::DashLine);

    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(2);

    painter->setBrush(brush);
    painter->setPen(pen);

    for (auto child : m_children) {
        painter->drawRect(child->getBoundary());
    }
}

int Selection::add(VisualEntity *val)
{
    m_children.push_back(val);
    return m_children.size() - 1;
}

VisualEntity *Selection::getLastSelected()
{
    return m_children[m_children.size() - 1];
}

bool Selection::isSelected(VisualEntity *val)
{
    return find(val) != m_children.end();
}

void Selection::toggleSelect(VisualEntity *val)
{
    if (isSelected(val)) {
        remove(val);
    } else {
        add(val);
    }
}

void Selection::deselectAll()
{
    m_children.clear();
}

Selection::Selection()
{
}

Selection::~Selection()
{
}

