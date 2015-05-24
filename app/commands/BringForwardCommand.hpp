#pragma once

#include "ChangeOrderCommand.hpp"

class BringForwardCommand : public ChangeOrderCommand
{
public:
    void execute() override;
};

