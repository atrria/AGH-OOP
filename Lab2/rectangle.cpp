#include "rectangle.h"
Rectangle::Rectangle()
{
	a = 0;
	b = 0;
}
Rectangle::Rectangle(int a, int b)
{
	this->a = a;
	this->b = b;
}
void Rectangle::print() const
{
	std::cout << "Prostokat o bokach: " << a << " " << b << std::endl;
}
double Rectangle::area() const
{
	return (double)a * b;
}

