using namespace std;
#include <iostream>
#include <string>

class Enemy
{
	string Name;
	double Health;

public:

	Enemy(string n, double h) : Name(n), Health(h) {}

	void attackE();
	//void Heal();
	void takeDamage();



};
class Rat : Enemy
{

};
class Goblin : Enemy
{

};

class Orc : Enemy 
{

};
