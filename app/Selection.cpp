#include "Selection.hpp"
#include "Group.hpp"
#include <QPainter>

void Selection::draw(QPainter *painter)
{
    QBrush brush;
    QPen pen(Qt::DotLine);

    pen.setWidth(2);

    painter->setBrush(brush);

    if (m_children.size() > 1) {
        pen.setColor(QColor(250, 150, 150));
        painter->setPen(pen);
        painter->drawRect(getBoundary());
    }

    pen.setColor(QColor(255, 20, 20));
    painter->setPen(pen);
    for (auto child : m_children) {
        painter->drawRect(child->getBoundary());
    }
}

int Selection::add(VisualEntity *val)
{
    for (int i = 0; i < int(m_children.size()); i++) {
        if (m_children[i] == val)
            return i;
    }

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

Selection::Selection(const Selection &other)
{
    *this = other;
}

Selection &Selection::operator=(const Selection &other)
{
    if(this != &other) {
        deselectAll();
        for (int i = 0; i < other.getSize(); i++) {
            add(other.get(i));
        }
    }

    return *this;
}

