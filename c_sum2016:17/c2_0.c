#include <stdio.h>

int main()
{
	/* Declaring variables.
	Variables can be characters (char), integers (int) or pointers (float). */
	char firstInitial;
	char middleInitial1;
	char middleInitial2;
	char lastInitial;
	int x;

	/* Initialising variables. 
	This acts to clear the volatile memory that we are about to use.
	Volatile memory may be storing anything, it is apparently best to clear it before we begin. */ 
	
	x = 0;					/* Here, the '=' does not imply 'equals to', but instead 'is being assigned to'. 
								s.t. the statement would read: 0 is assigned to x. */
	firstInitial = '\0';	/* \0 is known as the null character. Must be in single quotes. */		
	middleInitial1 = '\0';
	middleInitial2 = '\0';
	lastInitial = '\0';

	/* What is above in the 'Initialising variables' section could also be used to declare these variables.
		This means you could save a couple of lines of code, but is that worth the sacrifice of clarity? */						


	firstInitial = 'A';
	middleInitial1 = 'M'; 
	middleInitial2 = 'J';
	lastInitial = 'H'; 

	printf("\n%c%c%c%c\n\n", firstInitial, middleInitial1, middleInitial2, lastInitial);
	return 0;
}