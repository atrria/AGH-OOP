#pragma once
#include "Point.h"

// klasa reprezentujaca unikalny wskaznik
class UniquePtr
{
private:
	Point* p;

public:
	// konstruktor ustawiajacy obiekt point jako pusty
	UniquePtr(): p(nullptr) {}
	// konstruktor ustawiajacy obiekt point na przekazany p
	UniquePtr(Point* p): p(p) {}
	// konstruktor przenoszacy
	UniquePtr(UniquePtr&&);
	// destruktor
	~UniquePtr();
	// operator bool sprawdzajacy czy obiekt point jest nullptr
	operator bool() const;
	// operator przenoszacy
	UniquePtr& operator=(UniquePtr&&);
	// funkcja uwalniajaca wskaznik
	Point* release();
	// funkcja zwracajaca wskaznik na point
	Point* get() const;
	// operator *
	Point& operator*() const;
	// operator ->, wywoluje funkcje get()
	Point* operator->() const;
};