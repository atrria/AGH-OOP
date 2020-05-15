#pragma once
#include <iostream>
#include "Node.h"

// klasa reprezentujaca liste cykliczna, zawiera wskazniki na poczatek i koniec oraz licznik elementow
class CyclicList
{
private:
	Node* _node_start;
	Node* _node_end;
	int counter;
public:
	// operator dodawania elementow na koniec listy
	CyclicList& operator<<(Node*);
	// konstruktor
	CyclicList() :_node_start(nullptr), _node_end(nullptr), counter(0) {}
	// destruktor
	~CyclicList();
	// konstruktor kopiujacy
	CyclicList(const CyclicList&);
	// funkcja zwracajaca wartosc licznika
	int count() const;
	// operator zwracajacy pierwszy wezel
	Node* operator()() const;
	// operator wypisujacy elementy listy
	friend std::ostream& operator<<(std::ostream&, const CyclicList&);
	// funkcja obracajaca liste do przodu
	CyclicList& rotate();
	// funkcja obracajaca liste do ty³u
	CyclicList& rotate_back();
};
std::ostream& operator<<(std::ostream&, const CyclicList&);
