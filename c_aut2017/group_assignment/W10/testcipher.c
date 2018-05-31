#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 70

int main (void)
{

  char inputString[MAX_PASSWORD_LENGTH];
  printf("Input test password: ");
  scanf("%s", inputString);

  int len = strlen(inputString);
  int j, n, m;

  for(n=0, j=0; n<len; n++)
  {
    for(m=0; m<3; m++, j++)
    {
      printf("%d", ((((int)inputString[n] + m*27)%93) + 33));
    }
  }


  return 0;
}

3865924875102517810551781055178105517810551781055279106
blooooop
