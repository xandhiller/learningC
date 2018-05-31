#include <stdio.h>

int main(int argc, char const *argv[])
{
	int iRandom = '\0';

 
    // rand() will generate numbers of closed interval of 0 to approx 32,767.
    iRandom = (srand(time(NULL) % 10) * 1969) % 10;

    printf("\n\n\n\t %d \n\n\n", iRandom);


	return 0;
}