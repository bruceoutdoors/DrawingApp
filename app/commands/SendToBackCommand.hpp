#pragma once

#include "BulkOrderCommand.hpp"

class SendToBackCommand : public BulkOrderCommand
{
public:
    ChangeOrderCommand* getNewChangeOrderCommand() override;
};

