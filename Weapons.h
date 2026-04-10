
#include <iostream>
#include <string>

class Weapon 
{
public:
	std::string Wname;
	double Damage;

	Weapon(std::string w = "Bare hands", int d = 2)
	{
		Wname = w;
		Damage = d;
	}

};