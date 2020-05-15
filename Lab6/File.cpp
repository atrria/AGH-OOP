#include "File.h"

void File::print()
{
	++size;
	std::cout << name << "\n";
}

void File::rename(std::string name)
{
	this->name = name;
}
