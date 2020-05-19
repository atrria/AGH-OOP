#pragma once
#include <iostream>
#include "Functions.h"

namespace SecureCalc
{
	template <class T>
	void run(const T& fun, double value)
	{
		std::cout << "--- Calculation: " << fun.name() << "(" << value << ")" << std::endl;
		try
		{
			std::cout << "==> result: " << fun.calc(value) << std::endl;
		}
		catch (std::domain_error e)
		{
			std::cout << "failed: " << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "failed: unspecified exception" << std::endl;
		}
	}
}

