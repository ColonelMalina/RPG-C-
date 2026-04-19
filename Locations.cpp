#include "Locations.h"
#include "Hero.h"
#include "Enemies.h"
#include "Battle.h"
#include "Weapons.h"
#include <iostream>
#include <vector>


void enterLoc(std::string name) {
    std::cout << "\n\n======================================================";
    std::cout << "\n          ENTERING: " << name;
    std::cout << "\n======================================================\n";
}


void weaponChest(Hero& player, Weapon newW) {
    std::cout << "\n[CHEST] The chest looks filled with loot and some bandages!\n";
    player.fullHeal();

    Weapon currentW = player.getCurrentWeapon();

    std::cout << "\n--- WEAPON COMPARISON ---\n";
    std::cout << "Current : " << currentW.Wname << " (Dmg: " << currentW.minDamage << "-" << currentW.maxDamage << ", Crit: " << currentW.critChance << "%)\n";
    std::cout << "Found   : " << newW.Wname << " (Dmg: " << newW.minDamage << "-" << newW.maxDamage << ", Crit: " << newW.critChance << "%)\n";

    if (newW > currentW) {
        std::cout << "\033[32m-> The " << newW.Wname << " seems STRONGER!\033[0m\n"; 
    }
    else {
        std::cout << "\033[31m-> The " << newW.Wname << " seems WEAKER.\033[0m\n";  
    }

    std::cout << "\nDo you want to equip the " << newW.Wname << "? \n1. YES | 2. NO\nSelect: ";
    int eq;
    std::cin >> eq;
    if (eq == 1) {
        player.EquipW(newW);
    }
}

// ================= FLOOR 1: THE NATURAL CAVERNS =================

void bearDen(Hero& player) {
    enterLoc("BEAR DEN");
    std::cout << "You hear heavy steps... A Rabid Bear charges!\n";
    if (startBattle(player, new RabidBear())) {
        std::cout << "Its mate was hiding in the shadows!\n";
        player.bandage(30);
        if (startBattle(player, new RabidBear())) {
            player.bandage(30);
            std::cout << "A giant centipede drops from the ceiling to scavenge the remains!\n";
            if (startBattle(player, new GiantCentipede())) {
                weaponChest(player, SteelSword());
                player.upgradeMana(10);
                player.regainMana();
                player.addhPotion(1);
            }
        }
    }
}

void undergroundLake(Hero& player) {
    enterLoc("UNDERGROUND LAKE");
    std::cout << "A massive swarm of cave creatures attacks from the ceiling!\n";
    std::vector<Enemies*> swarm1 = { new CaveBat(), new Rat() };
    if (startMultiBattle(player, swarm1)) {
        player.fullHeal();
        std::cout << "More creatures emerge from the dark water!\n";
        std::vector<Enemies*> swarm2 = { new CaveBat(), new CaveBat(), new Rat() };
        if (startMultiBattle(player, swarm2)) {
            std::cout << "You found a hidden blue herb by the water.\n";
            player.upgradeHeal();
            player.fullHeal();
            player.regainMana();
            weaponChest(player, Dagger());
        }
    }
}

void crystalGrotto(Hero& player) {
    enterLoc("CRYSTAL GROTTO");
    std::cout << "Two Giant Centipedes are guarding the glowing crystals!\n";
    std::vector<Enemies*> guards = { new GiantCentipede(), new GiantCentipede() };
    if (startMultiBattle(player, guards)) {
        std::cout << "A Cave Bat, disturbed by the fight, swoops in!\n";
        if (startBattle(player, new CaveBat())) {
            player.upgradeMana(10);
            player.regainMana();
            player.addhPotion(2);
        }
    }
}

void steepDescent(Hero& player) {
    enterLoc("STEEP DESCENT");
    std::cout << "A Goblin and his rat companion block the tunnel down!\n";
    std::vector<Enemies*> ambush1 = { new Goblin(), new Rat() };
    if (startMultiBattle(player, ambush1)) {
        std::cout << "Another Goblin jumps down from a ledge to avenge them!\n";
        if (startBattle(player, new Goblin())) {
            std::cout << "You found Dagger dropped by the Goblin.\n";
            weaponChest(player, Dagger());
        }
    }
}

// ================= FLOOR 2: THE GREAT CHASM =================

void ricketyWoodBridge(Hero& player) {
    enterLoc("RICKETY BRIDGE");
    std::cout << "Harpies swoop down as you try to cross!\n";
    std::vector<Enemies*> flock1 = { new ChasmHarpy() };
    if (startMultiBattle(player, flock1)) {
        std::cout << "Two more Harpies dive from the darkness!\n";
        player.addhPotion(1);
        std::vector<Enemies*> flock2 = { new ChasmHarpy(), new ChasmHarpy() };
        if (startMultiBattle(player, flock2)) {
            weaponChest(player, SteelSword());
            player.addhPotion(1);
        }
    }
}

void stoneOverpass(Hero& player) {
    enterLoc("STONE OVERPASS");
    std::cout << "A Bridge Troll roars, flanked by two Goblins!\n";
    std::vector<Enemies*> trollGang = { new BridgeTroll(), new Goblin(), new Goblin() };
    if (startMultiBattle(player, trollGang)) {
        std::cout << "More Goblins rush from the other side of the bridge!\n";
        std::vector<Enemies*> gobbo = { new Goblin(), new ShamGob() };
        if (startMultiBattle(player, gobbo)) {
            std::cout << "You absorbed the essence of the Fire Goblin and learned FIREBALL!";
            weaponChest(player, HeavyMace());
            player.upgradeHeal();
            player.regainMana();
            player.learnFireball();
        }
    }
}

void hiddenFord(Hero& player) {
    enterLoc("HIDDEN FORD");
    std::cout << "The water boils. Three Giant Centipedes emerge!\n";
    std::vector<Enemies*> wave1 = { new GiantCentipede(), new GiantCentipede(), new GiantCentipede() };
    if (startMultiBattle(player, wave1)) {
        std::cout << "The water boils again... Two more arrive!\n";
        player.addhPotion(1);
        std::vector<Enemies*> wave2 = { new GiantCentipede(), new GiantCentipede() };
        if (startMultiBattle(player, wave2)) {
            std::cout << "You found a rusty Orish axe in the water.\n";
            weaponChest(player, OrcAxe());
            player.upgradeMana(10);
            player.fullHeal();
            player.regainMana();
            player.addhPotion(1);
        }
    }
}

// ================= FLOOR 3: THE FORGOTTEN RUINS =================

void ruinedAltar(Hero& player) {
    enterLoc("RUINED ALTAR");
    std::cout << "Three suits of Animated Armor wake from their slumber!\n";
    std::vector<Enemies*> armors1 = { new AnimatedArmor(), new AnimatedArmor() };
    if (startMultiBattle(player, armors1)) {
        std::cout << "The final, massive armor steps forward!\n";
        player.addhPotion(2);
        if (startBattle(player, new AnimatedArmor())) {
            std::cout << "The altar grants you the more knowledge for FIREBALL!\n";
            player.upgradeFireball();
            player.regainMana();
        }
    }
}

void illusionCorridor(Hero& player) {
    enterLoc("ILLUSION CORRIDOR");
    std::cout << "The shadows twist into four Arcane Wraiths!\n";
    std::vector<Enemies*> wraiths1 = { new ArcaneWraith(), new ArcaneWraith() };
    if (startMultiBattle(player, wraiths1)) {
        std::cout << "Two more Wraiths materialize from the walls!\n";
        player.bandage(30);
        std::vector<Enemies*> wraiths2 = { new ArcaneWraith(), new ArcaneWraith() };
        if (startMultiBattle(player, wraiths2)) {
            std::cout << "You absorbed the essence from wraiths and learned ICESPIKE!\n";
            weaponChest(player, Edagger());
            player.upgradeFireball();
            player.regainMana();
            player.learnIce();
        }
    }
}

void alchemyLab(Hero& player) {
    enterLoc("ALCHEMY LAB");
    std::cout << "An Orc is looting the lab, protected by Wraiths!\n";
    std::vector<Enemies*> looters = { new ArcaneWraith(), new ArcaneWraith() };
    if (startMultiBattle(player, looters)) {
        std::cout << "You picked up some bandages from table.\n";
        player.bandage(30);
        player.addhPotion(1);
        std::cout << "The Orc charges at you with full force!\n";
        if (startBattle(player, new Orc())) {
            player.upgradeFireball();
            player.upgradeMana(15);
            player.regainMana();
            player.fullHeal();
        }
    }
}

void glowingPortal(Hero& player) {
    enterLoc("GLOWING PORTAL");
    std::cout << "A massive Goblin squad guards the portal!\n";
    std::vector<Enemies*> squad1 = { new Goblin(), new Goblin(), new Goblin() };
    if (startMultiBattle(player, squad1)) {
        std::cout << "The Orc Commander steps through the portal to face you!\n";
        player.addhPotion(1);
        if (startBattle(player, new Orc())) {
            weaponChest(player, OrcAxe());
            player.upgradeFireball();
            player.regainMana();
        }
    }
}

// ================= FLOOR 4: THE CORRUPTED DEPTHS =================

void bloodRiver(Hero& player) {
    enterLoc("BLOOD RIVER");
    std::cout << "A pack of Blood Fiends is drinking from the river!\n";
    std::vector<Enemies*> pack1 = { new BloodFiend(), new BloodFiend() };
    if (startMultiBattle(player, pack1)) {
        std::cout << "More Fiends crawl out of the bloody water!\n";
        player.bandage(30);
        std::vector<Enemies*> pack2 = { new BloodFiend(), new BloodFiend() };
        if (startMultiBattle(player, pack2)) {
            weaponChest(player, Elvensword());
            player.upgradeHeal();
            player.regainMana();
        }
    }
}

void fleshWallCorridor(Hero& player) {
    enterLoc("FLESH WALL");
    std::cout << "A Flesh Golem bursts from the wall, releasing a swarm of rats!\n";
    std::vector<Enemies*> gross1 = { new Rat(), new Rat(), new Rat() };
    if (startMultiBattle(player, gross1)) {
        std::cout << "The Flesh Golem finally breaks free and attacks!\n"; 
        player.addhPotion(1);
        std::vector<Enemies*> gross2 = { new FleshGolem(), new BloodFiend() };
        if (startMultiBattle(player, gross2)) {
            player.upgradeIce();
            player.upgradeHeal();
            player.regainMana();
            player.fullHeal();
        }
    }
}

void boneCatacombs(Hero& player) {
    enterLoc("BONE CATACOMBS");
    std::cout << "A Warlock is leading a patrol!\n";
    std::vector<Enemies*> patrol1 = { new Orc(), new Orc() };
    if (startMultiBattle(player, patrol1)) {
        std::cout << "The Orc Warlock unleashes his dark magic!\n";
        if (startBattle(player, new Orc2())) {
            std::cout << "There's a lot of scrools lying around!\n";
            player.upgradeIce();
            player.upgradeFireball();
            player.regainMana();
            player.upgradeMana(20);
        }
    }
}

void soulPrison(Hero& player) {
    enterLoc("SOUL PRISON");
    std::cout << "The prison is heavily guarded by Fiends and a Shaman!\n";
    std::vector<Enemies*> guards1 = { new BloodFiend(), new BloodFiend() };
    if (startMultiBattle(player, guards1)) {
        std::cout << "The Shaman summons another Fiend to his side!\n"; 
        player.addhPotion(2);
        std::vector<Enemies*> guards2 = { new Orc2(), new BloodFiend() };
        if (startMultiBattle(player, guards2)) {
            player.upgradeIce();
            player.upgradeHeal();
            player.regainMana();
        }
    }
}

// ================= FLOOR 5: THE GATES OF HELL =================

void flamingPits(Hero& player) {
    enterLoc("FLAMING PITS");
    std::cout << "A pack of four Hellhounds surrounds you!\n";
    std::vector<Enemies*> hounds1 = { new Hellhound(), new Hellhound() };
    if (startMultiBattle(player, hounds1)) {
        std::cout << "Two more leap from the flames!\n";
        player.bandage(30);
        std::vector<Enemies*> hounds2 = { new Hellhound(), new Hellhound() };
        if (startMultiBattle(player, hounds2)) {
            weaponChest(player, BigAxe());
            player.upgradeFireball();
            player.regainMana();
            player.addhPotion(2);
        }
    }
}

void demonicStatues(Hero& player) {
    enterLoc("DEMONIC STATUES");
    std::cout << "The gargoyles animate, supported by Animated Armors!\n";
    std::vector<Enemies*> livingStone1 = { new AnimatedArmor(), new AnimatedArmor() };
    if (startMultiBattle(player, livingStone1)) {
        std::cout << "The obsidian Gargoyles spread their wings!\n";
        player.bandage(30);
        std::vector<Enemies*> livingStone2 = { new ObsidianGargoyle(), new ObsidianGargoyle() };
        if (startMultiBattle(player, livingStone2)) {
            weaponChest(player, Halapartna());
            player.upgradeIce();
            player.regainMana();
        }
    }
}

void abyssalGorge(Hero& player) {
    enterLoc("ABYSSAL GORGE");
    std::cout << "A lone Dread Knight stands on the edge... and summons Blood Fiends!\n";
    std::vector<Enemies*> sum = { new BloodFiend(), new BloodFiend(), new BloodFiend() };
    if (startMultiBattle(player, sum)) {
        std::cout << "The Dread Knight draws his massive sword!\n";
        if (startBattle(player, new DreadKnight())) {
            player.upgradeFireball();
            player.upgradeIce();
            player.fullHeal();
            player.regainMana();
            player.addhPotion(2);
        }
    }
}

void blackGate(Hero& player) {
    enterLoc("THE BLACK GATE");
    std::cout << "The elite guard of the Demon Lord will not let you pass!\n";
    std::vector<Enemies*> elite1 = { new Hellhound(), new Hellhound() };
    if (startMultiBattle(player, elite1)) {
        std::cout << "Two Dread Knights step forward to finish you!\n";
        player.bandage(30);
        std::vector<Enemies*> elite2 = { new DreadKnight(), new DreadKnight() };
        if (startMultiBattle(player, elite2)) {
            std::cout << "The gate creaks open... The final battle awaits.\n";
            player.regainMana();
            player.fullHeal(); 
            player.addhPotion(1);
        }
    }
}

// ================= FLOOR 6: THE FINAL BOSS =================

void bossRoom(Hero& player) {
    enterLoc("THE THRONE OF THE ABYSS");
    std::cout << "The Demon Lord's personal guards attack first!\n";
    std::vector<Enemies*> honorGuard = { new ObsidianGargoyle(), new DreadKnight() };
    if (startMultiBattle(player, honorGuard)) {
        std::cout << "Azazel rises from his throne. 'Enough play...'\n";
        if (startBattle(player, new DemonLord())) {
            std::cout << "\n======================================================\n";
            std::cout << " AZAZEL FALLS! THE LIGHT RETURNS TO CONSOLE LAND!\n";
            std::cout << "               YOU ARE THE CHAMPION!\n";
            std::cout << "======================================================\n";
        }
    }
}