#pragma once
#include <vector>
class Hero;
class Enemies;

bool startBattle(Hero& player, Enemies* monster);
bool startMultiBattle(Hero& player, std::vector<Enemies*> enemies);