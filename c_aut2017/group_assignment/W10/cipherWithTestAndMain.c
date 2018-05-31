#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 70
#define TEST

int main (void)
{
  #ifdef TEST
  printf("\n\nYou are currently in the test mode of the cipher function.\n"
          "This cipher intakes each character into a string and replaces "
          "it with three randomised letters.\nIt does this by casting the "
          "the characters as numbers, numerically altering them and then "
          "casting them as\ncharacters again. Once they're converted back into "
          "characters, it saves them to a cipher string.\nThis cipher string "
          "can be saved and/or encrypted.\nHave a go!\n");
  #endif

  char inputString[MAX_PASSWORD_LENGTH];
  printf("NOTE: Be wary of who is looking at your screen, your password will"
          " appear on screen.\n\n"
          "Input your password, then press enter> ");
  scanf("%70[^\n]", inputString);

  int len = strlen(inputString);
  char a;
  int i, m;
  char cipher[3*MAX_PASSWORD_LENGTH];

  #ifdef TEST
  printf("\n\nValue of strlen is: %d\n", len);
  #endif


  for (i=0, m=0; i<len; i++, m++)
  {
    #ifdef TEST
    printf("\n\nValue of m at the beginning of loop %d is: %d\n", i, m);
    #endif

    int x, y, z;
    a = inputString[i];

    /*
    The 1, 2 and 3 in the three lines below can be altered to any integer
    for extra randomness. But it must be the same constant numbers so that
    the cipher is constant.
    */
    x = ((((int)a + 0)% 93) + 33);
    y = ((((int)a + 4)% 93) + 33);
    z = ((((int)a + 2)% 93) + 33);

    #ifdef TEST
    printf("\n\nIn loop %d the variables are:\nx = %d\ny = %d\nz = %d\n",
            i, x, y, z);
    #endif

    cipher[m] = (char)x;
    m++;
    cipher[m] = (char)y;
    m++;
    cipher[m] = (char)z;

    #ifdef TEST
    printf("\n\nValue of m at the end of loop %d is: %d\n", i, m);
    printf("Loop %d the cipher is: %s\n", i, cipher);
    #endif
  }

  #ifdef TEST
  printf("\n\nCipher is: %s\n", cipher);
  #endif

  return 0;
}
