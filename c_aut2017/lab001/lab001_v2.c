#include <stdio.h>
#include <ctype.h>
#define conversion 29.57354942 /* Number of mL per fl oz. */

int main(void)
{
  double a = 'a';
  double input = '\0';
  double output = '\0';
  isalpha(a);
  /* isdigit(input); */

  /* Ask the user for input */
  printf("Please enter a volume in ounces:\n");

  /* Scan user's input */
  scanf("%lf", &input);

  /* Check if user  */
  if (isalpha(input) == 0)
  {
    output = input * conversion;
    printf("%lf fl oz. is equal to %lf mL\n", input, output);

  }
  else
  {
    printf("Sorry, %lf is not a number.\n", input);
  }

  return (0);
}
