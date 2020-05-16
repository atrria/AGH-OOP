#include "InfoClass.h"

InfoClass::InfoClass(std::string info2)
{
	this->informacja = info2;
}

InfoClass::~InfoClass()
{
	std::cout << "-- Usuwam obiekt InfoClass: info = " << informacja;
}
std::string InfoClass::info() const
{
	return ("** printfInfo: info = "+informacja);
}