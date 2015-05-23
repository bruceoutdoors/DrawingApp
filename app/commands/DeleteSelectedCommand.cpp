#include "DeleteSelectedCommand.hpp"
#include "DrawCommand.hpp"
#include "ActiveSelection.hpp"
#include "VisualEntity.hpp"

#include <cassert>

DeleteSelectedCommand::DeleteSelectedCommand()
{
    m_as = new Selection();
    *m_as = ActiveSelection::getInstance();

    assert(m_as->getSize() > 0);

    for (int i = 0; i < m_as->getSize(); i++) {
        DrawCommand *dc = new DrawCommand(m_as->get(i));
        m_drawCommands.push_back(dc);
    }
}

DeleteSelectedCommand::~DeleteSelectedCommand()
{
	delete m_as;

    for (auto &dc : m_drawCommands) {
        delete dc;
    }
}

void DeleteSelectedCommand::execute()
{
    for (auto &dc : m_drawCommands) {
        dc->undo();
    }
}

void DeleteSelectedCommand::undo()
{
    for (auto &dc : m_drawCommands) {
        dc->execute();
    }

    for (int i = 0; i < m_as->getSize(); i++) {
        m_as->get(i)->setSelected(true);
    }
}
