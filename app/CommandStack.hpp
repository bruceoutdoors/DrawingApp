#pragma once

#include "Command.hpp"
#include "Signal.hpp"
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
    Signal<int> *getCurrentIndexChangedSignal();

protected:
    virtual void setCurrentIdx(const int &idx);

private:
    Signal<int> m_currentIndexChanged;
    std::vector<Command*> m_stack;
    int m_current;
};

