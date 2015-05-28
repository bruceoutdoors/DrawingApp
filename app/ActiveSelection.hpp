#pragma once

#include "Selection.hpp"
#include "Signal.hpp"

// singleton
class ActiveSelection : public Selection
{
public:
    static ActiveSelection& getInstance();
    void add(VisualEntity *val) override;
    void remove(VisualEntity *val) override;

    Signal<size_t> *getSelectionSizeChangedSignal();

private:
    Signal<size_t> m_selectionSizeChanged;
    ActiveSelection();
    virtual ~ActiveSelection();
};

