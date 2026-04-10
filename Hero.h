#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Weapons.h"
#include "Enemies.h"


class Hero
{
	std::string Name;
	double health;
	double maxHealth;
	double Mana;
	Weapon currentW;

public:

	Hero(std::string n, double h, double m) : Name(n), health(h), maxHealth(h), Mana(m) {}

	bool isAlive() { return health > 0; }
	std::string getName() { return Name; }

	void EquipW(Weapon newWeapon) {
		currentW = newWeapon;
		std::cout << Name << " now wields " << currentW.Wname << "." << std::endl;
	}
	void Attack(Enemies& target) {
		double hit = currentW.getPower();
		srand(time(0));

		std::vector<std::string> attackMessages = {
		Name + " swings their " + currentW.Wname + " with pure rage!",
		Name + " lunges forward, striking with the " + currentW.Wname + ".",
		Name + " executes a precise strike using the " + currentW.Wname + ".",
		Name + " unleashes a devastating blow with their " + currentW.Wname + "!"
		};
		
		int randomIndex = rand() % attackMessages.size();

		std::cout << attackMessages[randomIndex] << std::endl;
		target.takeDamage(hit);
	}
	double minH = 5.0;
	double maxH = 10.0;
	double hManaCost = 5.0;
	int healLevel = 1;

    void Heal() {
		if (Mana < hManaCost) {
			std::cout << "Not enough Mana! Need " << hManaCost << std::endl;
			return;
		}

		double range = maxH / minH;
		double actualHeal = minH + (rand() % (int)(range + 1));

		Mana -= hManaCost;
		health += actualHeal;

		if (health > maxHealth) health = maxHealth;

		std::cout << "You used Heal Lvl " << healLevel << "!" << std::endl;
		std::cout << "Recovered " << actualHeal << " HP. (Mana: " << Mana << ")" << std::endl;
	}

	void upgradeHeal() {
		healLevel++;
		minH += 5;
		maxH += 8; 
		hManaCost += 2; 
		std::cout << "Heal upgraded to Level " << healLevel << "!" << std::endl;
	}

	void takeDamage(double amount) {
		health -= amount;
		if (health <= 0) health = 0;
		std::cout << "You took " << amount << " damage!" << std::endl;
	}


};