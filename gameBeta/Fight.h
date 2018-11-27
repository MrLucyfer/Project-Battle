#pragma once
#include "Characters.h"
int FightMenu();
int FightLoop(player &p);
void Fight(player &p, mob &m, int order);
void Block(player &p, mob &m);
void Heal(player &p, int hp);
void PrintInfo(player p, mob m);