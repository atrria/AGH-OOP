#pragma once
#include <iostream>
#include "Functions.h"

// klasa obsługująca wywołanie funkcji run i wyjątki
class SecureCalc
{
public:
    // funkcja próbująca wywołać zadaną funkcję matematyczną z podanym parametrem
	static void run(const Function&, double);
};
