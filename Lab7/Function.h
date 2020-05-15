#pragma once
class Function
{
public:
	virtual ~Function() = default;
	virtual Function* clone() const = 0;
	virtual double calc(double) const = 0;
};

