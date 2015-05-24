#pragma once

#include "ChangeOrderCommand.hpp"

class SendBackwardCommand : public ChangeOrderCommand
{
public:
    void execute() override;
};

