#include "Battle.h"   // Přiložíme náš vlastní jídelní lístek
#include "Hero.h"     // Tady už potřebujeme vědět, jak hrdina vypadá
#include "Enemies.h"  // A jak vypadá nepřítel
#include <iostream>

bool startBattle(Hero& player, Enemies* monster) {
    std::cout << "\n=== BATTLE START: " << player.getName() << " vs " << monster->getName() << " ===\n";

    while (player.isAlive() && monster->isAlive()) {
        std::cout << "\n--- Your Turn ---" << std::endl;
        std::cout << "1. Attack\n2. Heal (5 mana)\n";
        if (player.hasFireball()) {
        std::cout << "3. Fireball (10 Mana)\n";
        }
        
        std::cout<<"Select action : ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            player.Attack(*monster);
        }
        else if (choice == 2)
        {
            player.Heal();
        }
        else if (choice == 3 && player.hasFireball()) {
            player.Fireball(*monster);
        }

        if (monster->isAlive()) {
            double dmg = monster->attackHero();
            player.takeDamage(dmg);
        }

        std::cin.ignore(1000, '\n');
        std::cin.get();
    }

    bool won = player.isAlive();
    if (won) {
        std::cout << "\nVICTORY! The " << monster->getName() << " is dead.\n";
    }
    else {
        std::cout << "\nGAME OVER... You died.\n";
    }

    delete monster;
    return won;
}