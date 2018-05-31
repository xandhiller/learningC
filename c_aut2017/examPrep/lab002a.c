#include <stdio.h>

int main(void)
{
  int num, den; /* Integers for the numerator (num) and denominator (den) */
  printf("Enter your numerator: ");
  scanf("%d", &num);

  printf("Enter your denominator: ");
  scanf("%d", &den);

  printf("Mixed fraction is: %d %d/%d\n", (num/den), (num%den), den);

  return 0;
}
