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

void Group::drawSelectedSelection(QPainter *painter)
{
    for (VisualEntity *visual : m_visuals) {
        if (visual->isSelected()) {
            visual->drawSelection(painter);
        }
    }
}

QRect Group::getBoundary()
{
    if (m_visuals.size() == 0) return QRect();

    int x = INT_MAX;
    int y = INT_MAX;
    int right = 0;
    int bottom = 0;

    for (VisualEntity *visual : m_visuals) {
        QRect b = visual->getBoundary();

        if (b.x() < x) x = b.x();
        if (b.y() < y) y = b.y();
        if (b.right()  > right)  right  = b.right();
        if (b.bottom() > bottom) bottom = b.bottom();
    }

    return QRect(QPoint(x, y), QPoint(right, bottom));
}

bool Group::contains(int x, int y)
{
    for (VisualEntity *visual : m_visuals) {
        if (visual->contains(x, y)) return true;
    }

    return false;
}

// first in order gets sent back
VisualEntity *Group::getClicked(int x, int y)
{
    // last drawn visual entity is in the most front
    for (int i = m_visuals.size() - 1; i >= 0; i--) {
        if (m_visuals[i]->contains(x, y)) return m_visuals[i];
    }

    return nullptr;
}

int Group::getSize()
{
    return m_visuals.size();
}

