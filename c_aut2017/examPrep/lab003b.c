/* lab003, task 5 */
#include <stdio.h>

int main (void)
{
  int a, b;

  for(a=1; a<4; a++)
  {
    for(b=a; b>0; b--)
    {
      printf("* ");
    }
    printf("\n");
  }

  for(NULL; a>0; a--)
  {
    printf("* * * *\n");
  }

  for(a=3; a>0; a--)
  {
    for(b=a; b>0; b--)
    {
      printf("* ");
    }
    printf("\n");
  }
  return 0; 
}
