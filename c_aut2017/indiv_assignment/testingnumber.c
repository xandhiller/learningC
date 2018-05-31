#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  char a[50];
  int b;
  scanf("%s", a);
  b = atoi(&a[0]);

  printf("\n");

  if (b % 1 == 0)
  {
    printf("The number is %d, it works\n", b);
  }
  else
  {
  printf("it doesn't work\n");
  }
  return 0;
}
