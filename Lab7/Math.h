#pragma once
#include "Function.h"

class Sin : public Function
{
private:
	double mparameter;
public:
	// konstruktor przyjmujacy parametr funkcji sinus
	Sin(double parameter) : mparameter(parameter) {}
	// prze�adoana funkcja obliczajaca sinusa postaci sin(a*x)
	~Sin() = default;
	double calc(double) const override;
	// funkcja zwracaj�ca wska�nik na kopi� obiektu
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
	// funkcja ustawiaj�ca parametr a
	Quadratic* set_a(double);
	// funkcja ustawiaj�ca parametr b
	Quadratic* set_b(double);
	// prze�adoana funkcja obliczajaca warto�� funkcji kwadratowej ax^2+bx+c

	double calc(double) const override;
	// funkcja zwracaj�ca wska�nik na kopi� obiektu
	Quadratic* clone() const override;
};

class Derivative : public Function
{
private:
	Function* mfun = nullptr;
	double mdx;
public:
	// konstruktor przyjmujacy wska�nik na funkcj� i krok dx
	Derivative(Function* fun, double dx) : mfun(fun->clone()), mdx(dx) {}
	~Derivative();
	// konstruktor kopiuj�cy
	Derivative(const Derivative&);
	// funkcja ustawiaj�ca krok dx
	void set_dx(double dx);
	// prze�adoana funkcja obliczajaca pochodne
	double calc(double) const override;
	// funkcja zwracaj�ca wska�nik na kopi� obiektu
	Derivative* clone() const override;
	// prze�adowany operator () dzia�aj�cy jak funkcja calc
	double operator()(double) const;
	Derivative& operator=(const Derivative&);
};