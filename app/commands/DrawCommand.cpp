#include "DrawCommand.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"

DrawCommand::DrawCommand(VisualEntity *c)
{
    m_ve = c;
    m_parent = c->getParentGroup();
}

DrawCommand::~DrawCommand()
{
    if (!m_ve->getParentGroup())
        delete m_ve;
}

void DrawCommand::execute()
{
    m_parent->add(m_ve);
}

void DrawCommand::undo()
{
    m_parent->remove(m_ve);
}
