#pragma once
#include <iostream>
#include <string>

class Weapon
{
public:
    std::string Wname;
    double minDamage;
    double maxDamage;

    Weapon(std::string w = "Bare hands", double minD = 2, double maxD = 4)
        : Wname(w), minDamage(minD), maxDamage(maxD) {}

    double getPower() {
        double range = maxDamage - minDamage;
        return minDamage + (rand() % (int)(range + 1));
    }
};