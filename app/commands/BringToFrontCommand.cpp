#include "BringToFrontCommand.hpp"
#include "Selection.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"

void BringToFrontCommand::execute()
{
    int currentFront = m_parent->getSize() - 1;

    for (int i = 0; i < m_sel->getSize(); i++) {
        int idx = m_sel->get(i)->getIndex();
        m_parent->swap(idx, currentFront--);
    }
}
