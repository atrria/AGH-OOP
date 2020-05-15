#include "Directory.h"

Directory::~Directory()
{
}

Directory* Directory::clone() const
{
	return new Directory(*this);
}

void Directory::print()
{
	std::cout << name <<"/\n";
	for (int i = 0; i < subdirs.size(); i++)
	{
		for(int i=0; i<size; i++)
		std::cout << "__";
		subdirs[i]->print();
	}
	//size++;
}

void Directory::operator/(File* file)
{
	//++size;
	subdirs.push_back(file);
}

void Directory::copy(File* file)
{
	clone();
	subdirs.push_back(file);
}

