#include "MainCommandStack.hpp"

MainCommandStack &MainCommandStack::getInstance()
{
    static MainCommandStack instance;
    return instance;
}
