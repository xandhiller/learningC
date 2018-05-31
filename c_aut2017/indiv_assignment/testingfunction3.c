#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
  int i;
  char listHeading[26];
  int studentcount = 4;
  char name[11];
  int birthday = 4;
  int birthmonth = 2;
  int birthyear = 1994;
  float gpa = 4;

  strcpy(name, "Alex");

  strcpy(listHeading, "Name       Birthday   GPA");
  printf("%s\n", listHeading);

  for (i=0; i<10; i++)
  {
    printf("-");
  }
  printf(" ");

  for (i=0; i<10; i++)
  {
    printf("-");
  }
  printf(" ");

  for (i=0; i<6; i++)
  {
    printf("-");
  }
  printf("\n");

  for (i=0; i < studentcount; i++)
  {
    printf("%-11s", name);
    printf("%02d-%02d-%d ", birthday, birthmonth, birthyear);
    printf("%.4f", gpa);
    printf("\n");
  }
  printf("\n");



  return 0;
}
