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
	double maxMana;
	Weapon currentW;

public:

	Hero(std::string n, double h, double m) : Name(n), health(h), maxHealth(h), maxMana(m), Mana(m) {}

	bool isAlive() { return health > 0; }
	std::string getName() { return Name; }

	void EquipW(Weapon newWeapon) {
		currentW = newWeapon;
		std::cout << Name << " now wields " << currentW.Wname << "." << std::endl;
	}
	void Attack(Enemies& target) {
		double hit = currentW.getPower();

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
	double minS = 10;
	double maxS = 20;
	double sManaCost = 6;
	int fireballLevel = 1;

	void Fireball(Enemies& target) {
		if (Mana < sManaCost) {
			std::cout << "Not enough Mana! Need " << sManaCost << std::endl;
			return;
		}
		double range = maxS - minS;
		double actualCast = minS + (rand() % (int)(range + 1));

		Mana -= sManaCost;
		std::cout << "You used Fireball Lvl " << fireballLevel << "!" << std::endl;
		std::cout << Name << " casts Fireball towards enemy for " << actualCast << ". (Mana: " << Mana << ")" << std::endl;
		target.takeDamage(actualCast);
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

		double range = maxH - minH;
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
		std::cout << "Heal upgraded to Level " << healLevel << "!\n" << std::endl;
		std::cout << "New range: "<< minH <<" - " << maxH << "." << std::endl;
	}
	void upgradeFireball() {
		healLevel++;
		minS += 4;
		maxS += 9;
		sManaCost += 3;
		std::cout << "Fireball upgraded to Level " << fireballLevel << "!" << std::endl;
		std::cout << "New range: " << minS << " - " << maxS << "." << std::endl;
	}
	bool unlockedFireball = false; 

	void learnFireball() {
		unlockedFireball = true;
		std::cout << "\n*** " << Name << " learned a new spell: FIREBALL (Level 1)! ***\n";
		std::cout << "\n                  BASE DAMAGE: 10 - 20                         \n";
	}
	bool hasFireball() {
		return unlockedFireball;
	}
	void regainMana() {
		Mana = maxMana;
		std::cout << "You regained your mana back!" << std::endl;
	}
	void fullHeal() {
		health = maxHealth;
		std::cout << "You regained full health!" << std::endl;
	}

	void takeDamage(double amount) {
		health -= amount;
		if (health <= 0) health = 0;
		std::cout << "You took " << amount << " damage!" << std::endl;
	}


};