#include "triangle.h"

Triangle::Triangle()
{
	a = 0;
	b = 0;
	c = 0;
}
Triangle::Triangle(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
void Triangle::print() const
{
	std::cout << "Trojkat o bokach: " << a << " " << b << " " << c << std::endl;
}
double Triangle::area() const
{
	double x = (a + b + c) / 2;
	return sqrt(x * (x - a) * (x - b) * (x - c));
}