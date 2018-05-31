#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int *x;
  char *y;
  float *w;
  double *z;
  int n;

  n = sizeof(x);
  printf("%d\n", n);
  n = sizeof(y);
  printf("%d\n", n);
  n = sizeof(w);
  printf("%d\n", n);
  n = sizeof(z);
  printf("%d\n", n);


  return 0;
}
