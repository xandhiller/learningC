#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{

	char cR = '\0';
    
    printf("\n\n\tPlease enter a letter:\n\n\n\t");
    scanf("%c", &cR);

	if (isdigit(cR)) {
		printf("\n\n\tWay to be rebellious, you free thinker, you.\n\n\n\n");
	}
	else {
		printf("\n\n\n\tThink for yourself, don't be a sheep.\n\n\n\n");
	}
	return 0;
}