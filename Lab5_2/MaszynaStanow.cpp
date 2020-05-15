#include "MaszynaStanow.h"

MaszynaStanow::~MaszynaStanow() {}

MaszynaStanow& MaszynaStanow::operator+=(Stan* st)
{
    st->setMS(this);
    m_states.push_back(st);
    return *this;
}

Stan& MaszynaStanow::operator()()
{
    return *m_states[m_current];
}

void MaszynaStanow::start()
{
    std::cout << "Rozpoczynamy dzialanie maszyny stanow!" << std::endl;
    m_current = 0;
}

void MaszynaStanow::operator++()
{
    if(m_current < m_states.size() - 1)
    {
        ++m_current;
    }
}
void MaszynaStanow::operator--()
{
    if(m_current > 0)
    {
        --m_current;
    }
}

void MaszynaStanow::print(std::ostream& ostr) const
{
    for(unsigned int i = 0; i<m_states.size(); ++i)
    {
        if( i == m_current )
        {
            std::cout << ">" << m_states[i]->nazwa() << "< ";
        }
        else
        {
            std::cout << m_states[i]->nazwa() << " ";
        }
    }
}

void MaszynaStanow::podsumowanie() const
{
    for(unsigned int i = 0; i<m_states.size(); ++i)
    {
        m_states[i]->podsumowanie();
    }
}