#pragma once
#include<iostream>

class File
{
protected:
	std::string name;
	int size;
public:
	File(std::string name, int size=1):name(name), size(size){}
	virtual ~File() = default;
	virtual void print();
	void rename(std::string);
};