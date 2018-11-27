#pragma once

struct player {
	char name[20];
	int hp, at;
	bool alive = true;
	int potions;

	int x, y;
	
};

struct mob {
	char name[20];
	int hp, at;
	bool alive = true;
};

void CreateCharacter(player &p, char name[], int x, int y);
void CreateMob(mob &m);
void PrintName(char n[]);
void PrintCoord(player p);