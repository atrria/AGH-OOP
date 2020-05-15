#pragma once
#include "Operation.h"

class Division : public Operation
{
private:
	double x;
	double y;
public:
	Division(int x, int y): x(x), y(y) {}
	void print() const override;
	double eval() const override;
};