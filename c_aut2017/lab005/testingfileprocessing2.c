#include <stdio.h>
#include <string.h>

int main(void)
{
  char a[50];
  int n = 2;

  FILE * pFile;

  pFile = fopen ("testingfileprocessing%d.txt","w");
  if (pFile == 0)
  {
    printf("File error\n");
    return 1;
  }
  /* fprintf(pFile, "teststring2\n"); */
  fprintf(pFile, "teststring3\n");
  fclose (pFile);

  pFile = fopen ("testingfileprocessing%d.txt","w");
  if (pFile == 0)
  {
    printf("File error\n");
    return 1;
  }
  /* fprintf(pFile, "teststring2\n"); */
  fprintf(pFile, "teststring4\n");
  fclose (pFile);

  for(n=0; n<3; n++)
  {
  pFile = fopen ("testingfileprocessing%d.txt","r");
  if (pFile == 0)
  {
    printf("File error\n");
    return 1;
  }
  fscanf(pFile, "%s", &a[n]);
  fclose (pFile);
  }

  printf("%s\n", a);

  return 0;
}
