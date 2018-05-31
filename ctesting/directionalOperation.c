#include <stdio.h>
#define LIM 1000



int main (void)
{
  int a;
  int b;

  int aba[LIM*LIM];
  int bab[LIM*LIM];

  long trueCount = 0;
  long falseCount = 0;

  for (a=0; a<=LIM; a++)
  {
    for (b=0; b<=LIM; b++)
    {
      aba[b] = (a^b)^a;
      bab[b] = (b^a)^b;

      if (a == b)
      {
        trueCount++;
        break;
      }

      if ( ( (a^b)^a ) == ( (b^a)^b ) )
      {
        printf("Iteration: %d\na = %d\nb = %d\n", a,a,b);
        printf("True\n");
        trueCount++;
      }

      else
      {
        falseCount++;
      }

    }
  }

  printf("Final count is:\nFalses: %ld\nTrues: %ld\n", falseCount, trueCount);

  for (b=0, trueCount=0; b<(LIM*LIM); b++)
  {
    if ( aba[b] == bab[b] )
    {
      trueCount++;
    }
    else
    {
      falseCount++;
    }
  }
  printf("Number of independent solutions is: %ld\nNumber of overlapping solutions is: %ld\n", falseCount, trueCount);

  return 0;
}
