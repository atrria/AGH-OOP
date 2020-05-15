#pragma once
#include <string>

// klasa reprezentujaca wezel listy
class Node
{
public:
	Node* next;
	// konstruktor
	Node() :next(nullptr){}
	// funkcja zwracajaca wskaznik do kopii elementu
	virtual Node* clone() const = 0;
	// funkcja konwertujaca wartosc wezla na string
	virtual std::string toString() const = 0;
};
