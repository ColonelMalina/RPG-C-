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
	double getMana() { return Mana; }
	double getHealth() { return health; }
	void EquipW(Weapon newWeapon) {
		currentW = newWeapon;
		std::cout << Name << " now wields " << currentW.Wname << "." << std::endl;
	}
	void Attack(Enemies& target) {
		double hit = currentW.getPower();

		int roll = rand() % 100; 
		if (roll < currentW.critChance) {
			hit *= 1.5;
			std::cout << "\n\033[41m\033[97m *** CRITICAL HIT! *** \033[0m\n";
		}
		std::vector<std::string> attackMessages = {
		Name + " swings their " + currentW.Wname + " with pure rage!",
		Name + " lunges forward, striking with the " + currentW.Wname + ".",
		Name + " executes a precise strike using the " + currentW.Wname + ".",
		Name + " unleashes a devastating blow with their " + currentW.Wname + "!"
		};
		
		int randomIndex = rand() % attackMessages.size();

		std::cout << attackMessages[randomIndex] << std::endl;
		target.takeDamage(hit);

		if (currentW.dotTurns > 0) {
			target.applyDot(currentW.dotDamage, currentW.dotTurns);
		}
	}

	// FIREBALL
	double minF = 10;
	double maxF = 20;
	double fManaCost = 6;
	int fireballLevel = 1;
	int dotChance = 20;

	bool Fireball(Enemies& target) {
		if (Mana < fManaCost) {
			std::cout << "Not enough Mana! Need " << fManaCost << std::endl;
			return false;
		}
		double range = maxF - minF;
		double actualCast = minF + (rand() % (int)(range + 1));

		Mana -= fManaCost;
		std::cout << "You used Fireball Lvl " << fireballLevel << "!" << std::endl;
		std::cout << Name << " casts Fireball towards enemy for " << actualCast << ". (Mana: " << Mana << ")" << std::endl;
		
		target.takeDamage(actualCast);
		if (rand() % 100 < dotChance) {
			target.applyDot(5 + (fireballLevel * 2), 3); 
		}
		return true;
	}
	void upgradeFireball() {
		healLevel++;
		minF += 4;
		maxF += 9;
		fManaCost += 3;
		dotChance += 15;
		std::cout << "Fireball upgraded to Level " << fireballLevel << "!" << std::endl;
		std::cout << "New range: " << minF << " - " << maxF << "." << std::endl;
		std::cout << "New chance for applying fire: " << dotChance << "%." << std::endl;
	}

	// ICESPIKE
	double minI = 7;
	double maxI = 15;
	double iManaCost = 5;
	int icespikeLevel = 1;
	int freezeChance = 10;

	bool Icespike(Enemies& target) {
		if (Mana < fManaCost) {
			std::cout << "Not enough Mana! Need " << fManaCost << std::endl;
			return false;
		}
		double range = maxF - minF;
		double actualCast = minF + (rand() % (int)(range + 1));

		Mana -= fManaCost;
		std::cout << "You used Icespike Lvl " << icespikeLevel << "!" << std::endl;
		std::cout << Name << " casts Icespike towards enemy for " << actualCast << ". (Mana: " << Mana << ")" << std::endl;
		target.takeDamage(actualCast);
		if (rand() % 100 < freezeChance) {
			target.freeze(1);
		}
		return true;
	}
	void upgradeIce() {
		healLevel++;
		minI += 3;
		maxI += 7;
		iManaCost += 2;
		freezeChance += 10;
		std::cout << "Icespike upgraded to Level " << icespikeLevel << "!" << std::endl;
		std::cout << "New range: " << minI << " - " << maxI << "." << std::endl;
		std::cout << "new chance for freezing target: " << freezeChance << "%." << std::endl;
	}

	// HEAL
	double minH = 5.0;
	double maxH = 10.0;
	double hManaCost = 5.0;
	int healLevel = 1;
	int critChance = 5;

    bool Heal() {
		if (Mana < hManaCost) {
			std::cout << "Not enough Mana! Need " << hManaCost << std::endl;
			return false;
		}

		double range = maxH - minH;
		double actualHeal = minH + (rand() % (int)(range + 1));

		Mana -= hManaCost;
		if (rand() % 100 < critChance) {
			actualHeal *= 1.8; 
			std::cout << "\033[33m*** CRITICAL HEAL! ***\033[0m" << std::endl; 
		}
		health += actualHeal;

		if (health > maxHealth) health = maxHealth;
 
		std::cout << "You used Heal Lvl " << healLevel << "!" << std::endl;
		std::cout << "Recovered " << actualHeal << " HP. (Mana: " << Mana << ")" << std::endl;
		return true;
	}

	void upgradeHeal() {
		healLevel++;
		minH += 5;
		maxH += 8; 
		hManaCost += 2; 
		critChance += 5;
		std::cout << "Heal upgraded to Level " << healLevel << "!\n" << std::endl;
		std::cout << "New range: "<< minH <<" - " << maxH << "." << std::endl;
		std::cout << "New chance for critical heal: " << critChance << "%." << std::endl;
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


	bool unlockedIce = false;

	void learnIce() {
		unlockedIce = true;
		std::cout << "\n*** " << Name << " learned a new spell: ICESPIKE (Level 1)! ***\n";
		std::cout << "\n                  BASE DAMAGE: 8 - 15                         \n";
	}
	bool hasIce() {
		return unlockedIce;
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

	void upgradeMana(double amount) {
		maxMana += amount; 
		Mana = maxMana;
		std::cout << "Your mana is now " << maxMana << "!" << std::endl;
	}
};