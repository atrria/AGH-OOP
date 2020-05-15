#pragma once
#include<iostream>
#include<vector>
#include<functional>

class List
{
private:
	std::vector<int> zbior;
public:
	void insert(int);
	void print(std::string s="") const;
	int& operator[](int);
	void operator=(int);
	int size();
	List filter(std::function < bool(int) > fun);
};