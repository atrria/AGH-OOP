#pragma once
#include <functional>
#include<vector>

class List;

class FilterCriteria
{
public:
	std::vector<std::function<bool(int x)>> vec;
	friend class List;
	int size();
	std::function<bool(int)> get(int i);
	bool negative(int);
	void add(std::function<bool(int x)> fun);
};