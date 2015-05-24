#include "ChangeOrderCommand.hpp"
#include "ActiveSelection.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"
#include <cassert>

ChangeOrderCommand::ChangeOrderCommand()
{
    m_sel = new Selection();
    *m_sel = ActiveSelection::getInstance();

    assert(m_sel->getSize() > 0);

    // We assume, that in changing order, the parent group of
    // all selected entities are the same.
    m_parent = m_sel->get(0)->getParentGroup();

    for (int i = 0; i < m_sel->getSize(); i++) {
        m_initOrder.push_back(m_sel->get(i)->getIndex());
    }
}

ChangeOrderCommand::~ChangeOrderCommand()
{
    delete m_sel;
}

bool ChangeOrderCommand::canChangeOrder()
{
    ActiveSelection *as = &ActiveSelection::getInstance();

    if (as->getSize() == 0) return false;

    Group *g = as->get(0)->getParentGroup();
    if (g->getSize() == 1
            || g->getSize() == as->getSize())
        return false;

    return true;
}

void ChangeOrderCommand::undo()
{
    for (int i = 0; i < m_sel->getSize(); i++) {
        int idx = m_sel->get(i)->getIndex();
        m_parent->swap(idx, m_initOrder[i]);
    }
}

