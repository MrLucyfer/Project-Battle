#pragma once
#include "Characters.h"
#include "Level.h"
void Movement(player &p, int dir);
void CheckColliders(player p, int fl[2][3], int options[]);
int MovementMenu(player p, int fl[2][3], int options[], char tp[]);
void CurrentPosition(player p, int fl[2][3], mapType);
void ClearRoom(int fl[2][3], player p);
void MovementLoop(player &p, int fl[2][3], int options[4], char tp[], mapType m);