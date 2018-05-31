#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 70

char cipher(char str[]);

char cipher(char str[])
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
    The 1, 2 and 3 in the three lines below can each be altered to any integer
    to create a key. The key must however stay constant so that the cipher
    remains constant and encrypted strings can be compared.
    */
    x = ((((int)a + 1)% 93) + 33);
    y = ((((int)a + 2)% 93) + 33);
    z = ((((int)a + 3)% 93) + 33);

    cipher[m] = (char)x;
    m++;
    cipher[m] = (char)y;
    m++;
    cipher[m] = (char)z;
  }

  return cipher[0];
}
