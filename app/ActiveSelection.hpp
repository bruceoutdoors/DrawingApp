#pragma once

#include "Selection.hpp"

// singleton
class ActiveSelection : public Selection
{
public:
    static ActiveSelection& getInstance();
    int add(VisualEntity *val) override;

private:
    ActiveSelection();
    virtual ~ActiveSelection();
};

