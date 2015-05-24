#include "BringToFrontCommand.hpp"
#include "BringForwardCommand.hpp"

ChangeOrderCommand *BringToFrontCommand::getNewChangeOrderCommand()
{
    return new BringForwardCommand();
}
