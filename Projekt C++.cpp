#include <iostream>
#include <ctime>
#include "Hero.h"
#include "Enemies.h"
#include "Weapons.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));


    Hero player("Arthur", 100, 20);
    Weapon sword("Soldier's Sword", 10, 15);
    player.EquipW(sword);

    Enemies* monster = new Goblin();

    // Cycle for battle 
    std::cout << "=== BATTLE START: " << player.getName() << " vs " << monster->getName() << " ===\n";

    while (player.isAlive() && monster->isAlive()) {
        std::cout << "\n--- Your Turn ---" << std::endl;
        std::cout << "1. Attack\n2. Heal\nSelect action: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            player.Attack(*monster);
        }
        else if (choice == 2) {
            player.Heal();
        }
        if (monster->isAlive()) {
            double dmg = monster->attackHero(); 
            player.takeDamage(dmg);            
        }

        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
        if (player.isAlive()) {
            std::cout << "\nVICTORY! The " << monster->getName() << " is dead.\n";
        }
        else {
            std::cout << "\nGAME OVER... You died.\n";
        }
        delete monster;
    // Cycle for battle 

        return 0; 
}
