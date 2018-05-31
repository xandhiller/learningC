
#include <stdio.h>

int main(void)
{
  /* Declare input variables */
  int num ='\0';
  int den ='\0';
  /* Declare output/displayed variables */
  int number_display = '\0';
  int fraction_display = '\0';

  /* Ask the user for input */
  printf("Enter the numerator and denominator separated by a space>");
  scanf("%d", &num); /* Will this work? */
  scanf("%d", &den);

  fraction_display = num % den;
  number_display = num / den;

  if (fraction_display == 0)
  {
    printf("%d\n", number_display);
  }

  else if (number_display == 0)
  {
    printf("%d/%d\n", fraction_display, den);
  }

  else
  {
  printf("%d %d/%d\n", number_display, fraction_display, den);
  }
  return 0;
}
