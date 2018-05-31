#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
  int size = 1;
  int* dynamicA = (int*)malloc(size*sizeof(int));

  int element, n;

  /* Ask for the input, then print the array */

  for (element=0; 1>0; element++)
  {
    printf("Enter a number: ");
    scanf("%d", &dynamicA[element]);

    size++;
    dynamicA = (int*)realloc(dynamicA, size*sizeof(int));

    printf("Array has %d elements and is:\n", element);
    /* print the array */
    for(n=0; n<=element; n++)
    {
      printf("[%d] ", dynamicA[n]);
    }
    printf("\n");
  }
  return 0;
}
