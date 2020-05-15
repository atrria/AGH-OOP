#pragma once
#include <iostream>

class PredkoscMaksymalna
{
private:
	int mv;
public:
	PredkoscMaksymalna(int v) :mv(v){}
	int getvel() const
	{
		return mv;
	}
	std::ostream& operator<<(const PredkoscMaksymalna& v)
	{
		std::ostream& os(std::cout);
		return os<<v.mv;
	}
};

