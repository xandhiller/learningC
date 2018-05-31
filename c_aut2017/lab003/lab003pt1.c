#include <stdio.h>

int main(void)
{
  int mark = '\0';

  printf("Please enter the student's mark> ");
  scanf("%d", &mark);

  if (mark <= 0) {
    printf("Impossible, check the mark again.\n");
  }
  else if (mark > 0 && mark <50) {
    printf("Z - Pity you failed, try harder next time.\n");
  }
  else if (mark >= 50 && mark <= 100) {
    printf("P - Congratulations, way to go.\n");
  }
  else if (mark > 100) {
    printf("Too awesome for the class, check the input again.\n");
  }
  return 0;
}
