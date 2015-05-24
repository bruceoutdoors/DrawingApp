#pragma once

#include "ChangeOrderCommand.hpp"

class BringToFrontCommand : public ChangeOrderCommand
{
public:
    void execute() override;
};

