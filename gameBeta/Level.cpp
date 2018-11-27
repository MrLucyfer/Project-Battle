#include <iostream>
#include "Random.h"
#include "Level.h"
#include "Characters.h"


using namespace std;

//1.Inicializar array a 1
//2.Sacar la coord Start
//3.Sacar la coord End y comprobar que no esta cogida
//3.Determinar pocion o espada y comprobar que no esta cogida

void EmptyArray(level a[2][3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j].x = j;
			a[i][j].y = i;
			a[i][j].type = 1;
			a[i][j].clean = false;
		}
	}
}

bool Check(level a[2][3], int &y, int &x) {
	y = Random(0, 1);
	x = Random(0, 2);
	if (a[y][x].type == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Insert(level a[2][3], int &y, int &x, int num) {
	bool disponible;
	do {
		disponible = Check(a, y, x);
	} while (!disponible);

	a[y][x].type = num;
}



void CreateLevel(level fl[2][3]) {
	int y, x;
	EmptyArray(fl);
	//Insertar start;
	Insert(fl, y, x, 0);
	//Insertar end;
	Insert(fl, y, x, 3);
	//Insertar bonus;
	Insert(fl, y, x, 2);
}


void PrintLevel(level fl[2][3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << fl[i][j].type << " ";
		}
		cout << endl;
	}
}

void GetZero(level fl[2][3], int &x, int &y) {
	int i = 0, j = 0;
	bool found = false;

	while (i < 2 && j < 3 && !found) {
		if (fl[i][j].type == 0) {
			y = i;
			x = j;
			found = true;
		}
		else {
			if (j >= 2 && i <= 1) {
				i++;
				j = 0;
			}
			else {
				j++;
			}
		}
	}
}

int GetRoom(player p, level fl[2][3]) {
	int room;
	room = fl[p.y][p.x].type;

	return room;
}


