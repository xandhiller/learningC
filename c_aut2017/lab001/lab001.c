#include <stdio.h>
#include <ctype.h>
#define conversion 29.57354942 /* Number of mL per fl oz. */

int main(void)
{
  double input = '\0';
  double output = '\0';
  /* isdigit(input); */

  /* Ask the user for input */
  printf("Please enter a volume in ounces:\n");

  /* Scan user's input */
  scanf("%lf", &input);

  /* Check if user input a number or letter */

  /* SILENCED

  if ( isdigit(input) )
  {
    output = input * conversion;
    printf("%lffl oz. is equal to %lfmL\n", input, output);
  }
  else
  {
    printf("Sorry, %lf is not a number.\n", input);
  }

  END SILENCE */

  /* convert the input to mL and set it to output. */
  output = input * conversion;

  /* Print the result to the user */
  printf("%lf fl oz. is equal to %lf mL\n", input, output);

  return (0);
}
