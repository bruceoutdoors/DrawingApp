#pragma once

#include <functional>
#include <map>

template<class... Args>
class Signal
{
public:
    // connect to slot; returns function that disconnects this link
    std::function<void()> connect(std::function<void(Args... args)> func) 
    {
        int funcKey = m_key;
        m_funcs[m_key++] = func;
        
        return [=]() {
            m_funcs.erase(funcKey);
        };
    }
    
    void broadcast(Args... args)
    {
        for (auto &func : m_funcs) {
            func.second(args...);
        }
    }

    void disconnectAll()
    {
        m_funcs.clear();
    }
  
private:
    int m_key;
    std::map<int, std::function<void(Args...)> > m_funcs;
};
