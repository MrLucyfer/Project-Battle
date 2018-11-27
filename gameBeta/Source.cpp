#include <iostream>
#include <time.h>
#include "Characters.h"
#include "Fight.h"
#include "Level.h"
#include "PMovement.h"

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int level[2][3];
	player p;
	mapType m;
	int iX, iY;
	char name[10] = { "JEJE" };
	int room;
	int options[4];
	char textOptions[4] = { 'u', 'd', 'l', 'r' };
	CreateLevel(level);
	GetZero(level, iX, iY);
	CreateCharacter(p, name, iX, iY);
	while (true) {
		MovementLoop(p, level, options, textOptions, m);
		system("cls");
	}
	system("PAUSE");

	return 0;
}






/*
	int winner;
	char name[100] = { "Nil" };
	player player;
	mob mob;
	CreateCharacter(player, name);
	CreateMob(mob);

	winner = FightLoop(player, mob);

	switch (winner) {
	case 1:
		cout << "You Won!" << endl;
		break;
	case 2:
		cout << "Mob won!" << endl;
		break;
	case 0:
		cout << "Both died in a bloody fight!" << endl;
		break;
	}

	CreateLevel(level);
	PrintLevel(level);
	*/
