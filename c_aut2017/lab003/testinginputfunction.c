#include <stdio.h>

int main (void)
{
  int x = '\0';
  int y = '\0';

  scanf("%d", &x);
  scanf("%d", &y);
  printf("Your input is (%d,%d)", x, y);

  return 0;
}
