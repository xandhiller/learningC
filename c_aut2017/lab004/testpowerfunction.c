#include <stdio.h>
#include <math.h>

int main(void)
{
  double b;
  double e;

  printf("Enter base> ");
  scanf("%lf", &b);

  printf("Enter exponent> ");
  scanf("%lf", &e);

  printf("%.2lf ^ %.2lf = %.2lf\n", b, e, pow(b,e));
  return 0;
}
