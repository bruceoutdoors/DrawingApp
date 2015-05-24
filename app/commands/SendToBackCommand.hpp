#pragma once

#include "ChangeOrderCommand.hpp"

class SendToBackCommand : public ChangeOrderCommand
{
public:
    void execute() override;
};

