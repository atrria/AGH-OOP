#include "FilterCriteria.h"
#include "List.h"

int FilterCriteria::size()
{
	return vec.size();
}

std::function<bool(int)> FilterCriteria::get(int i)
{
	return vec[i];
}

bool FilterCriteria::negative(int n)
{
	return (n < 0);
}

void FilterCriteria::add(std::function<bool(int x)> fun)
{
	vec.push_back(fun);
}
