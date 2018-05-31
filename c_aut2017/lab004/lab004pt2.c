#include <stdio.h>
#include <math.h>
#include <string.h>

int main (void)
{
  /* Have to make the outputArray and inputArray doubles to make this work */
  double inputArray[4];
  double outputArray[4];

  /* Is the power you rase the base to in exponent function */
  double n;

  /* i is a counter */
  int i;

  printf("Enter 5 values separated by spaces> ");

  /* Cycles through inputArray and enters values for it */
  for (i=0; i<5; i++)
  {
    scanf("%lf", &inputArray[i]);
  }

  /* Taking in value of exponent */
  printf("Enter the value of n> ");
  scanf("%lf", &n);


  /* Prints out inputArray as per requirements */
  printf("Input array is: ");

  /* Cycles through the values of inputArray */
  for (i=0; i<5; i++)
  {
  printf("%.0lf ", inputArray[i]); /* Zero decimal places printed */
  }
  printf("\n");

  /* copies inputArray to outputArray then alters it accordingly */
  for (i=0; i<5; i++)
  {
    outputArray[i] = inputArray[i];
    outputArray[i] = pow(outputArray[i], n);
  }

  /* Printd out outputArray as per requirements */
  printf("Output array is: ");

  /* Cycles through the now altered values of outputArray */
  for (i=0; i<5; i++)
  {
  printf("%.0lf ", outputArray[i]); /* Zero decimal places printed */
  }

  /* Finishes off with a new line escape-sequence, so that the elements
  of outputArray could be on the same line */
  printf("\n");

  return 0;
}
