#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
  char b = 'b';
  printf("The ASCII value of b is: %d\n", (int)b);

  int i;

  for (i=0; i<93; i++)
  {
    printf("The number is %d and the ASCII character is '%c'\n", i, ((char)i%93)+33);
  }

  return 0;
}
