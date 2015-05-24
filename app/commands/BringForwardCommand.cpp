#include "BringForwardCommand.hpp"
#include "Selection.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"
#include <stdexcept>

void BringForwardCommand::execute()
{
    for (int i = 0; i < m_sel->getSize(); i++) {
        int idx = m_sel->get(i)->getIndex();
        try {
            VisualEntity *v = m_parent->get(idx+1);
            if (m_sel->isSelected(v)) continue;
        } catch (const std::runtime_error &) {
            continue;
        }
        m_parent->swap(idx, idx+1);
    }
}
