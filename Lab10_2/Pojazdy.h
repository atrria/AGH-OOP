#pragma once
#include <string>
#include "Predkosc.h"

class Pojazd
{
private:
	std::string plates;
public:
	Pojazd() = default;
	Pojazd(const std::string& pl) :plates(pl) {}
	virtual ~Pojazd() = default;
	friend std::ostream& operator<<(std::ostream& os, const Pojazd& p);
};
std::ostream& operator<<(std::ostream& os, const Pojazd& p)
{
	return os<<p.plates;
}

class PojazdLadowy : public virtual Pojazd
{
private:
	PredkoscMaksymalna vel;
public:
	PojazdLadowy(const std::string& pl, PredkoscMaksymalna v) :Pojazd(pl), vel(v){}
	PojazdLadowy(PredkoscMaksymalna v) :vel(v) {}
	int predkoscMaksymalna() const
	{
		return vel.getvel();
	}
};

class PojazdWodny : public virtual Pojazd
{
private:
	PredkoscMaksymalna vel;
public:
	PojazdWodny(const std::string& pl, PredkoscMaksymalna v) :Pojazd(pl), vel(v) {}
	PojazdWodny(PredkoscMaksymalna v) :vel(v) {}
	int predkoscMaksymalna() const
	{
		return vel.getvel();
	}
};

class Samochod : public PojazdLadowy
{
public:
	Samochod(const std::string& pl, PredkoscMaksymalna v):PojazdLadowy(pl, v){}
};

class Rower : public PojazdLadowy
{
public:
	Rower(const std::string& pl) :PojazdLadowy(pl, 0) {}
};

class Motorowka : public PojazdWodny
{
public:
	Motorowka(const std::string& pl, PredkoscMaksymalna v) :PojazdWodny(pl, v) {}
};

class Amfibia : public Pojazd
{
private:
	PredkoscMaksymalna mv1;
	PredkoscMaksymalna mv2;
public:
	Amfibia(const std::string& pl, PredkoscMaksymalna v1, PredkoscMaksymalna v2) : Pojazd(pl), mv1(v1), mv2(v2) {}
	int predkoscMaksymalna_Lad() const
	{
		return mv1.getvel();
	}
	int predkoscMaksymalna_Woda() const
	{
		return mv2.getvel();
	}
};
