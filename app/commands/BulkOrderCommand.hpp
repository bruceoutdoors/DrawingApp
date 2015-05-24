#pragma once

#include "Command.hpp"
#include "CommandStack.hpp"

class ChangeOrderCommand;

class BulkOrderCommand : public Command
{
public:
    BulkOrderCommand();
    ~BulkOrderCommand();

    virtual ChangeOrderCommand* getNewChangeOrderCommand() = 0;

    void execute() override;
    void undo() override;

private:
    CommandStack *m_cstack;
    int m_commExecuteCount;
};

