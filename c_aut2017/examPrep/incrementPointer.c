#include <stdio.h>

int main (void)
{
  int* seed;
  printf("%p\n", seed);

  seed++;
  printf("%p\n", seed);

  return 0;
}
