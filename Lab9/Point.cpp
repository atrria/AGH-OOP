#include "Point.h"

Point::Point(int x, int y) :x(x), y(y)
{
	std::cout << "++ Tworze punkt (" << x << ", " << y << ")"<<std::endl;
}

Point::~Point()
{
	std::cout << "-- Usuwam punkt (" << x << ", " << y << ")" << std::endl;
}

std::string Point::info() const
{
	return "pkt " + std::to_string(x) + ", " + std::to_string(y);
}

