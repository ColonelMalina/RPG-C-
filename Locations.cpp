#include "Locations.h"
#include "Hero.h"
#include "Enemies.h"
#include "Battle.h"
#include <iostream>

// ================= FLOOR 1: CAVES (Exploration) =================
void bearDen(Hero& player) { std::cout << "\n[Bear Den] The smell of wet fur fills the air. Deep claw marks scar the stone walls...\n"; }

void undergroundLake(Hero& player) { std::cout << "\n[Underground Lake] A vast, dark lake lies before you. The freezing water ripples mysteriously...\n"; }

void crystalGrotto(Hero& player) { std::cout << "\n[Crystal Grotto] Beautiful blue crystals illuminate the cavern. Shadows dance in the pale light...\n"; }

void steepDescent(Hero& player) { std::cout << "\n[Steep Descent] You find a dark, narrow tunnel leading deeper underground...\n"; }

// ================= FLOOR 2: CHASM AND BRIDGE (Proceed) =================
void ricketyWoodBridge(Hero& player) { std::cout << "\n[Rickety Bridge] The old wood creaks terrifyingly, but you manage to cross the chasm.\n"; }

void stoneOverpass(Hero& player) { std::cout << "\n[Stone Overpass] A solid dwarven bridge. It feels safe, though you hear whispers from below.\n"; }

void hiddenFord(Hero& player) { std::cout << "\n[Hidden Ford] You climb down and wade through the shallow rapids to reach the other side.\n"; }

// ================= FLOOR 3: MAGICAL RUINS (Exploration) =================
void ruinedAltar(Hero& player) { std::cout << "\n[Ruined Altar] Crumbled statues of forgotten gods stand in silent judgment. The air feels heavy...\n"; }

void illusionCorridor(Hero& player) { std::cout << "\n[Illusion Corridor] The hallway twists and turns unnaturally, warping your sense of direction...\n"; }

void alchemyLab(Hero& player) { std::cout << "\n[Alchemy Lab] Shattered glass and strange glowing liquids cover the tables. A strange mist lingers...\n"; }

void glowingPortal(Hero& player) { std::cout << "\n[Glowing Portal] You step into a shimmering rift in space and are teleported deeper!\n"; }

// ================= FLOOR 4: DEMONIC CORRUPTION (Proceed) =================
void bloodRiver(Hero& player) { std::cout << "\n[Blood River] The water here is thick and crimson. The smell of copper is overwhelming.\n"; }

void fleshWallCorridor(Hero& player) { std::cout << "\n[Flesh Wall] The stone walls pulse as if they are breathing. Disgusting, but you push through.\n"; }

void boneCatacombs(Hero& player) { std::cout << "\n[Bone Catacombs] Every step crunches on skulls and ribs of ancient victims.\n"; }

void soulPrison(Hero& player) { std::cout << "\n[Soul Prison] Ghostly hands reach out from the walls, begging for release as you pass.\n"; }

// ================= FLOOR 5: GATES OF THE ABYSS (Proceed) =================
void flamingPits(Hero& player) { std::cout << "\n[Flaming Pits] Plumes of hellfire erupt from the floor. You carefully navigate the heat.\n"; }

void demonicStatues(Hero& player) { std::cout << "\n[Demonic Statues] Huge obsidian demons watch you with glowing ruby eyes as you walk by.\n"; }

void abyssalGorge(Hero& player) { std::cout << "\n[Abyssal Gorge] A narrow ledge above an endless void of dark, swirling energy.\n"; }

void blackGate(Hero& player) { std::cout << "\n[The Black Gate] A massive door made of dark iron and screaming faces stands before you.\n"; }

// ================= FLOOR 6: BOSS =================
void bossRoom(Hero& player) {
    std::cout << "\n======================================================\n";
    std::cout << "               THE THRONE OF THE ABYSS\n";
    std::cout << "======================================================\n";
    std::cout << "The air is suffocating. The Demon Lord rises from his throne of bone.\n";
    std::cout << "'You have wandered too far from the light, mortal...'\n";
}
}
//    if (startBattle(player, new Orc())) {
//        std::cout << "\nThe chest looks filled with loot and some bandages!\n";
//        player.fullHeal();
//        std::cout << "\nDo you want to equip the Orcish Axe? \n1. YES/ 2. NO\n";
//        int eq;
//        std::cin >> eq;
//        switch (eq) {
//        case 1:
//            player.EquipW(OrcAxe());
//            break;
//        case 2:
//            break;
//        };
//    }
//}