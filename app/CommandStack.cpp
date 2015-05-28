#include "CommandStack.hpp"

void CommandStack::add(Command *c)
{
    if (m_stack.size() == 0) { // 1st element
        m_stack.push_back(c);
        setCurrentIdx(0);
        return;
    }

    // wipe out commands on top, if any
    while (int(m_stack.size() - 1) > m_current) {
        int next = m_current + 1;
        delete m_stack[next];
        m_stack.erase(m_stack.begin() + next);
    }

    m_stack.push_back(c);
    setCurrentIdx(m_current+1);
}

void CommandStack::undo()
{
    if (m_current == -1) return;

    m_stack[m_current]->undo();
    setCurrentIdx(m_current-1);
}

void CommandStack::redo()
{
    // if last element
    if (m_stack.size() == 0
            || m_current == m_stack.size() - 1) return;

    setCurrentIdx(m_current+1);
    m_stack[m_current]->execute();
}

void CommandStack::clear()
{
    for (Command *command : m_stack) {
        delete command;
    }

    m_stack.clear();
    setCurrentIdx(-1);
}

int CommandStack::getSize() const
{
    return m_stack.size();
}

void CommandStack::setCurrentIdx(const int &idx)
{
    m_current = idx;

    m_currentIndexChanged.broadcast(m_current);
}

int CommandStack::getCurrentIdx() const
{
    return m_current;
}

Signal<int> *CommandStack::getCurrentIndexChangedSignal()
{
    return &m_currentIndexChanged;
}

CommandStack::CommandStack() :
    m_current(-1)
{
}

CommandStack::~CommandStack()
{
    m_currentIndexChanged.disconnectAll();

    clear();
}
