#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int n;
  int m;

  FILE* fp;

  fp = fopen("binf1", "wb");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }

  for(n=0; n<7; n++)
  {
    fwrite(&n, sizeof(n), 1, fp);
  }
  fclose(fp);


  fp = fopen("binf1", "rb");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }

  for (m=0; m<7; m++)
  {

    fread(&m, sizeof(m), 1, fp);
    fprintf(stdout, "%d\n", m);
    fclose(fp);
  }

  /*
  If you close the file, the pointer for where you are in the file is lost.
  If you keep the file open, then the pointer for where you are in the file
  is saved and you can keep reading and writing.
  */

  return 0;

}
