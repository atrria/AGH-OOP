#include "shape.h"
class Rectangle : public Shape
{
private:
	int a;
	int b;
public:
	Rectangle();
	Rectangle(int, int);
	void print() const;
	double area() const;
};
