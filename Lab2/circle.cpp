#include "circle.h"
Circle::Circle()
{
	r = 0;
}
Circle::Circle(int r)
{
	this->r = r;
}
void Circle::print() const
{
	std::cout << "Okrag o promieniu: " << r << std::endl;
}
double Circle::area() const
{
	return (double)r * r * 3.14;
}