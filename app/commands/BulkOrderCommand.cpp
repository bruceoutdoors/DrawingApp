#include "BulkOrderCommand.hpp"
#include "CommandStack.hpp"
#include "ChangeOrderCommand.hpp"
#include "ActiveSelection.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"
#include <cassert>

BulkOrderCommand::BulkOrderCommand()
{
    assert(ActiveSelection::getInstance().getSize() > 0);

    m_commExecuteCount = ActiveSelection::getInstance().get(0)->getParentGroup()->getSize();

    m_cstack = new CommandStack();
}

BulkOrderCommand::~BulkOrderCommand()
{
    delete m_cstack;
}

void BulkOrderCommand::execute()
{
    // execute the max number of times to bring an object to the front
    // it's hackish, but I'm willing to close a blind eye on this :P
    for (int i = 0; i < m_commExecuteCount; i++) {
        ChangeOrderCommand *bfc = getNewChangeOrderCommand();
        bfc->execute();
        m_cstack->add(bfc);
    }
}

void BulkOrderCommand::undo()
{
    while (m_cstack->getCurrentIdx() != -1) {
        m_cstack->undo();
    }
}

