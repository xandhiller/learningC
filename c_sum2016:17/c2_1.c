#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* Initialise and declare variables */
	const float pi = 3.141592653589793;
	/* pi = '\0'; */

	/* Declare a value for it to a large amount of decimal places */
	/* pi = 3.141592653589793; */

	/* Print it out to see if it can show all the numbers */
	printf("Pi is approximately equal to %.9f \n", pi);	 
    
	return 0;
}

// Having an issue in printing the actual amount of digits. 
// It instead prints '3.141592741'.
// Why is this? Is this a limit of floating point numbers?
// Must we engineer around these constraints when bulding 
// 		programs that are supposed to print to many decimal 
//		places of specificity?