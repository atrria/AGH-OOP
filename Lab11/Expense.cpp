#include "Expense.h"

void Expense::print() const
{
	std::cout << mstr << ":";
	std::for_each(mvec.begin(), mvec.end(), [](double n) { std::cout << std::setw(6) << n; });
	std::cout << std::endl;
}

double Expense::mean() const
{
	return (std::accumulate(mvec.begin(), mvec.end(), 0.) / mvec.size());
}

double Expense::operator[](unsigned column) const
{
	return mvec[column];
}
