#include "Command.hpp"
#include "MainCommandStack.hpp"

void Command::addtoCommandStack()
{
    MainCommandStack::getInstance().add(this);
}
