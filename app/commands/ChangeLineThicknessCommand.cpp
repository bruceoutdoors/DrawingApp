#include "ChangeLineThicknessCommand.hpp"
#include "ActiveSelection.hpp"
#include "Shape.hpp"
#include "Line.hpp"

#include <cassert>

// on creation, this command saves the active selection and
// its respective colors
ChangeLineThicknessCommand::ChangeLineThicknessCommand()
{
    m_currentSelection = new Selection();
    *m_currentSelection = ActiveSelection::getInstance();

    assert(m_currentSelection->getSize() > 0);

    // removes unlinable objects and saves colors of lines
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            m_savedThickness.push_back(s->getLineThickness());
            continue;
        }

        Line *l = dynamic_cast<Line*>(m_currentSelection->get(i));

        if (l) {
            m_savedThickness.push_back(l->getLineThickness());
            continue;
        }

        m_currentSelection->remove(i);
        i--;
    }

    assert(m_savedThickness.size() == m_currentSelection->getSize());
}

ChangeLineThicknessCommand::~ChangeLineThicknessCommand()
{
    delete m_currentSelection;
}

void ChangeLineThicknessCommand::setThickness(int thickness)
{
    m_thickness = thickness;
}

void ChangeLineThicknessCommand::execute()
{
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            s->setLineThickness(m_thickness);
            continue;
        }

        Line *l = dynamic_cast<Line*>(m_currentSelection->get(i));

        if (l) {
            l->setLineThickness(m_thickness);
        }
    }
}

void ChangeLineThicknessCommand::undo()
{
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            s->setLineThickness(m_savedThickness[i]);
            continue;
        }

        Line *l = dynamic_cast<Line*>(m_currentSelection->get(i));

        if (l) {
            l->setLineThickness(m_savedThickness[i]);
        }
    }
}

