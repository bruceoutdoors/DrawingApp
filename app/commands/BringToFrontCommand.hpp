#pragma once

#include "BulkOrderCommand.hpp"

class BringToFrontCommand : public BulkOrderCommand
{
public:
    ChangeOrderCommand* getNewChangeOrderCommand() override;
};

