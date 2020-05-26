#pragma once
#include <iostream>

// klasa reprezentuj¹ca samochód o konkretnej marce
class Car
{
private:
	// marka samochodu
	std::string mName;
public:
	// konstruktor domyœlny
	Car() = default;
	// konstruktor przypisuj¹cy nazwê marki
	Car(std::string name) : mName(name) {}
	// funkcja wypisuj¹ca markê samochodu
	void print() const
	{
		std::cout << "Car: " << mName << std::endl;
	}
};