#include <stdio.h>
#include <math.h>
#include <string.h>

int main (void)
{
  char inputArray[6];

  printf("Enter 5 values separated by spaces> ");

  scanf("%s", &inputArray[0]);
  scanf("%s", &inputArray[1]);
  scanf("%s", &inputArray[2]);
  scanf("%s", &inputArray[3]);
  scanf("%s", &inputArray[4]);

  printf("Input array is: %s\n", inputArray);


  return 0;
}
