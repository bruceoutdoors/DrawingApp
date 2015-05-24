#include "SendToBackCommand.hpp"
#include "Selection.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"

void SendToBackCommand::execute()
{
    int currentBack = 0;

    for (int i = m_sel->getSize()-1; i >= 0; i--) {
        int idx = m_sel->get(i)->getIndex();
        m_parent->swap(idx, currentBack++);
    }
}
