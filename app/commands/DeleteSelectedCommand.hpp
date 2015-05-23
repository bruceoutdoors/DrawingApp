#pragma once

#include "Command.hpp"
#include <vector>

class DrawCommand;
class Selection;

// a DeleteSelectedCommand essentially stores a bunch of
// draw commands from a selection
class DeleteSelectedCommand : public Command
{
public:
    DeleteSelectedCommand();
    virtual ~DeleteSelectedCommand();

    void execute() override;
    void undo()    override;

private:
    std::vector<DrawCommand*> m_drawCommands;
    Selection *m_as;
};

