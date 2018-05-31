#include <stdio.h>
#include <string.h>
#include <math.h>

int palindrome(char wordin, int length);

int main(void)
{
  int i;
  int length;
  char wordin[15];

  for (i=0; i<16; i++)
  {
    scanf("%c\n", &wordin[i]);

    if ((wordin[i] == '\n') && (wordin[--i] == 0))
    {
      length = i;
      i = 16;
    }
  }

  /* Pass wordin to palindrome function */

  /* Print result */
  if( palindrome(wordin, length) == 1 )
  {
    printf("The word that has been input is not a palindrome.\n");
  }
  else if ( palindrome(wordin, length) != 1 )
  {
    printf("The word that has been input is a palindrome.\n");
  }

  return 0;
}

int palindrome(char wordin, int length)
{
  int eval;
  int i;
  int j;
  int lengthhalf = length/2;

  for (i=0, length; i<=lengthhalf; i++, length--)
  {
    if ( (wordin[i]) == (wordin[j]) )
    {
      eval = 1;
    }
    else if ( (wordin[i]) != (wordin[j]) )
    {
      eval = 0;
    }
  }

  return eval;
}
