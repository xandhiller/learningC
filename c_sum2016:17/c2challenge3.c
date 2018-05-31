#include <stdio.h>

int main(int argc, char const *argv[])
{

	char chrUsername;

	printf("You need to enter a username:  ");
	scanf("%c", &chrUsername);
	printf("\nYou will now be known as %8.c.\n", chrUsername);
    
	return 0;
}