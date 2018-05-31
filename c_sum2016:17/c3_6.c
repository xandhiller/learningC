#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{ 
	int cRandom;
	rand(void 3);

	cRandom = (rand(void 3));
	cRandom = (cRandom % 10) + 1;

    printf("%d\n", cRandom);

	return 0;
}