#pragma once
#include "Point.h"

// klasa pochodna klasy point
class LabeledPoint : public Point
{
private:
	// nazwa punktu
	std::string label;
public:
	// konstruktor korzystajacy z konstruktora point
	LabeledPoint(std::string label, int x, int y);
	// destruktor
	virtual ~LabeledPoint();
	// funkcja zwracajaca informacje o zawartosci obiektu
	std::string info() const override;
	// funkcja globalna ustawiajaca nazwe punktu
	friend void setName(Point* ptr, std::string s);
};

void setName(Point* ptr, std::string s);
