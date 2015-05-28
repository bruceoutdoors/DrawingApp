#pragma once

#include "Command.hpp"

#include "ActiveSelection.hpp"

#include <vector>
#include <cassert>

class VisualEntity;
class Shape;
class Line;

template <class T,
          class Type,
          void (T::*TSetter)(const Type &),
          Type (T::*TGetter)(void) const>
class ChangePropertyCommand : public Command
{
public:
    ChangePropertyCommand()
    {
        ActiveSelection *as = &ActiveSelection::getInstance();

        assert(as->getSize() > 0);

        for (int i = 0; i < as->getSize(); i++) {
            T *t = dynamic_cast<T*>(as->get(i));

            if (t) {
                m_savedVals.push_back((t->*TGetter)());
                m_Ts.push_back(t);
            }
        }
    }

    virtual ~ChangePropertyCommand() {}

    bool canExecute() override
    {
        return (m_Ts.size() == 0) ? false : true;
    }

    void setValue(const Type &color)
    {
        m_val = color;
    }

    void execute() override
    {
        for (auto &t : m_Ts) {
            (t->*TSetter)(m_val);
        }
    }

    void undo() override
    {
        for (size_t i = 0; i < m_Ts.size(); i++) {
            (m_Ts[i]->*TSetter)(m_savedVals[i]);
        }
    }

private:
    std::vector<Type> m_savedVals;
    std::vector<T*> m_Ts;
    Type m_val;
};

