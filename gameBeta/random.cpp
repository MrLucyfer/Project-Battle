#include <stdlib.h>
int Random(int min, int max) {
	int NumAleatori;
	NumAleatori = min + (rand() % (max - min + 1));
	return NumAleatori;
}
