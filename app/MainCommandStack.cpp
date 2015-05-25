#include "MainCommandStack.hpp"
#include "MainWindow.hpp"

MainCommandStack &MainCommandStack::getInstance()
{
    static MainCommandStack instance;
    return instance;
}

void MainCommandStack::setMainWindow(MainWindow *mw)
{
    m_mw = mw;
}

void MainCommandStack::setCurrentIdx(const int &idx)
{
    CommandStack::setCurrentIdx(idx);

    if (m_mw)
        m_mw->mainCommandStackHasChanged();
}
