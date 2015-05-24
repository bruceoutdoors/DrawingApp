#pragma once

#include "CommandStack.hpp"
#include <vector>

// singleton
class MainCommandStack : public CommandStack
{
public:
    static MainCommandStack &getInstance();

private:
    MainCommandStack() {}
    virtual ~MainCommandStack() {}
    MainCommandStack(MainCommandStack const&) {}
    MainCommandStack& operator=(MainCommandStack const&) {}
};

