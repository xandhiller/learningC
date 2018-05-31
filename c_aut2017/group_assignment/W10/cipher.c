#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 70




/* char cipher(char password[]);*/

int main (void)
{
  #ifdef TEST
  char inputString[MAX_PASSWORD_LENGTH];
  char returnString[MAX_PASSWORD_LENGTH];
  printf("Input test password: ");
  scanf("%s", inputString);

  returnString = (cipher(inputString));

  printf("Password is: %s\n"
          "cipher is: %s\n",
        inputString, returnString);

  #endif

  /* Just trying to get the fucking thing working */
  char inputString[MAX_PASSWORD_LENGTH];
  printf("Input test password: ");
  scanf("%s", inputString);
  /* End of me declaring non-function related variables */

  /* Function code went here */
  int len = strlen(inputString);
  int j, n, m;
  char cipher[MAX_PASSWORD_LENGTH];


  for(n=0, j=0; n<len; n++)
  {
    for(m=0; m<3; m++, j++)
    {
      strcat(cipher[j], ((int)inputString[n] + m*27)%93) + 33));
    }
  }
  /* End of function code */

  printf("%s\n", cipher);


  return 0;
}

/* char cipher(char password[])
{


  return cipher;
} */
