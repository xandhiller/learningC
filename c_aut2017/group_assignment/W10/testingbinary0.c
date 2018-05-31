#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  char input[30];
  char output[30];

  fprintf(stdout, "Enter input: ");
  fscanf(stdin, "%s", input);

  FILE* fp;

  fp = fopen("binf", "wb");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }

  fwrite(input, sizeof(input), 1, fp);

  fclose(fp);

  fp = fopen("binf", "rb");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }

  fread(output, sizeof(output), 1, fp);

  fprintf(stdout, "Output is: %s\n", output);

  fclose(fp);


  return 0;
}
