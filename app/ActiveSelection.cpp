#include "ActiveSelection.hpp"
#include "GlobalDrawProperties.hpp"

ActiveSelection &ActiveSelection::getInstance()
{
    static ActiveSelection instance;
    return instance;
}

void ActiveSelection::add(VisualEntity *val)
{
    int size = m_children.size();
    Selection::add(val);
    int newSize = m_children.size();

    if (size != newSize) {
        GlobalDrawProperties::getInstance().update();
    }
}

ActiveSelection::ActiveSelection()
{

}

ActiveSelection::~ActiveSelection()
{

}

