#include "SumOfElements.h"
void SumOfElements::print() const
{
    std::cout << tab[0];
    for (int i = 1; i < n; i++)
    {
        std::cout << " + " << tab[i];
    }
}

double SumOfElements::eval() const
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += tab[i];
    }
    return sum;
}
