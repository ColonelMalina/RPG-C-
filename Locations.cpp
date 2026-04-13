#include "Locations.h"
#include "Hero.h"
#include "Enemies.h"
#include "Battle.h"
#include <iostream>

void abandonedMine(Hero& player) {
    std::cout << "\n--- ABANDONED MINE ---\n";
    std::cout << "The air is damp and smells of rot. You hear a terrifying squeak!\n";

    if (startBattle(player, new Rat())) {
        std::cout << "\nYou catch your breath. The rat was guarding an old magic scroll!\n";
        player.upgradeHeal();
        player.EquipW(Dagger());
    }
}

void goblinCamp(Hero& player) {
    std::cout << "\n--- GOBLIN CAMP ---\n";
    std::cout << "You sneak into a small clearing. A Goblin spots you and draws his rusty blade!\n";

    if (startBattle(player, new Goblin())) {
        std::cout << "\nYou search the camp and find some bandages and a Steel Sword.\n";
        player.regainMana();
        player.fullHeal();
        std::cout << "\nDo you want to equip the Steel Sword? \n1. YES/ 2. NO\n";
        int eq;
        std::cin >> eq;
        switch (eq) {
        case 1:
            player.EquipW(SteelSword());
            break;
        case 2:
            break; 
        }
    }
}

void deepCave(Hero& player) {
    std::cout << "\n--- DEEP CAVE ---\n";
    std::cout << "It's completely dark. Suddenly your path is blocked by massive rat!\n";

    if (startBattle(player, new Rat())) {
        std::cout << "\nAs you clear your sword after that fight you hear someone in the distance.\n";
        std::cout << "\nUnfortunately for you it is a Hungry Orc guarding a chest... Good luck!\n";
        player.regainMana();
    }
    if (startBattle(player, new Orc())) {
        std::cout << "\nThe chest looks filled with loot and some bandages!\n";
        player.fullHeal();
        std::cout << "\nDo you want to equip the Orcish Axe? \n1. YES/ 2. NO\n";
        int eq;
        std::cin >> eq;
        switch (eq) {
        case 1:
            player.EquipW(OrcAxe());
            break;
        case 2:
            break;
        };
    }
}