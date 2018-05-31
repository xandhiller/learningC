#include <stdio.h>
#define FILENAME  "bloop.txt"

int main(void)
{
  FILE* fp;

  fp = fopen(FILENAME, "w");

  fprintf(fp, "Testing. Testing. Ground control to major Tom.\n");

  fclose(fp);

  return 0;
}
