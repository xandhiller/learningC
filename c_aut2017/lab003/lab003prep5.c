#include <stdio.h>

int main(void)
{
  int input = 1;

  printf("If you enter zero, this program will exit\n");
  printf("To start, ");

  while (input != 0)
  {
    for (input = 1; input != 0; scanf("%d", &input))
    {
      printf("your number is %d\n", input);
      printf("Enter a number> ");
    }
  }
  return 0;
}
