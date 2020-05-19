#pragma once
#include <string>

class Log10
{
public:
	Log10() = default;
    	~Log10() = default;
	double calc(double) const;
	std::string name() const { return "log10"; }
};

class Asin
{
public:
	Asin() = default;
	~Asin() = default;
	double calc(double) const;
	std::string name() const { return "arcsin"; }
};

class Legendre
{
private:
	int _n;
public:
	Legendre(): _n(0){}
	Legendre(int n):_n(n){}
	~Legendre() = default;
	double calc(double) const;
	std::string name() const { return "Legendre polynomial"; }
};

