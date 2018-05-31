#include <stdio.h>
#include <string.h>

int main(void)
{
  char a[50];

  FILE * pFile;

  pFile = fopen ("testingfileprocessing.txt","w");
  fprintf(pFile, "teststring");


  pFile = fopen ("testingfileprocessing.txt","r");
  fscanf(pFile, "%s", &a);
  fclose (pFile);

  printf("%s\n", a);

  return 0;
}
