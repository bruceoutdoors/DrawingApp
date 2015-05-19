#include "AbstractGroup.hpp"
#include "VisualEntity.hpp"

AbstractGroup::AbstractGroup()
{

}

AbstractGroup::~AbstractGroup()
{

}

VisualEntity *AbstractGroup::get(int index)
{
    if (index > (m_children.size() - 1) || index < 0) {
        throw std::runtime_error("There is no such index in Group: " + index);
    }

    return m_children[index];
}

// removes the pointer from container; does not delete the actual entity
void AbstractGroup::remove(int index)
{
    get(index); // just validates whether it exists

    m_children.erase(m_children.begin() + index);
}

void AbstractGroup::remove(VisualEntity *val)
{
    auto result = find(val);

    if (result != m_children.end()) {
        m_children.erase(result);
    }
}

void AbstractGroup::removeAll()
{
    m_children.clear();
}

void AbstractGroup::destroy(int index)
{
    auto v = m_children[index];

    remove(index);

    delete v;
}

int AbstractGroup::getSize()
{
    return m_children.size();
}

QRect AbstractGroup::getBoundary()
{
    if (getSize() == 0) return QRect();

    int x = INT_MAX;
    int y = INT_MAX;
    int right = 0;
    int bottom = 0;

    for (VisualEntity *visual : m_children) {
        QRect b = visual->getBoundary();

        if (b.x() < x) x = b.x();
        if (b.y() < y) y = b.y();
        if (b.right()  > right)  right  = b.right();
        if (b.bottom() > bottom) bottom = b.bottom();
    }

    return QRect(QPoint(x, y), QPoint(right, bottom));
}

std::vector<VisualEntity*>::iterator AbstractGroup::find(VisualEntity *val)
{
    auto result = std::find(m_children.begin(), m_children.end(), val);
    if(result != m_children.end()){
          return result;
    } else return m_children.end();
}

void AbstractGroup::setPosition(QPoint pos)
{
    // TODO: implement this...
}

QPoint AbstractGroup::getPosition()
{
    QRect b = getBoundary();

    return QPoint(b.x() + b.width()/2,
                  b.y() + b.height()/2);
}

