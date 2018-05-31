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


  return 0;
}
