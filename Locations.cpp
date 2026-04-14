#include "Locations.h"
#include "Hero.h"
#include "Enemies.h"
#include "Battle.h"
#include <iostream>
#include <vector>

// Pomocná funkce pro vizuální oddělení lokací
void enterLoc(std::string name) {
    std::cout << "\n\n======================================================";
    std::cout << "\n          ENTERING: " << name;
    std::cout << "\n======================================================\n";
}
void weaponChest(Hero& player, Weapon newW) {
    std::cout << "\n[CHEST] The chest looks filled with loot and some bandages!\n";
    player.fullHeal();
    std::cout << "Do you want to equip the " << newW.Wname << "? \n1. YES | 2. NO\n";
    int eq;
    std::cin >> eq;
    if (eq == 1) player.EquipW(newW);
}

// ================= FLOOR 1: THE NATURAL CAVERNS =================

void bearDen(Hero& player) {
    enterLoc("BEAR DEN");
    std::cout << "The den is dark. You hear heavy breathing from two different corners...\n";
    if (startBattle(player, new RabidBear())) {
        std::cout << "The mother bear is dead, but her mate is even larger!\n";
        if (startBattle(player, new RabidBear())) {
            std::cout << "Victory! You found a Rusty Dagger and an ancient mana shard.\n";
            weaponChest(player, Dagger());
            player.upgradeMana(10); // MANA UPGRADE 1/5
        }
    }
}

void undergroundLake(Hero& player) {
    enterLoc("UNDERGROUND LAKE");
    std::cout << "As you approach the water, a swarm of vermin attacks!\n";
    if (startBattle(player, new CaveBat())) {
        if (startBattle(player, new Rat())) {
            if (startBattle(player, new CaveBat())) {
                std::cout << "The swarm is cleared. You find a glowing blue herb.\n";
                player.upgradeHeal(); // HEAL UPGRADE 1/5
                player.fullHeal();
            }
        }
    }
}

void crystalGrotto(Hero& player) {
    enterLoc("CRYSTAL GROTTO");
    std::cout << "The crystals hum. A giant centipede guards a pile of loot!\n";
    if (startBattle(player, new GiantCentipede())) {
        std::cout << "You found a mana crystal embedded in the wall.\n";
        player.upgradeMana(10); // MANA UPGRADE 2/5
        player.regainMana();
    }
}

void steepDescent(Hero& player) {
    enterLoc("STEEP DESCENT");
    std::cout << "The way down is blocked by a Goblin scout.\n";
    if (startBattle(player, new Goblin())) {
        std::cout << "You managed to push through deeper into the earth.\n";
    }
}

// ================= FLOOR 2: THE GREAT CHASM =================

void ricketyWoodBridge(Hero& player) {
    enterLoc("RICKETY BRIDGE");
    std::cout << "Harpies are circling above the bridge. They dive at you!\n";
    if (startBattle(player, new ChasmHarpy())) {
        if (startBattle(player, new ChasmHarpy())) {
            std::cout << "You crossed the bridge and found a Steel Sword!\n";
            weaponChest(player, SteelSword());
        }
    }
}

void stoneOverpass(Hero& player) {
    enterLoc("STONE OVERPASS");
    std::cout << "A Bridge Troll stands his ground. He's not alone.\n";
    if (startBattle(player, new BridgeTroll())) {
        std::cout << "A Goblin raider joins the fight from the shadows!\n";
        if (startBattle(player, new Goblin())) {
            std::cout << "You recovered a Heavy Mace from the Troll's hoard.\n";
            weaponChest(player, HeavyMace());
            player.upgradeHeal(); // HEAL UPGRADE 2/5
        }
    }
}

void hiddenFord(Hero& player) {
    enterLoc("HIDDEN FORD");
    std::cout << "The rapids are dangerous. Two centipedes ambush you in the water!\n";
    std::vector<Enemies*> wave = { new GiantCentipede(), new GiantCentipede() };
    if (startMultiBattle(player, wave)) {
            std::cout << "The cold water heals your wounds. You found a mana potion.\n";
            player.fullHeal();
            player.upgradeMana(10); // MANA UPGRADE 3/5
        }
    }
}

// ================= FLOOR 3: THE FORGOTTEN RUINS =================

void ruinedAltar(Hero& player) {
    enterLoc("RUINED ALTAR");
    std::cout << "Two suits of Animated Armor guard the sacred fire.\n";
    if (startBattle(player, new AnimatedArmor())) {
        if (startBattle(player, new AnimatedArmor())) {
            std::cout << "The altar ignites! You learn FIREBALL.\n";
            player.learnFireball(); // FIREBALL UNLOCK
        }
    }
}

void illusionCorridor(Hero& player) {
    enterLoc("ILLUSION CORRIDOR");
    std::cout << "The hallway is endless. A wraith appears to test your mind.\n";
    if (startBattle(player, new ArcaneWraith())) {
        std::cout << "Another shadow emerges from the walls!\n";
        if (startBattle(player, new ArcaneWraith())) {
            std::cout << "The illusions vanish. You find an Enchanted Dagger.\n";
            weaponChest(player, Edagger());
            player.upgradeFireball(); // FIREBALL UPGRADE 1/5
        }
    }
}

void alchemyLab(Hero& player) {
    enterLoc("ALCHEMY LAB");
    std::cout << "The lab is a mess of broken glass and angry spirits.\n";
    if (startBattle(player, new ArcaneWraith())) {
        if (startBattle(player, new AnimatedArmor())) {
            std::cout << "You drink a concentrated fire elixir!\n";
            player.upgradeFireball(); // FIREBALL UPGRADE 2/5
            player.upgradeMana(15); // MANA UPGRADE 4/5
            player.regainMana();
        }
    }
}

void glowingPortal(Hero& player) {
    enterLoc("GLOWING PORTAL");
    std::cout << "A heavy Orc stands before the rift. He won't let you pass.\n";
    if (startBattle(player, new Orc())) {
        std::cout << "Another Orc charges from the portal!\n";
        if (startBattle(player, new Orc())) {
            std::cout << "You seized an Orcish Axe and stepped through.\n";
            weaponChest(player, OrcAxe());
            player.upgradeFireball(); // FIREBALL UPGRADE 3/5
        }
    }
}

// ================= FLOOR 4: THE CORRUPTED DEPTHS =================

void bloodRiver(Hero& player) {
    enterLoc("BLOOD RIVER");
    std::cout << "The fiends are feeding. They are hungry for your blood!\n";
    if (startBattle(player, new BloodFiend())) {
        if (startBattle(player, new BloodFiend())) {
            if (startBattle(player, new BloodFiend())) {
                std::cout << "The river yields the Elven Sword and a boost to your healing.\n";
                weaponChest(player, Elvensword());
                player.upgradeHeal(); // HEAL UPGRADE 3/5
            }
        }
    }
}

void fleshWallCorridor(Hero& player) {
    enterLoc("FLESH WALL");
    std::cout << "The walls pulse. Two Flesh Golems block the exit!\n";
    if (startBattle(player, new FleshGolem())) {
        if (startBattle(player, new FleshGolem())) {
            std::cout << "You find a scroll of ice magic in the golem's remains.\n";
            player.upgradeIce(); // ICE UPGRADE 1/5
            player.upgradeHeal(); // HEAL UPGRADE 4/5
        }
    }
}

void boneCatacombs(Hero& player) {
    enterLoc("BONE CATACOMBS");
    std::cout << "A Shaman Orc is raising the dead. Stop him!\n";
    if (startBattle(player, new Orc2())) {
        if (startBattle(player, new Orc2())) {
            std::cout << "The ritual is stopped. You learn ICESPIKE.\n";
            player.learnIce(); // ICE UNLOCK
            player.upgradeIce(); // ICE UPGRADE 2/5
        }
    }
}

void soulPrison(Hero& player) {
    enterLoc("SOUL PRISON");
    std::cout << "The ghosts here are aggressive. Three fiends guard the keys.\n";
    if (startBattle(player, new BloodFiend())) {
        if (startBattle(player, new Orc2())) {
            if (startBattle(player, new BloodFiend())) {
                std::cout << "The freed souls bless your mana and ice spells.\n";
                player.upgradeMana(20); // MANA UPGRADE 5/5
                player.upgradeIce(); // ICE UPGRADE 3/5
                player.upgradeHeal(); // HEAL UPGRADE 5/5
            }
        }
    }
}

// ================= FLOOR 5: THE GATES OF HELL =================

void flamingPits(Hero& player) {
    enterLoc("FLAMING PITS");
    std::cout << "Hellhounds leap from the fire!\n";
    if (startBattle(player, new Hellhound())) {
        if (startBattle(player, new Hellhound())) {
            std::cout << "In the ashes, you find the legendary Axe of Consoleland.\n";
            weaponChest(player, BigAxe());
            player.upgradeFireball(); // FIREBALL UPGRADE 4/5
        }
    }
}

void demonicStatues(Hero& player) {
    enterLoc("DEMONIC STATUES");
    std::cout << "The obsidian gargoyles come to life!\n";
    if (startBattle(player, new ObsidianGargoyle())) {
        if (startBattle(player, new ObsidianGargoyle())) {
            std::cout << "Behind a statue, you find the Halberd of Strength.\n";
            weaponChest(player, Halapartna());
            player.upgradeIce(); // ICE UPGRADE 4/5
        }
    }
}

void abyssalGorge(Hero& player) {
    enterLoc("ABYSSAL GORGE");
    std::cout << "A Dread Knight guards the final bridge.\n";
    if (startBattle(player, new DreadKnight())) {
        std::cout << "The void grants you final mastery over your spells.\n";
        player.upgradeFireball(); // FIREBALL UPGRADE 5/5
        player.upgradeIce(); // ICE UPGRADE 5/5
        player.fullHeal();
        player.regainMana();
    }
}

void blackGate(Hero& player) {
    enterLoc("THE BLACK GATE");
    std::cout << "Two elite Dread Knights stand before the Demon Lord.\n";
    // Tady už začíná jít do tuhého
    if (startBattle(player, new DreadKnight())) {
        if (startBattle(player, new DreadKnight())) {
            std::cout << "The gate creaks open. The air is heavy with death.\n";
        }
    }
}

// ================= FLOOR 6: THE FINAL BOSS =================

void bossRoom(Hero& player) {
    enterLoc("THE THRONE OF THE ABYSS");
    std::cout << "Azazel stands tall. 'You have come far, mortal. But here you fall.'\n";
    if (startBattle(player, new DemonLord())) {
        std::cout << "\nAZAZEL IS DEFEATED! THE LIGHT RETURNS TO CONSOLE LAND!\n";
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