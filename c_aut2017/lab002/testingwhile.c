/*******************************************************************************
AUTHOR:  Alex Hiller
PROGRAM DESCRIPTION: Testing out the limits of while loops.
DATE OF COMPLETION:
COMPANY:
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int input ='0';

/*
  printf("Please enter any number>");
  scanf("%d", &input);
*/

  while ( input++ != 100)
  {
    printf("%d\n", &input);
  }

  return (0);
}
/*
Issues with the printing, it just prints the same number, over
and over again.
*/
