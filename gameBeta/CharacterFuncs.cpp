#include <iostream>
#include "Characters.h"
#include "Random.h"

using namespace std;

//Crea un jugador
void CreateCharacter(player &p, int x, int y) {
	p.hp = 10;
	p.at = 3;
	p.x = x;
	p.y = y;
	p.potions = 1;
}

//Crea un mob
void CreateMob(mob &m) {
	m.hp = Random(7,10);
	m.at = Random(2,4);
	m.alive = true;
}

//Imprime el nombre de un personaje
void PrintName(char n[]) {
	int i = 0;
	while (n[i] != '\0') {
		cout << n[i];
		i++;
	}
}

//Imprime el nombre de un personaje
void PrintCoord(player p) {
	cout << p.y << " " << p.x << endl;
}