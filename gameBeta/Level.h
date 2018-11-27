#pragma once

struct mapType {
	char pl = 64;
	char u = 35;
	char v = 32;
};

void EmptyArray(int a[2][3]);
bool Check(int a[2][3], int &y, int &x);
void Insert(int a[2][3], int &y, int &x, int num);
void CreateLevel(int fl[2][3]);
void PrintLevel(int fl[2][3]);
void GetZero(int fl[2][3], int &, int &);
int GetRoom(player p, int fl[2][3]);