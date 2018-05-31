#include <stdio.h>

int main(void) {

  int a = '\0';
  int b = '\0';
  int c = '\0';

  a = 0;
  b = -1;

  c = (a || b);

  printf("%d\n", c);

  return 0;
}
