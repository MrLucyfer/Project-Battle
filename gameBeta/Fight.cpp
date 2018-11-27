#include "Characters.h"
#include "Random.h"
#include <iostream>

using namespace std;

//Recoge la opcion para la pelea
char FightMenu() {
	char option;
	cout << "--- Choose one option: ---" << endl;
	cout << endl;
	cout << "1-Attack" << endl;
	cout << "2-Block" << endl;
	cout << "3-Heal" << endl;
	cin >> option;
	return option;
}

//Funcion activada si 1
void Fight(player &p, mob &m, int order) {
	int blockChance = Random(0, 10);
	switch (order) {
	case 0:
		m.hp -= p.at;
		if (blockChance >= 3) {
			p.hp -= m.at;
		}
		break;
	case 1:
		p.hp -= m.at;
		if (blockChance >= 3) {
			m.hp -= p.at;
		}
		break;
	}
	if (p.hp <= 0) {
		p.alive = false;
	}
	if (m.hp <= 0) {
		m.alive = false;
	}
}

//Funcion activada si 2
void Block(player &p, mob &m) {
	int dmg = m.at - p.at;
	if (dmg > 0) {
		p.hp -= dmg;
	}
}

//Funcion activada si 3
void Heal(player &p, int hp) {
	if (p.potions > 0 && p.hp < 10) {
		p.hp += hp;
	}
}

//Muestra las vidas de los jugadores
void PrintInfo(player p, mob m) {
	cout << "Player - " << p.hp << "   " << "MOB - " << m.hp << endl;
	cout << endl;
}


//Proceso de pelea hasta la muerte de uno de ellos
int FightLoop(player &p, mob &m) {
	int order = Random(0, 1);
	char option;
	while (p.alive && m.alive) {
		PrintInfo(p, m);
		do {
			 option = FightMenu();
		} while (option != '1' && option != '2' &&option != '3');
		
		switch (option) {
		case '1': 
			Fight(p, m, order);
			break;
		case '2':
			Block(p, m);
			break;
		case '3': 
			Heal(p, 3);
			break;
		}
	}
	if (p.alive) {
		return 1;
	}
	else if (m.alive) {
		return 2;
	}
	else {
		return 0;
	}
}


