#pragma once
#include <string>
#include "Node.h"

// klasa reprezentuj¹ca wezel przechowujacy wartosc int
class NodeInt : public Node
{
private:
	int ival;
public:
	// konstruktor
	NodeInt(int i) :ival(i) {}
	// funkcja zwracajaca wartosc wezla
	int valInt() const;
	// funkcja zwracajaca wskaznik do kopii elementu
	NodeInt* clone() const override;
	// funkcja konwertujaca wartosc wezla typu int na string
	std::string toString() const override;
};

// klasa reprezentujaca wezel przechowujacy wartosc float
class NodeFloat : public Node
{
private:
	float fval;
public:
	// konstruktor
	NodeFloat(float f) :fval(f) {}
	// funkcja zwracajaca wartosc wezla
	float valFloat() const;
	// funkcja zwracajaca wskaznik do kopii elementu
	NodeFloat* clone() const override;
	// funkcja konwertujaca wartosc wezla typu float na string
	std::string toString() const override;
};

// klasa reprezentujaca wezel przechowujacy wartosc string
class NodeString : public Node
{
private:
	std::string sval;
public:
	// konstruktor
	NodeString(std::string s) :sval(s) {}
	// funkcja zwracajaca wartosc wezla
	std::string& valString();
	// funkcja zwracajaca wskaznik do kopii elementu
	NodeString* clone() const override;
	// funkcja zwracajaca wartosc wezla
	std::string toString() const override;
};
