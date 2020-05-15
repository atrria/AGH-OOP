#include "Operation.h"

void operator>>=(const std::string& s, const Operation& op)
{
	std::cout << s << " ";
	op.print();
	std::cout << " " << s << "\n";
}
