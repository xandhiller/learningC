#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
	int cGuess;
	int cRandom;
	srand(time(NULL));

	printf("\n\n\tWe're gonna play a game.\n");
	printf("\n\tI'm thinking of a number between 1 and 10.\n");
	printf("\n\tIf you guess it correctly, you win.");
	printf("\n\tIf not, I win.\n\n\n\n");

	scanf("%d", &cGuess);

	cRandom = (srand(time(NULL))%10)+1;

	if (isdigit(cGuess))
	{
		if (cGuess > 0 && cGuess < 11)
		{
			if (cGuess == cRandom) // Checks if guess equals randomly generated number.
			{
				printf("You're correct, woo!\n");

			}
			else { // Guess not correct
				printf("Oh bugger, you're wrong. Sorry!\n");
			}
		}
		else {
			printf("That is not a number between 1 and 10.\n");
		}
	}
    else{
    	printf("That is not a number.\n");
    }

	return 0;
}