#include <stdio.h>

int main(int argc, char const *argv[])
{
	float fltX;
	float fltY;
	float fltA;
	float fltB;
    
    // Ask for the input of x, y, a and b.
    printf("\nThis program will solve for the equation: (a-b)*(x-y)\n");

	// Input for 'a'
    printf("Please enter the value for 'a':    \n");
	scanf("%f", &fltA);

	// Input for 'b'
    printf("Please enter the value for 'b':    \n");
	scanf("%f", &fltB);	

    // Input for 'x' 
    printf("Please enter the value for 'x':    \n");
	scanf("%f", &fltX);

	// Input for 'y'
    printf("Please enter the value for 'y':    \n");
	scanf("%f", &fltY);

	printf("%f \n", (fltA - fltB)*(fltX - fltY));

	return 0;
}