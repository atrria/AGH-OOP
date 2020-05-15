#pragma once
#include <string>		// std::string
#include <vector>		// std::vector
#include <iostream>		// std::cout
#include <iomanip>		// std::setw
#include <functional>	// std::bind
#include <algorithm>	// std::for_each, std::sort
#include <numeric>		// std::accumulate

//klasa reprezentujaca wydatki, przechowujaca dzien tygodnia i kwoty
class Expense
{
private:
	// lancuch przechowujacy dzien tygodnia
	std::string mstr;
	// wektor kwot
	std::vector<double> mvec;

public:
	// konstruktor domyslny
	Expense() = default;
	// destruktor domyslny
	~Expense() = default;
	// konstruktor ustawiajacy dzien i kwoty
	Expense(const std::string& str, const std::vector<double>& vec) :mstr(str), mvec(vec) {}
	// funkcja wypisujaca dzien i kwoty, korzystajaca z std::setw() do uzyskania odstepow pomiedzy elementami
	void print() const;
	// funkcja obliczajaca srednia poprzez podzielenie wartosci zwroconej przez funkcje sumujaca std::accumulate przez ilosc elementow
	double mean() const;
	// przeladowanie operatora [] na potrzeby funkcji compare, zwraca element wektora
	double operator[](unsigned) const;
};
