#include "UPASS.h"


char *cipher(char str[])
{
  int len = strlen(str);
  char a;
  int i, m;
  char cipher[3*MAX_PASSWORD_LENGTH];

  for (i=0, m=0; i<len; i++, m++)
  {
    int x, y, z;
    a = str[i];

    /*
    The 0, 4 and 2 in the three lines below can each be altered to any integer
    to create a key. The key must however stay constant so that the cipher
    remains constant and encrypted strings can be compared.
    */
    x = ((((int)a + 0)% 93) + 33);
    y = ((((int)a + 4)% 93) + 33);
    z = ((((int)a + 2)% 93) + 33);

    cipher[m] = (char)x;
    m++;
    cipher[m] = (char)y;
    m++;
    cipher[m] = (char)z;
  }
  cipher[m] = '\0';

  char *returnPointer = cipher;
  return returnPointer;
}
