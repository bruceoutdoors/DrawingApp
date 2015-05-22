#pragma once

#include "Command.hpp"
#include <vector>

// singleton
class CommandStack
{
public:
    static CommandStack &getInstance();
    void add(Command *c);
    void undo();
    void redo();
    void clear();
    int getSize();

private:
    CommandStack();
    ~CommandStack();
    CommandStack(CommandStack const&) {}
    CommandStack& operator=(CommandStack const&) {}

    std::vector<Command*> m_stack;
    int m_current;
};

