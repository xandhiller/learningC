#include <stdio.h>
#include <string.h>

int main(void)
{
  char source[3];
  int transfer;
  int number;
  source[0] = 1;
  source[1] = 2;
  source[2] ='\0';

  transfer = (int)strcat(&source[0], &source[1]);

  number = transfer;
  printf("'transfer' is: %d\n", transfer);
  printf("typecasted 'transfer' is: %d\n", (int)transfer);
  printf("'number' is:%d\n", number);

  return 0;
}
