#pragma once
#include "Characters.h"

struct level {
	int x, y, type;
	bool clean;
};


struct mapType {
	char pl = 64;
	char u = 35;
	char v = 32;
};

void EmptyArray(level a[2][3]);
bool Check(level a[2][3], int &y, int &x);
void Insert(level a[2][3], int &y, int &x, int num);
void CreateLevel(level fl[2][3]);
void PrintLevel(level fl[2][3]);
void GetZero(level fl[2][3], int &, int &);
int GetRoom(player p, level fl[2][3]);
void CleanRoom(player p, level fl[2][3]);