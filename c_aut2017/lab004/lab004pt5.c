#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
  char threeword[3];
  char threebackword[3];
  int i;
  int j;
  char transfer;
  char concat[8];

  printf("Enter a word with three letters> ");

  for(i=0; i<3; i++)
  {
    scanf("%c", &threeword[i]);
  }
  /* &threeword[3] == '\0'; */

  printf("Word entered: %s\n", threeword);

  /*
  The string-print worked for the input, threeword, but not threebackword,
  why? The threebackword kept printing both the reversed word and the straight
  word concatenated. Why is this?
  */

  for(i=2, j=0; j<3; i--, j++)
  {
    transfer = threeword[i];
    threebackword[j] = transfer;
  }
   /* &threebackword[3] == '\0'; */


  printf("Reverse word: ");

  for(i=0; i<3; i++)
  {
    printf("%c", threebackword[i]);
  }
  printf("\n");

/* This just prints it, doesn't save it as a separate array

  printf("%sX", threeword);

  for(i=0; i<3; i++)
  {
    printf("%c", threebackword[i]);
  }

  printf("\n");
*/

  /* Assign threeword to the first three elements */
  for(i=0; i<3; i++)
  {
    transfer = threeword[i];
    concat[i] = transfer;
  }

  /* Assign 'X' to the fourth element of concat */
  concat[3] = 'X';

  /* Assign backthreeword to last three elements */
  for(i=0, j=4; j<7; i++, j++)
  {
    transfer = threebackword[i];
    concat[j] = transfer;
  }

  /* Assign zero to the last element of concat */
  /* concat[8] = '\0'; */

  printf("%s\n", concat);

  return 0;
}
