#include <stdio.h>

int main(void)
{
  int a;
  int b;

  for (a=1; a<4; a++)
  {
    for (b=a; b>0; b--)
    {
      printf("* ");
    }
    printf("\n");
  }

  for (a=4; a>0; a--)
  {
    printf("* * * *\n");
  }

  for (a=3; a>0; a--)
  {
    for (b=a; b>0; b--)
    {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}
