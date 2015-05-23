#include "ChangeLineColorCommand.hpp"
#include "ActiveSelection.hpp"
#include "Shape.hpp"
#include "Line.hpp"

#include <cassert>

// on creation, this command saves the active selection and
// its respective colors
ChangeLineColorCommand::ChangeLineColorCommand()
{
    m_currentSelection = new Selection();
    *m_currentSelection = ActiveSelection::getInstance();

    assert(m_currentSelection->getSize() > 0);

    // removes unlinable objects and saves colors of lines
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            m_savedColors.push_back(s->getLineColor());
            continue;
        }

        Line *l = dynamic_cast<Line*>(m_currentSelection->get(i));

        if (l) {
            m_savedColors.push_back(l->getLineColor());
            continue;
        }

        m_currentSelection->remove(i);
        i--;
    }

    assert(m_savedColors.size() == m_currentSelection->getSize());
}

ChangeLineColorCommand::~ChangeLineColorCommand()
{
    delete m_currentSelection;
}

void ChangeLineColorCommand::setColor(QColor color)
{
    m_color = color;
}

void ChangeLineColorCommand::execute()
{
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            s->setLineColor(m_color);
            continue;
        }

        Line *l = dynamic_cast<Line*>(m_currentSelection->get(i));

        if (l) {
            l->setLineColor(m_color);
        }
    }
}

void ChangeLineColorCommand::undo()
{
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            s->setLineColor(m_savedColors[i]);
            continue;
        }

        Line *l = dynamic_cast<Line*>(m_currentSelection->get(i));

        if (l) {
            l->setLineColor(m_savedColors[i]);
        }
    }
}

