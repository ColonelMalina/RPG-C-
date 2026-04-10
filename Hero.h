#include <vector>
#include <iostream>
#include <string>
#include "Weapons.h"
#include "Enemies.h"
class Enemies;

class Hero 
{
	std::string Name;
	double health;
    double maxHealth;
	double Mana;
	Weapon currentW;

public:

	Hero(std::string n, double h, double m) : Name(n), health(h), maxHealth(h), Mana(m) {}

	void EquipW(Weapon newWeapon) {
		currentW = newWeapon;
		std::cout << Name << " now wields " << currentW.Wname << "." << std::endl;
	}
	void Attack(Enemies& tagret) {
		double hit = currentW.getPower();

		std::vector<std::string> attackMessages = {
		Name + " swings their " + currentW.Wname + " with pure rage!",
		Name + " lunges forward, striking with the " + currentW.Wname + ".",
		Name + " executes a precise strike using the " + currentW.Wname + ".",
		Name + " unleashes a devastating blow with their " + currentW.Wname + "!"
		};
		// Pick a random index from 0 to 3
		int randomIndex = rand() % attackMessages.size();

		std::cout << attackMessages[randomIndex] << std::endl;
		target.takeDamage(hit);
	}
	void Heal(double amount) {
		health += amount;
		if (health >= maxHealth) health = maxHealth;
	    std::cout << Name << "You healed for" << amount << std::endl;
			
	}
	void takeDamage(double amount) {
		health -= amount;
		if (health <= 0) health = 0;
		std::cout << Name << "You took" << amount << "damage!" << std::endl;
	}


};