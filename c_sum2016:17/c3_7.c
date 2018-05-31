#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  srand (time(NULL));

  int r = (rand()%10) + 1;

  printf("\n \n \t \t %d \n \n", r);
  return 0;
}
