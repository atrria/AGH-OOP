#include "shape.h"
class Circle : public Shape
{
private:
	int r;
public:
	Circle();
	Circle(int);
	void print() const;
	double area() const;
};
