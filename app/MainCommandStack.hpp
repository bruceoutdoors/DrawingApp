#pragma once

#include "CommandStack.hpp"
#include <vector>

class MainWindow;

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

