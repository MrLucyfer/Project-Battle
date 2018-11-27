#pragma once
#include "Characters.h"
#include "Level.h"
void Movement(player &p, int dir);
void CheckColliders(player p, int options[]);
int MovementMenu(player p, level fl[][3], int options[], char tp[]);
void CurrentPosition(player p, level fl[2][3], mapType);
void MovementLoop(player &p, level fl[2][3], int options[4], char tp[], mapType m);