#include <iostream>
#include "Characters.h"
#include "Level.h"

using namespace std;

void Movement(player &p, int dir) {
	switch (dir) {
	case 1:
			p.y -= 1;
			break;
	case 2:
			p.y += 1;		
			break;
	case 3:
			p.x -= 1;		
			break;
	case 4:
			p.x += 1;		
			break;
	default:
		cout << "Wrong input" << endl;
	}
}


void CheckColliders(player p, int fl[2][3], int options[]) {

	//UP
	if (p.y == 0) {
		options[0] = 0;
	}
	else {
		options[0] = 1;
	}

	//Down
	if (p.y == 1) {
		options[1] = 0;
	}
	else {
		options[1] = 1;
	}

	//Left
	if (p.x == 0) {
		options[2] = 0;
	}
	else {
		options[2] = 1;
	}

	//Right
	if (p.x == 2) {
		options[3] = 0;
	}
	else {
		options[3] = 1;
	}
	cout << endl;
}

int MovementMenu(player p, int fl[2][3], int options[], char tp[]) {
	int option;
	int index = 0;
	CheckColliders(p, fl, options);
	cout << "Choose a direction: " << endl;
	for (int i = 0; i < 4; i++) {
		if (options[i] == 1) {
			cout << index + 1 << "-" << tp[i] << endl;;
		}
		index++;
	}
	
	do {
		cin >> option;
		if (option <= 0 || option > 4 || options[option - 1] == 0) {
			cout << "Enter a valid direction" << endl;
		}
	} while (option <= 0 || option > 4 || options[option - 1] == 0);
	return option;
}


void CurrentPosition(player p, int fl[2][3], mapType m) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == p.y && j == p.x) {
				cout << m.pl << " ";
			}
			else if (fl[i][j] == 0) {
				cout << m.v << " ";
			}
			else {
				cout << m.u << " ";
			}
		}
		cout << endl;
	}
}

void ClearRoom(int fl[2][3], player p) {
	fl[p.y][p.x] = 0;
}


void MovementLoop(player &p, int fl[2][3], int options[4], char tp[], mapType m) {
	int dir;
	CurrentPosition(p, fl, m);
	CheckColliders(p, fl, options);
	dir = MovementMenu(p, fl, options, tp);
	Movement(p, dir);
	ClearRoom(fl, p);
}