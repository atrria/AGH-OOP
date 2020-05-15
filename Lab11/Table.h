#pragma once
#include "Expense.h"

// klasa reprezentujaca tablice wydatkow za pomoca wektora obiektow Expense
class Table
{
private:
	// wektor wydatkow
	std::vector<Expense> mtable;

public:
	// konstruktor domyslny
	Table() = default;
	// destruktor domyslny
	~Table() = default;
	// przeladowanie operatora += dopisujace kolejny rekord wydatkow
	void operator+=(const Expense&);
	// funkcja wypisujaca tablice wydatkow przy uzyciu istniejacej funkcji print z klasy Expense
	void print() const;
	// funkcja sortujaca rosnaco elementy po podanej kolumnie, korzystajaca z funkcji compare
	Table& sort(unsigned);
	// funkcja sortujaca rosnaco elementy po sredniej z kolumn, korzystajaca z funkcji compareMean
	Table& sortByMean();
};

