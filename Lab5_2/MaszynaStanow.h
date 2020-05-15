#pragma once
#include <iostream>
#include <vector>
#include "Stan.h"

class Stan;
class MaszynaStanow
{
private:
    std::vector<Stan*> m_states;
    unsigned int m_current;

public:
    MaszynaStanow() : m_current(0) {}
    ~MaszynaStanow();
    friend class Stan;
    MaszynaStanow & operator+= (Stan*);
    Stan& operator()();
    void start();
    void operator++();
    void operator--();
    void print(std::ostream&) const;
    void podsumowanie() const;
};

inline std::ostream & operator<< (std::ostream & os, const MaszynaStanow & m)
{
    m.print(os);
    return os;
}
