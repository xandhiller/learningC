#include <stdio.h>

int main(void) {

  float a = '\0';
  float b = '\0';
  float c = '\0';

  a = 0;
  b = -1;

  c = (a || b);

  printf("%f\n", c);

  return 0;
}
