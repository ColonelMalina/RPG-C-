#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
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
    player.EquipW(Weapon());

    int currentFloor = 1;
    std::map<int, std::set<std::string>> clearedLocations;
    bool gameRunning = true;

    while (gameRunning && player.isAlive()) {
        std::cout << "\n============================================\n";
        std::cout << "   FLOOR " << currentFloor << " - Status: " << player.getName() << " (HP: " << player.getHealth()<< " Mana: " << player.getMana() << ")"; 
        std::cout << "\n============================================\n";

        if (clearedLocations.count(currentFloor)) {
            std::cout << "Cleared on this floor: ";
            for (const auto& loc : clearedLocations[currentFloor]) {
                std::cout << "[" << loc << "] ";
            }
            std::cout << "\n--------------------------------------------\n";
        }

        if (currentFloor == 1) {
            std::cout << "--- FLOOR 1: The Natural Caverns ---\n";
            std::cout << "1. [Explore] Bear Den\n2. [Explore] Underground Lake\n3. [Explore] Crystal Grotto\n4. [Proceed] Steep Descent\n";
            int p1; std::cin >> p1;
            switch (p1) {
            case 1: bearDen(player); clearedLocations[currentFloor].insert("Bear Den"); break;
            case 2: undergroundLake(player); clearedLocations[currentFloor].insert("Underground Lake"); break;
            case 3: crystalGrotto(player); clearedLocations[currentFloor].insert("Crystal Grotto"); break;
            case 4: steepDescent(player); clearedLocations[currentFloor].insert("Steep Descent"); currentFloor = 2; break;
            default: std::cout << "Invalid choice.\n"; break;
            }
        }
        else if (currentFloor == 2) {
            std::cout << "--- FLOOR 2: The Great Chasm ---\n";
            std::cout << "1. [Go Back] Return to Floor 1\n";
            std::cout << "2. [Proceed] Rickety Wood Bridge\n3. [Proceed] Stone Overpass\n4. [Proceed] Hidden Ford\n";
            int p2; std::cin >> p2;
            if (p2 == 1) { currentFloor = 1; continue; }
            switch (p2) {
            case 2: ricketyWoodBridge(player); currentFloor = 3; clearedLocations[currentFloor].insert("Rickety Bridge"); break;
            case 3: stoneOverpass(player); currentFloor = 3; clearedLocations[currentFloor].insert("Stone Overpass"); break;
            case 4: hiddenFord(player); currentFloor = 3; clearedLocations[currentFloor].insert("Hidden Ford"); break;
            default: std::cout << "You fell into the abyss.\n"; return 0;
            }
        }
        else if (currentFloor == 3) {
            std::cout << "--- FLOOR 3: The Forgotten Ruins ---\n";
            std::cout << "1. [Go Back] Return to Floor 2\n";
            std::cout << "2. [Explore] Ruined Altar\n3. [Explore] Illusion Corridor\n4. [Explore] Alchemy Lab\n5. [Proceed] Glowing Portal\n";
            int p3; std::cin >> p3;
            if (p3 == 1) { currentFloor = 2; continue; }
            switch (p3) {
            case 2: ruinedAltar(player); clearedLocations[currentFloor].insert("Ruined Altar"); break;
            case 3: illusionCorridor(player); clearedLocations[currentFloor].insert("Illusion Corridor"); break;
            case 4: alchemyLab(player); clearedLocations[currentFloor].insert("Alchemy Lab"); break;
            case 5: glowingPortal(player); currentFloor = 4; clearedLocations[currentFloor].insert("Glowing Portal"); break;
            }
        }
        else if (currentFloor == 4) {
            std::cout << "--- FLOOR 4: The Corrupted Depths ---\n";
            std::cout << "1. [Go Back] Return to Floor 3\n";
            std::cout << "2. [Proceed - Path A] Follow the River of Blood\n";
            std::cout << "3. [Proceed - Path B] Enter the Soul Prison\n";
            std::cout << "4. [Explore] Flesh Wall Corridor\n5. [Explore] Bone Catacombs\n";
            int p4; std::cin >> p4;
            if (p4 == 1) { currentFloor = 3; continue; }
            switch (p4) {
            case 2: bloodRiver(player); currentFloor = 5; clearedLocations[currentFloor].insert("Blood River"); break;
            case 3: soulPrison(player); currentFloor = 5; clearedLocations[currentFloor].insert("Soul Prison"); break;
            case 4: fleshWallCorridor(player); clearedLocations[currentFloor].insert("Flesh Wall"); break;
            case 5: boneCatacombs(player); clearedLocations[currentFloor].insert("Bone Catacombs"); break;
            }
        }
        else if (currentFloor == 5) {
            std::cout << "--- FLOOR 5: The Gates of Hell ---\n";
            std::cout << "1. [Go Back] Return to Floor 4\n";
            std::cout << "2. [Explore] Jump across Flaming Pits\n3. [Explore] Walk between Demonic Statues\n4. [Explore] Abyssal Gorge\n5. [BOSS GATE] Black Gate\n";
            int p5; std::cin >> p5;
            if (p5 == 1) { currentFloor = 4; continue; }
            switch (p5) {
            case 2: flamingPits(player); clearedLocations[currentFloor].insert("Flaming Pits"); break;
            case 3: demonicStatues(player); clearedLocations[currentFloor].insert("Demonic Statues"); break;
            case 4: abyssalGorge(player); clearedLocations[currentFloor].insert("Abyssal Gorge"); break;
            case 5: blackGate(player); currentFloor = 6; clearedLocations[currentFloor].insert("Black Gate"); break;
            }
        }
        else if (currentFloor == 6) {
            bossRoom(player);
            if (player.isAlive()) {
                std::cout << "\n*** CONGRATULATIONS! YOU HAVE CONQUERED THE ABYSS! ***\n";
                gameRunning = false;
            }
        }

        if (!player.isAlive()) {
            std::cout << "\n--- GAME OVER ---\n";
            gameRunning = false;
        }
    }

    return 0;
}
   

