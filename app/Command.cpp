#include "Command.hpp"
#include "CommandStack.hpp"

void Command::addtoCommandStack()
{
    CommandStack::getInstance().add(this);
}
