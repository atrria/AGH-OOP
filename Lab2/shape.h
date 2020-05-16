#pragma once
#include <iostream>
class Shape
{
public:
	Shape() {};
	virtual ~Shape() = default;
	virtual void print() const
	{
		std::cout << "";
	}
	static void print(const Shape& temp)
	{
		temp.print();
	}
	virtual double area() const
	{
		return 0.0;
	}
	void print(std::ostream& os) const
	{
		print();
	}
};

