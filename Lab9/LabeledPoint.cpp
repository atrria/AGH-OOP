#include "LabeledPoint.h"

LabeledPoint::LabeledPoint(std::string label, int x, int y): Point(x,y),label(label)
{
	std::cout << "++ Tworze punkt o nazwie: "<<label<<std::endl;
}

LabeledPoint::~LabeledPoint()
{
	std::cout << "-- Usuwam punkt o nazwie: " << label<<std::endl;
}

std::string LabeledPoint::info() const
{
	std::string s = this->Point::info();
	return s + " -- " + label;
}

void setName(Point* ptr, std::string s)
{
	dynamic_cast<LabeledPoint*>(ptr)->label = s;
}
