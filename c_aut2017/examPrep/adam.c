#include <stdio.h>
#define MAX_NUM 20

double getnumber(int numbers[]);

int main(void)
{
  int a[MAX_NUM];
  int i;
  double mean;
  for(i=0;i<5;i++)
  {
    a[i] = i+2;
  }
  a[5] = -1;

  mean = getnumber(a);
  printf("%lf", mean);
}

double getnumber(int numbers[])
{
  int sum = 0;
  int i;
  int sentnal = -1;

  for(i=0;i<MAX_NUM;i++)
  {
    if(numbers[i] == sentnal)
    {
      i--;
      break;
    }
    sum = sum + numbers[i];
  }
  if(i==0)
  return -1;
  else
  return (double)sum/(i+1);
}
