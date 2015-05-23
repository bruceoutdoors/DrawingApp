#include "MoveSelectionCommand.hpp"
#include "ActiveSelection.hpp"
#include "VisualEntity.hpp"

MoveSelectionCommand::MoveSelectionCommand(QPoint start) :
    m_start(start)
{
    m_sel = new Selection();
    *m_sel = ActiveSelection::getInstance();

    for (int i = 0; i < m_sel->getSize(); i++) {
        m_VEPos.push_back(m_sel->get(i)->getPosition());
    }
}

MoveSelectionCommand::~MoveSelectionCommand()
{
    delete m_sel;
}

void MoveSelectionCommand::setPosition(QPoint target)
{
    m_target = target;
}

void MoveSelectionCommand::execute()
{
    for (int i = 0; i < m_sel->getSize(); i++) {
        QPoint destination = m_VEPos[i] + (m_target - m_start);
        m_sel->get(i)->setPosition(destination);
    }
}

void MoveSelectionCommand::undo()
{
    for (int i = 0; i < m_sel->getSize(); i++) {
        m_sel->get(i)->setPosition(m_VEPos[i]);
    }
}
