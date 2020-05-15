#include "List.h"
#include<cmath>

void List::insert(int v)
{
	zbior.push_back(v);
}

void List::print(std::string s) const
{
	std::cout << s;
	std::cout << "[ ";
	for (int i = 0; i < abs(int(zbior.size())); i++)
	{
		std::cout << zbior[i] << " ";
	}
	std::cout << "]\n";
}

int& List::operator[](int i)
{
	return zbior[i];
}

void List::operator=(int v)
{
	zbior.push_back(v);
}

int List::size()
{
	return zbior.size();
}

List List::filter(std::function<bool(int x)> fun)
{
	List list;
	for (int i = 0; i < int(zbior.size()); i++)
	{
		if (fun(zbior[i]) == true)
		{
			list.zbior.push_back(zbior[i]);
		}
	}
	return list;
}
