#include "DrawCommand.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"
#include "ActiveSelection.hpp"

DrawCommand::DrawCommand(VisualEntity *c)
{
    m_ve = c;
    m_parent = c->getParentGroup();

    m_drawCommandGroup = new Group();
}

DrawCommand::~DrawCommand()
{
    delete m_drawCommandGroup;
}

void DrawCommand::execute()
{
    m_parent->add(m_ve);
    ActiveSelection::getInstance().deselectAll();
    m_ve->setSelected(true);
}

void DrawCommand::undo()
{
    ActiveSelection::getInstance().deselectAll();

    // a group here also manages the memory.
    // Adding it in another DrawCommand's group will pass
    // the responsiblity to destroy the visual entity
    // to that DrawCommand's group
    m_drawCommandGroup->add(m_ve);
}
