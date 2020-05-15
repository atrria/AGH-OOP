#pragma once
#include "Function.h"

class Sin : public Function
{
private:
	double mparameter;
public:
	// konstruktor przyjmujacy parametr funkcji sinus
	Sin(double parameter) : mparameter(parameter) {}
	// prze³adoana funkcja obliczajaca sinusa postaci sin(a*x)
	~Sin() = default;
	double calc(double) const override;
	// funkcja zwracaj¹ca wskaŸnik na kopiê obiektu
	Sin* clone() const override;
};

class Quadratic : public Function
{
private:
	double ma;
	double mb;
	double mc;
public:
	// konstruktor przyjmujacy parametry funkcji kwadratowej
	Quadratic(double a, double b, double c) : ma(a), mb(b), mc(c) {}
	~Quadratic() = default;
	Quadratic(const Quadratic& r) = default;
	// funkcja ustawiaj¹ca parametr a
	Quadratic* set_a(double);
	// funkcja ustawiaj¹ca parametr b
	Quadratic* set_b(double);
	// prze³adoana funkcja obliczajaca wartoœæ funkcji kwadratowej ax^2+bx+c

	double calc(double) const override;
	// funkcja zwracaj¹ca wskaŸnik na kopiê obiektu
	Quadratic* clone() const override;
};

class Derivative : public Function
{
private:
	Function* mfun = nullptr;
	double mdx;
public:
	// konstruktor przyjmujacy wskaŸnik na funkcjê i krok dx
	Derivative(Function* fun, double dx) : mfun(fun->clone()), mdx(dx) {}
	~Derivative();
	// konstruktor kopiuj¹cy
	Derivative(const Derivative&);
	// funkcja ustawiaj¹ca krok dx
	void set_dx(double dx);
	// prze³adoana funkcja obliczajaca pochodne
	double calc(double) const override;
	// funkcja zwracaj¹ca wskaŸnik na kopiê obiektu
	Derivative* clone() const override;
	// prze³adowany operator () dzia³aj¹cy jak funkcja calc
	double operator()(double) const;
	Derivative& operator=(const Derivative&);
};