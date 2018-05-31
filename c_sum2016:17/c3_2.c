#include <stdio.h>
#include <ctype.h>

/*

The isdigit() function is used to tell you whether what has been entered
by the user is a digit or not. It will be 'true' if it's a digit, and
'false' if it is not. 

The isdigit() function can only take one variable inside of it, apparently.

It also appears that it has to be a 'char' variable that is passed into it.
I tried doing it with a float, but it just evaluated the whole thing 
as true, no matter what was entered (note, that I use a isdigit() false as my 'if' condition).

*/

int main(int argc, char const *argv[])
{
	// I chose R as the variable name because the number will be 
	// contained in the set of Real numbers.
	// The 'f' is, as per convention, set because the variable is a 'float'.

	char fR = '\0';
    
    printf("\n\n\tPlease enter a letter:\n\n\n\t");
    scanf("%c", &fR);

	if ( isdigit(fR) == 0)
	{
		printf("\n\n\tThat's great! You're now my puppet.\n\n\n\n");
	}
	else {
		printf("\n\n\n\tWay to be rebellious. But now the program is over.\n\n");
	}
	return 0;
}