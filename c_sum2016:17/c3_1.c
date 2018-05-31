#include <stdio.h>

/*

Use Boolean operators to form complex if structures.
	
		'and' = &&
		'if' = ||

Boolean expressions are evaluated from left to right.

Also, nb: lower case and upper case letters are considered 
different inputs. 

*/

int main(int argc, char const *argv[])
{
    char cH ='\0';

    /*

    This is a witty program made to practice the use 
    of 'if' and 'else' statements, as well as boolean operators.

    */

    //Asks for user input of 'H' or 'h'.

	printf("Please enter the letter H (upper or lower case):\n\n\n");
	scanf("%c", &cH);

	//Makes it so that entering H is a 'correct' string.

    if (cH == 'H' || cH == 'h') {
    	printf("\n\n\tYou have entered correctly.\n\n\n");
    }
    	
    //The 'else' statement makes it so that anything else causes 'nukes' to be launched.
    
    else {
    	printf("\n\n\n\tIncorrect input. \n\n\tNukes launched.\n\n\n\n");
    }

	return 0;
	// End of program.
}