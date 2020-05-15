#pragma once
#include "Operation.h"
#include <cmath>

class Exponentiation : public Operation
{
private:
	double x;
	double n;
public:
	Exponentiation(double x, double n): x(x), n(n) {}
	void print() const override;
	double eval() const override;
};