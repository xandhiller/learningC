#include <stdio.h>

int main(int argc, char const *argv[])
{
	int iResponse = '\0';

	// Categories for user to select from.

	printf("\n\n\tPlease select one of the following:\n\n");
	printf("\t1. Sports\n");
	printf("\t2. Literature\n");
	printf("\t3. History\n");

	scanf("%d", &iResponse);

	// Switch responses.

	switch(iResponse){
		case 1:
            printf("You chose Sports.\n");
            break;
        case 2:
            printf("You chose Literature.\n");
            break;
        case 3:
            printf("You chose History.\n");
            break;
        default:
            printf("No, not a valid input.\n");
            break;
	}
	return 0;
}