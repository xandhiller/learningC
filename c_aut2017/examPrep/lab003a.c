#include <stdio.h> /* printf, scanf */

int main (void)
{
  double input, n, m;
  printf("Enter the number for factorial-ing: ");
  scanf("%lf", &input);

  for(n=input, m=1; n>1; n--)
  {
    m = n*m;
  }
  printf("%lf! = %lf\n", input, m);
  return 0;
}
