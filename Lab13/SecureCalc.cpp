#include "SecureCalc.h"

void SecureCalc::run(const Function& fun, double value)
{
	std::cout << "--- Calculation: " << fun.name() << "(" << value << ")" << std::endl;
	
	try
	{
		std::cout << "==> result: " << fun.calc(value) << std::endl;
	}
	catch (std::domain_error e_domain)
	{
		std::cout << "failed: " << e_domain.what()<<std::endl;
	}
	catch (...)
	{
		std::cout << "failed: unknown type of exception\n";
	}
}
