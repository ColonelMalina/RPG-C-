#include "Battle.h"   
#include "Hero.h"     
#include "Enemies.h"  
#include <vector>
#include <iostream>

bool startBattle(Hero& player, Enemies* monster) {
    std::cout << "\n=== BATTLE START: " << player.getName() << " vs " << monster->getName() << " ===\n";

    while (player.isAlive() && monster->isAlive()) {
        bool turnOver = false;
        do {
            std::cout << "\n--- Your Turn ---" << std::endl;
            std::cout << "1. Attack | 2. Heal |";
            if (player.hasFireball()) std::cout << " 3. Fireball |";
            if (player.hasIce()) std::cout << " 4. Icespike |";
            if (player.gethPotion() > 0) std::cout << " 9. Potion (" << player.gethPotion() << "x)";

            std::cout << "\nSelect action: ";
            int choice;
            std::cin >> choice;
            if (choice == 9) {
                if (player.gethPotion() > 0) {
                    player.usehPotion();
                }
                else {
                    std::cout << "You don't have any potions!" << std::endl;
                }
                continue;
            }            else if (choice == 1) {
                player.Attack(*monster);
                turnOver = true;
            }
            else if (choice == 2) {
                if (player.Heal()) turnOver = true;
            }
            else if (choice == 3 && player.hasFireball()) {
                if (player.Fireball(*monster)) turnOver = true;
            }
            else if (choice == 4 && player.hasIce()) {
                if (player.Icespike(*monster)) turnOver = true;
            }
            else {
                std::cout << "Invalid choice or spell not learned!" << std::endl;
            }

        } while (!turnOver);


        if (monster->isAlive()) {
            monster->takeDotDamage();

            if (monster->isAlive()) {
                if (monster->isFrozen()) {
                    std::cout << monster->getName() << " is frozen and skips their turn!" << std::endl;
                }
                else {
                    player.takeDamage(monster->attackHero());
                }
            }
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


bool startMultiBattle(Hero& player, std::vector<Enemies*> enemies) {
    while (player.isAlive() && !enemies.empty()) {
        bool turnOver = false;
        do {
            std::cout << "\n--- ENEMIES ---" << std::endl;
            for (int i = 0; i < enemies.size(); i++) {
                std::cout << i + 1 << ". " << enemies[i]->getName() << std::endl;
            }

            std::cout << "\n--- Your Turn ---" << std::endl;
            std::cout << "1. Attack | 2. Heal |";
            if (player.hasFireball()) std::cout << " 3. Fireball |";
            if (player.hasIce()) std::cout << " 4. Icespike |";
            if (player.gethPotion() > 0) std::cout << " 9. Potion (" << player.gethPotion() << "x)";

            std::cout << "\nSelect action: ";
            int choice;
            std::cin >> choice;

            if (choice == 9) {
                if (player.gethPotion() > 0) {
                    player.usehPotion();
                }
                else {
                    std::cout << "You don't have any potions!" << std::endl;
                }
                continue; 
            }

            else if (choice == 2) {
                if (player.Heal()) turnOver = true;
            }
            else if (choice >= 1 && choice <= 4) {
                std::cout << "Select target (1-" << enemies.size() << "): ";
                int targetIdx;
                std::cin >> targetIdx;

                if (targetIdx > 0 && targetIdx <= enemies.size()) {
                    targetIdx--;
                    if (choice == 1) { player.Attack(*enemies[targetIdx]); turnOver = true; }
                    else if (choice == 3 && player.hasFireball()) { if (player.Fireball(*enemies[targetIdx])) turnOver = true; }
                    else if (choice == 4 && player.hasIce()) { if (player.Icespike(*enemies[targetIdx])) turnOver = true; }
                    else { std::cout << "Spell not learned!" << std::endl; }
                }
                else {
                    std::cout << "Invalid target!" << std::endl;
                }
            }
            else {
                std::cout << "Invalid action!" << std::endl;
            }

        } while (!turnOver);

        for (auto it = enemies.begin(); it != enemies.end(); ) {
            if (!(*it)->isAlive()) {
                std::cout << (*it)->getName() << " has been defeated!" << std::endl;
                delete* it;
                it = enemies.erase(it);
            }
            else {
                (*it)->takeDotDamage();
                if ((*it)->isAlive()) {
                    if (!(*it)->isFrozen()) {
                        player.takeDamage((*it)->attackHero());
                    }
                    else {
                        std::cout << (*it)->getName() << " is frozen and skips turn!" << std::endl;
                    }
                }
                ++it;
            }
        }

        std::cin.ignore(1000, '\n');
        std::cin.get();
    }

    bool won = player.isAlive();
    if (won) {
        std::cout << "\nVICTORY! All enemies have been defeated.\n";
    }
    else {
        std::cout << "\nGAME OVER... You died.\n";
    }

    return won;
}