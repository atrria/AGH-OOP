#include "Division.h"

void Division::print() const
{
 	std::cout << x << " / " << y;
}

double Division::eval() const
{
    return x/y;
}
