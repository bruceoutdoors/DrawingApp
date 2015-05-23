#pragma once

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}

    void addtoCommandStack();
};


