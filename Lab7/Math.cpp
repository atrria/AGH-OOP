#include "Math.h"
#include <math.h>

double Sin::calc(double argument) const
{
	return sin(argument*mparameter);
}

Sin* Sin::clone() const
{
	return new Sin(*this);
}

double Quadratic::calc(double argument) const
{
	return ma*argument*argument+mb*argument+mc;
}

Quadratic* Quadratic::clone() const
{
	return new Quadratic(*this);
}

Quadratic* Quadratic::set_a(double a)
{
	ma = a;
	return this;
}
Quadratic* Quadratic::set_b(double b)
{
	mb = b;
	return this;
}

Derivative::Derivative(const Derivative& other)
{
	mdx = other.mdx;
	mfun = other.mfun->clone();
}

Derivative::~Derivative()
{
	delete mfun;
}

void Derivative::set_dx(double dx)
{
	mdx = dx;
}

double Derivative::calc(double argument) const
{
	return (mfun->calc(argument + mdx) - mfun->calc(argument - mdx)) / (2. * mdx);
}

Derivative* Derivative::clone() const
{
	return new Derivative(*this);
}

double Derivative::operator()(double argument) const
{
	return calc(argument);
}

Derivative& Derivative::operator=(const Derivative& other)
{
	mdx = other.mdx;
	delete mfun;
	mfun = other.mfun->clone();
	return *this;
}

