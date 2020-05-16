#include "shape.h"
#include <iostream>
#include <math.h>
class Triangle : public Shape
{
private:
	int a;
	int b;
	int c;
public:
	Triangle();
	Triangle(int, int, int);
	void print() const;
	double area() const;
};

