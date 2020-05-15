#pragma once
#include<iostream>
#include<vector>
#include"File.h"

class Directory : public File
{
private:
	std::vector<File*> subdirs;
	//int size;
public:
	Directory(std::string name): File(name, 1) {}
	~Directory();
	Directory* clone() const;
	virtual void print() override;
	void operator/(File* file);
	void copy(File* file);
};

