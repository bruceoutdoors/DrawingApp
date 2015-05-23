#include "ChangeFillColorCommand.hpp"
#include "ActiveSelection.hpp"
#include "Shape.hpp"

#include <cassert>

// on creation, this command saves the active selection and
// its respective colors
ChangeFillColorCommand::ChangeFillColorCommand()
{
    m_currentSelection = new Selection();
    *m_currentSelection = ActiveSelection::getInstance();

    assert(m_currentSelection->getSize() > 0);

    // removes unfillable objects (non-Shape) and saves colors of fillable ones
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            m_savedColors.push_back(s->getFillColor());
        } else {
            m_currentSelection->remove(i);
            i--;
        }
    }

    assert(m_savedColors.size() == m_currentSelection->getSize());
}

ChangeFillColorCommand::~ChangeFillColorCommand()
{
    delete m_currentSelection;
}

void ChangeFillColorCommand::setColor(QColor color)
{
    m_color = color;
}

void ChangeFillColorCommand::execute()
{
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            s->setFillColor(m_color);
        }
    }
}

void ChangeFillColorCommand::undo()
{
    for (int i = 0; i < m_currentSelection->getSize(); i++) {
        Shape *s =  dynamic_cast<Shape*>(m_currentSelection->get(i));

        if (s) {
            s->setFillColor(m_savedColors[i]);
        }
    }
}

