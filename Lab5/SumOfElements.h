#pragma once
#include "Operation.h"

class SumOfElements : public Operation
{
private:
	double* tab;
	int n;
public:
	SumOfElements(double* tab, int n): tab(tab), n(n) {}
	void print() const override;
	double eval() const override;
};