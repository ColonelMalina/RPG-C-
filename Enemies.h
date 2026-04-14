#pragma once
#include <iostream>
#include <string>
class Hero; 
class Enemies {

protected:
    std::string Name;
    double Health;
    double minD;
    double maxD;
    double activeDotDamage = 0;
    int activeDotTurns = 0;
    int frozenTurns = 0;

public:
    Enemies(std::string n, double h, double min, double max ) : Name(n), Health(h), minD(min), maxD(max) {}

    double getAttackPower() {
        double range = maxD - minD;
        return minD + (rand() % (int)(range + 1));
    }
    void takeDamage(double amount) {
        Health -= amount;
        if (Health < 0) Health = 0;
        std::cout << Name << " takes " << amount << " damage! Remaining HP: " << Health << std::endl;
    }
    double attackHero() {
        double damage = getAttackPower();
        std::cout << Name << " attacks for " << damage << " damage!" << std::endl;
        return damage;
    }
    void applyDot(double dotDmg, int turns) {
        if (turns > 0) {
            activeDotDamage = dotDmg;
            activeDotTurns = turns;
            std::cout << "" << Name << " is on fire/bleeding! " << std::endl; 
        }
    }
    void takeDotDamage() {
        if (activeDotTurns > 0) {
            std::cout << Name << " suffers " << activeDotDamage << " DoT damage! (" << activeDotTurns << " turns left)\n";
            Health -= activeDotDamage;
            if (Health < 0) Health = 0;
            activeDotTurns--;
        }
    }
    void freeze(int turns) {
        frozenTurns = turns;
        std::cout << "\033[36m" << Name << " is FROZEN solid!\033[0m" << std::endl;
    }

    bool isFrozen() {
        if (frozenTurns > 0) {
            frozenTurns--;
            return true;
        }
        return false;
    }
    bool isAlive() { return Health > 0; }
    std::string getName() { return Name; }
};


// ================= FLOOR 1: Caves  =================
class CaveBat : public Enemies {
public: CaveBat() : Enemies("Cave Bat", 10, 2, 4) {}
};

class Rat : public Enemies { 
public: Rat() : Enemies("Rat", 15, 3, 5) {}
};

class GiantCentipede : public Enemies {
public: GiantCentipede() : Enemies("Giant Centipede", 22, 4, 7) {}
};
class RabidBear : public Enemies {
public: RabidBear() : Enemies("Rabid Bear", 45, 5, 10) {}
};

// ================= FLOOR 2: Chasm  =================
class Goblin : public Enemies { 
public: Goblin() : Enemies("Goblin", 30, 8, 12) {}
};

class ChasmHarpy : public Enemies { 
public: ChasmHarpy() : Enemies("Chasm Harpy", 38, 7, 13) {}
};

class BridgeTroll : public Enemies {
public: BridgeTroll() : Enemies("Bridge Troll", 45, 9, 16) {}
};

// ================= FLOOR 3: Magical Ruins =================
class AnimatedArmor : public Enemies {
public: AnimatedArmor() : Enemies("Animated Armor", 50, 10, 16) {}
};

class ArcaneWraith : public Enemies { 
public: ArcaneWraith() : Enemies("Arcane Wraith", 55, 11, 19) {}
};

class Orc : public Enemies { 
public: Orc() : Enemies("Orc", 60, 13, 31) {}
};

// ================= FLOOR 4: Demonic Corruption =================
class Orc2 : public Enemies {
public: Orc2() : Enemies("Demonic Warlock", 40, 25, 40) {}
};

class BloodFiend : public Enemies {
public: BloodFiend() : Enemies("Blood Fiend", 70, 18, 28) {}
};

class FleshGolem : public Enemies {
public: FleshGolem() : Enemies("Flesh Golem", 80, 15, 22) {}
};

// ================= FLOOR 5: Gates of the Abyss =================
class Hellhound : public Enemies {
public: Hellhound() : Enemies("Hellhound", 100, 22, 35) {}
};

class DreadKnight : public Enemies { // --- NOVÉ ---
public: DreadKnight() : Enemies("Dread Knight", 120, 24, 38) {} 
};

class ObsidianGargoyle : public Enemies {
public: ObsidianGargoyle() : Enemies("Obsidian Gargoyle", 140, 20, 30) {} 
};

// ================= FLOOR 6: FINAL BOSS =================
class DemonLord : public Enemies {
public: DemonLord() : Enemies("Demon Lord Azazel", 250, 28, 50) {}
};