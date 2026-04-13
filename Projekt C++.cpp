#include <iostream>
#include <ctime>
#include "Hero.h"
#include "Enemies.h"
#include "Weapons.h"
#include "Battle.h"
#include "Locations.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "\n============================================\n";
    std::cout << "       WELCOME TO THE CONSOLE LAND \n";
    std::cout << "============================================\n";
    
    std::string playerName;
    std::cout << "Enter your hero's name: ";
    std::getline(std::cin, playerName);

    Hero player(playerName, 100, 30);
    Weapon barehands;
    player.EquipW(barehands);

    std::cout << "\nWelcome, " << player.getName() << "!\n";
    std::cout << "You appeard at a crossroads. You don't know how you got here.\n";
    std::cout << "Three paths lie before you.\n";
    std::cout << "\n1. Take the Left Path (Abandoned Mine - Easy)\n";
    std::cout << "2. Go straight (Goblin Camp - Medium)\n";
    std::cout << "3. Take the Right Path (Deep Cave - Hard)\n";
    std::cout << "Choose your destiny (1-3): ";

    int path;
    std::cin >> path;

    switch (path) {
    case 1:
        abandonedMine(player);
        break;
    case 2:
        goblinCamp(player);
        break;
    case 3:
        deepCave(player);
        break;
    default:
        std::cout << "\nYou hesitated too long. A rock fell on your head. You died.\n";
        return 0;
    }
    if (!player.isAlive()) {
        std::cout << "\n--- GAME OVER ---\n";
        return 0;
    }

    int path2;
    std::cin >> path2;

    switch (path2) {
    case 1:
        (player);
        break;
    case 2:
        (player);
        break;
    case 3:
        (player);
        break;
    default:
        std::cout << "";
        return 0;
    }
    if (!player.isAlive()) {
        std::cout << "\n--- GAME OVER ---\n";
        return 0;
    }
    int path3;
    std::cin >> path3;

    switch (path3) {
    case 1:
        (player);
        break;
    case 2:
        (player);
        break;
    case 3:
        (player);
        break;
    default:
        std::cout << "";
        return 0;
    }
    if (!player.isAlive()) {
        std::cout << "\n--- GAME OVER ---\n";
        return 0;
    }
    int path4;
    std::cin >> path4;

    switch (path4) {
    case 1:
        (player);
        break;
    case 2:
        (player);
        break;
    case 3:
        (player);
        break;
    default:
        std::cout << "";
        return 0;
    }
    if (!player.isAlive()) {
        std::cout << "\n--- GAME OVER ---\n";
        return 0;
    }
    int path5;
    std::cin >> path5;

    switch (path5) {
    case 1:
        (player);
        break;
    case 2:
        (player);
        break;
    case 3:
        (player);
        break;
    default:
        std::cout << "";
        return 0;
    } 
    if (!player.isAlive()) {
        std::cout << "\n--- GAME OVER ---\n";
        return 0;
    }
    int path6;
    std::cin >> path6;

    switch (path6) {
    case 1:
        ;
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    default:
        std::cout << "";
        return 0;
    }
    if (!player.isAlive()) {
        std::cout << "\n--- GAME OVER ---\n";
        return 0;
    }
    std::cout << "\n--- YOU BEAT THE DUNGEON! ---\n";
    return 0;
}
   

