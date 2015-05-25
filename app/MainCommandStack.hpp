#pragma once

#include "CommandStack.hpp"
#include <vector>

class MainWindow;

// singleton
class MainCommandStack : public CommandStack
{
public:
    static MainCommandStack &getInstance();
    void setMainWindow(MainWindow *mw);

protected:
    void setCurrentIdx(const int &idx) override;

private:
    MainWindow *m_mw;

    MainCommandStack() : m_mw(nullptr) {}
    virtual ~MainCommandStack() {}
    MainCommandStack(MainCommandStack const&) {}
    MainCommandStack& operator=(MainCommandStack const&) {}
};

