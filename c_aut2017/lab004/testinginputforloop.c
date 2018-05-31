#include <stdio.h>
#include <math.h>
#include <string.h>

int main (void)
{
  char inputArray[5];
  int i;

  printf("Enter 5 values separated by spaces> ");

  for (i=0; i<6; i++)
  {
    scanf("%s", &inputArray[i]);
  }

  printf("Input array is: %s\n", inputArray);


  return 0;
}
