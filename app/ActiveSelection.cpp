#include "ActiveSelection.hpp"
#include "GlobalDrawProperties.hpp"

ActiveSelection &ActiveSelection::getInstance()
{
    static ActiveSelection instance;
    return instance;
}

int ActiveSelection::add(VisualEntity *val)
{
    int size = m_children.size();
    int index = Selection::add(val);

    if (size != index + 1) {
        GlobalDrawProperties::getInstance().update();
    }

    return index;
}

ActiveSelection::ActiveSelection()
{

}

ActiveSelection::~ActiveSelection()
{

}

