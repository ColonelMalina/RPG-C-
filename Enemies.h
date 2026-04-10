#pragma once
#include <iostream>
#include <string>
class Hero; 
class Enemies {

protected:
    std::string Name;
    double Health;
    double minD;
    double maxD;

public:
    Enemies(std::string n, double h, double min, double max ) : Name(n), Health(h), minD(min), maxD(max) {}

    double getAttackPower() {
        double range = maxD - minD;
        return minD + (rand() % (int)(range + 1));
    }
    void takeDamage(double amount) {
        Health -= amount;
        if (Health < 0) Health = 0;
        std::cout << Name << " takes " << amount << " damage! Remaining HP: " << Health << std::endl;
    }
    double attackHero() {
        double damage = getAttackPower();
        std::cout << Name << " attacks for " << damage << " damage!" << std::endl;
        return damage;
    }
    bool isAlive() { return Health > 0; }
    std::string getName() { return Name; }
};
class Rat : public Enemies{
public:
    Rat() : Enemies("Rat", 15, 3, 5) {}

};
class Goblin : public Enemies {
public:
    Goblin() : Enemies("Goblin", 30, 7, 10) {}
};

class Orc : public Enemies {
public:
    Orc() : Enemies("Orc", 60, 13, 31) {}
};
class Orc2 : public Enemies {
public:
    Orc2() : Enemies("Shaman Orc", 40, 25, 40) {}
};