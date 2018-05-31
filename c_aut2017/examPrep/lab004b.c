/* Task 2, lab 4 */
#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE 5

int main (void)
{
  int inputArray[ARRAY_SIZE], outputArray[ARRAY_SIZE], n, m;
  /* m is a counter for loops */

  printf("Enter 5 values separated by a space: ");

  for(m=0; m<ARRAY_SIZE; m++)
  {
    scanf("%d", &inputArray[m]);
  }

  printf("Enter a value of n> ");
  scanf("%d", &n);

  printf("Input array is: ");
  for(m=0; m<ARRAY_SIZE; m++)
  {
    printf("%d ", inputArray[m]);
  }
  printf("\n");

  printf("Output array is: ");
  for(m=0; m<ARRAY_SIZE; m++)
  {
    outputArray[m] = pow(inputArray[m], n);
    printf("%d ", outputArray[m]);
  }
  printf("\n");

  for(m=0, n=-200000; m<ARRAY_SIZE; m++)
  {
    if (n<outputArray[m])
    {
      n = outputArray[m];
    }
  }
  printf("Maximum value of the output array is: %d\n", n);

  return 0;

}
