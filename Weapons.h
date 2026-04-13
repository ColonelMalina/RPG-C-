#pragma once
#include <iostream>
#include <string>

class Weapon
{
public:
    std::string Wname;
    double minDamage;
    double maxDamage;
    double dotDamage;  
    int dotTurns;     
    int critChance;    

    Weapon(std::string w = "Bare hands", double minD = 2, double maxD = 4, double dotD = 0, int dotT = 0, int critC = 2)
        : Wname(w), minDamage(minD), maxDamage(maxD), dotDamage(dotD), dotTurns(dotT), critChance(critC) {}

    double getPower() {
        double range = maxDamage - minDamage;
        return minDamage + (rand() % (int)(range + 1));
    }
};
Weapon Dagger();
Weapon SteelSword();
Weapon OrcAxe();
Weapon Halapartna();
Weapon BigAxe();
Weapon Elvensword();
Weapon Edagger();
Weapon HeavyMace();