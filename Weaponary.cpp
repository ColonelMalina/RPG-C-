#include "Weapons.h"

// Tady tvoříš konkrétní zbraně
Weapon Dagger() {
    return Weapon("Rusty Dagger", 5, 8);
}

Weapon SteelSword() {
    return Weapon("Steel Sword", 12, 18); 
}

Weapon OrcAxe() {
    return Weapon("Heavy Orcish Axe", 15, 30); 
}