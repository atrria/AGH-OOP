#include "Table.h"

void Table::operator+=(const Expense& expense)
{
	mtable.push_back(expense);
}

void Table::print() const
{
	std::for_each(mtable.begin(), mtable.end(), [](const Expense& expense) { return expense.print(); });
	std::cout << std::endl;
}

Table& Table::sort(unsigned column)
{
	if (column < mtable.size())
	{
		std::sort(mtable.begin(), mtable.end(), [&column](const Expense& exp1, const Expense& exp2) { return (exp1[column] < exp2[column]); });
		return *this;
	}
	std::cout << "Indeks " << column << " nieprawidlowy!" << std::endl;
	return *this;
}

Table& Table::sortByMean()
{
	std::sort(mtable.begin(), mtable.end(), [](const Expense& exp1, const Expense& exp2) { return (exp1.mean() < exp2.mean()); });
	return *this;
}
