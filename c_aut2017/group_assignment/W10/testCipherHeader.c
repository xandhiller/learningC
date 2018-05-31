#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cipherFunction.h"

#define MAX_PASSWORD_LENGTH 70

int main (void)
{
  char teststring[3*MAX_PASSWORD_LENGTH];
  printf("Enter test string> ");
  scanf("%s", teststring);

  strcpy(teststring, cipher(teststring));
  printf("Cipher string is: %s\n", teststring);

  return 0;
}
