#pragma once

#include "Command.hpp"
#include <vector>

// singleton
class CommandStack
{
public:
    CommandStack();
    virtual ~CommandStack();

    void add(Command *c);
    void undo();
    void redo();
    void clear();
    int getSize() const;

    int getCurrentIdx() const;

protected:
    virtual void setCurrentIdx(const int &idx);

private:
    std::vector<Command*> m_stack;
    int m_current;
};

