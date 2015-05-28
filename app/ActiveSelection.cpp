#include "ActiveSelection.hpp"

ActiveSelection &ActiveSelection::getInstance()
{
    static ActiveSelection instance;
    return instance;
}

void ActiveSelection::add(VisualEntity *val)
{
    int size = getSize();
    Selection::add(val);
    int newSize = getSize();

    if (size != newSize) {
        m_selectionSizeChanged.broadcast(getSize());
    }
}

void ActiveSelection::remove(VisualEntity *val)
{
    int size = getSize();
    Selection::remove(val);
    int newSize = getSize();

    if (size != newSize) {
        m_selectionSizeChanged.broadcast(getSize());
    }
}

Signal<size_t> *ActiveSelection::getSelectionSizeChangedSignal()
{
    return &m_selectionSizeChanged;
}

ActiveSelection::ActiveSelection()
{

}

ActiveSelection::~ActiveSelection()
{
    m_selectionSizeChanged.disconnectAll();
}

