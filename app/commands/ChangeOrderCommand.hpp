#pragma once

#include "Command.hpp"
#include <vector>

class Selection;
class Group;

class ChangeOrderCommand : public Command
{
public:
    ChangeOrderCommand();
    virtual ~ChangeOrderCommand();

    static bool canChangeOrder();

    void undo()    override;

protected:
    Selection *m_sel;
    Group *m_parent;
    std::vector<int> m_initOrder;
};
