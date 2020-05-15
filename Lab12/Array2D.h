#pragma once
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "BadDimsException.h"

class Array2D
{
private:
	int* arr=nullptr;
	int mDim1;
	int mDim2;
public:
	Array2D(int dim1, int dim2) :mDim1(dim1), mDim2(dim2)
	{
		int size = mDim1 * mDim2;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = i + 1;
		}
	}
	~Array2D()
	{
	    delete [] arr;
	}
	void print() const;
	friend std::ostream& operator<<(std::ostream&, const Array2D&);
	void reshape(int, int);
	int* operator[](int);
	int& at(int, int);
	int at(int, int) const;
	Array2D& operator=(Array2D&);
};

std::ostream& operator<<(std::ostream&, const Array2D&);
