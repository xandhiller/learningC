/* Testing how modulo works */
#include <stdio.h>

int main(void)
{
  int dividend = '\0';
  int divisor = '\0';
  int c = '\0';

  printf("Let's find the modulus of some shit!\n");
  printf("Enter the dividend>");
  scanf("%d", &dividend);

  printf("\nEnter the divisor>");
  scanf("%d", &divisor);

  c = dividend % divisor;

  printf("\n%d\n", c);

  return 0;
}
