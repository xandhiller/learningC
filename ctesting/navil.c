#include <stdio.h>

struct numbers
{
  int num1;
  int num2;
  int num3;
  int num4;
};
typedef struct numbers numbers_t;

void func(numbers_t group[]);

int main (void)
{
  numbers_t arr[2];

  arr[0].num1 = 1;
  arr[0].num2 = 2;
  arr[0].num3 = 3;
  arr[0].num4 = 4;

  arr[1].num1 = 5;
  arr[1].num2 = 6;
  arr[1].num3 = 7;
  arr[1].num4 = 8;

  func(arr);
  func(arr);

  return 0;
}

void func(numbers_t group[])
{
  printf("%d\n", group[0].num1);
  printf("%d\n", group[0].num2);
  printf("%d\n", group[0].num3);
  printf("%d\n", group[0].num4);

  printf("%d\n", group[1].num1);
  printf("%d\n", group[1].num2);
  printf("%d\n", group[1].num3);
  printf("%d\n", group[1].num4);

  group[0].num1 = 9;
  group[0].num2 = 10;
  group[0].num3 = 11;
  group[0].num4 = 12;

  group[1].num1 = 13;
  group[1].num2 = 14;
  group[1].num3 = 15;
  group[1].num4 = 16;
}
