#pragma once
#include <string>
#include <iostream>
/*
			GameObj
			   /\
			  /  \
			 /    \
	  Character  Hurting
	      /\        /\
		 /  \      /  \
		/    \    /    \
	Player    Boss     Bomb

*/

class HP
{
private:
	int _hp;
public:
	HP(int hp) : _hp(hp) {}
	std::string to_str() const
	{
		return "[" + std::to_string(_hp) + "HP]";
	}
};

class GameObj
{
private:
	std::string idd;
public:
	GameObj(const std::string& id):idd(id){}
	virtual ~GameObj()=default;
	std::string id() const
	{
		return idd;
	}
	virtual void print(std::ostream& os) const {};
	friend std::ostream& operator<< (std::ostream& os, const GameObj& go);
};
std::ostream& operator<< (std::ostream& os, const GameObj& go)
{
	go.print(os);
	return os;
}

class Hurting : virtual public GameObj
{
private:
	HP hpp;
public:
	Hurting(HP hp) : hpp(hp), GameObj("") {}
	std::string hp() const
	{
		return hpp.to_str();
	}
};

class Character : virtual public GameObj
{
private:
	std::string name;
	HP hpp;
public:
	Character(HP hp, const std::string& name): hpp(hp), name(name), GameObj("") {}
	std::string hp() const
	{
		return hpp.to_str();
	}
};

class Player : public Character
{
public:
	Player(HP hp, const std::string& name, const std::string& id) :Character(hp, name), GameObj(id) {}
};

class Bomb : public Hurting
{
public:
	Bomb(HP hp, const std::string& id) : Hurting(hp), GameObj(id) {}
};

class Boss : public Character, public Hurting
{
public:
	Boss(HP hp, const std::string& name, HP hp2, const std::string& id):Character(hp, name), Hurting(hp2), GameObj(id){}
};

