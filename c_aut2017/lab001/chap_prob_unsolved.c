#include <stdio.h>
#include <ctype.h>
#define ml_per_km_rate 1.609

double d_Ml; /*Define the 'miles' vairable*/
double d_Km; /*Define the 'kilometres' variable*/

int main(void) {

  printf("This program converts miles to kilometres,
  please enter the number of miles:\n\n");

  scanf(" %lf\n", &d_Ml);
  if (isdigit("%d", d_Ml) == 0) {
    printf("\tUnfortunatley, that is not a number
    and hence cannot be converted to kilometres.\n");
    }
    else {
      d_Km = (d_Ml * ml_per_km_rate);
      printf("\n\t\t %lf miles is equal to %lf
      kilometres.\n", d_Ml, d_Km);
  }
  return 0;
}

/* Query: Way to detect if not a number? Also, having issues with the
program needing to have a character entered (not solely the number to
be converted) in order to progress with the program and receive an output. */

/* Query sorted: use of ctype.h library and isdigit() function. Also capable
of doing a similar thing to test whether you have someone inputting letters
only. */
