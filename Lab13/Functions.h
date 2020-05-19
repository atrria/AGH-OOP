#pragma once
#include <string>

// czysto wirtualna klasa do obsługi funkcji matematycznych - interfejs
class Function
{
public:
    // domyślny destruktor wirtualny
    virtual ~Function() = default;
    // funkcja wirtualna obliczająca wartość funkcji matematycznej dla danego argumentu
	virtual double calc(double) const = 0;
	// funkcja wirtualna zwracająca nazwę funkcji matematycznej dla której została wywołana
	virtual std::string name() const = 0;
};

// klasa reprezentująca logarytm o podstawie 10, dziedzicząca po klasie Function
class Log10 : public Function
{
public:
    // domyślny konstruktor
    Log10() = default;
    // domyślny destruktor
    ~Log10() = default;
    // funkcja obliczająca wartość funkcji log10 dla danego argumentu
	double calc(double) const override;
	// funkcja zwracająca nazwę funkcji matematycznej
	std::string name() const override
	{
		return "log10";
	}
};

// klasa reprezentująca arcsin, dziedzicząca po klasie Function
class Asin : public Function
{
public:
    // domyślny konstruktor
    Asin() = default;
    // domyślny destruktor
    ~Asin() = default;
    // funkcja obliczająca wartość funkcji arcsin dla danego argumentu
	double calc(double) const override;
	// funkcja zwracająca nazwę funkcji matematycznej
	std::string name() const override
	{
		return "arcsin";
	}
};

// klasa reprezentująca wielomian Legendre'a, dziedzicząca po klasie Function
class Legendre : public Function
{
private:
	int _n;
public:
    // konstruktor
    Legendre(): _n(0){}
    // konstruktor ustawiający wartość zmiennej składowej
	Legendre(int n): _n(n){}
	// domyślny destruktor
    ~Legendre() = default;
    // funkcja obliczająca wartość wielomianu Legendre'a dla danego argumentu
	double calc(double) const override;
	// funkcja zwracająca nazwę funkcji matematycznej
	std::string name() const override
	{
		return "Legendre polynomial";
	}
};

