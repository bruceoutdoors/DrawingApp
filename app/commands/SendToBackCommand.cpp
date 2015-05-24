#include "SendToBackCommand.hpp"
#include "SendBackwardCommand.hpp"

ChangeOrderCommand *SendToBackCommand::getNewChangeOrderCommand()
{
    return new SendBackwardCommand();
}
