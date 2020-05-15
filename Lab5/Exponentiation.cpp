#include "Exponentiation.h"

void Exponentiation::print() const
{
	std::cout << x << " ^ " << n;
}
double Exponentiation::eval() const
{
	return pow(x, n);
}