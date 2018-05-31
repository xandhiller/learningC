#include <stdio.h>

int main(void)
{
  char a[30];
  char b[30];
  char c[30];
  char filename[30];
  char result[93];

  /* Assign some stuff to a, b and c. */
  printf("a is> ");
  scanf("%s", a);
  printf("b is> ");
  scanf("%s", b);
  printf("c is> ");
  scanf("%s", c);

  FILE *file;

  printf("File name is> ");
  scanf("%s", filename);

  /*  Tell user that you're writing to a file */
  printf("\nWriting to %s...\n", filename);

  file = fopen(filename, "w");
  fprintf(file, "%s %s %s", a, b, c);
  fclose(file);

  file = fopen(filename, "r");
  fscanf(file, "%[^\0]", result);
  fclose(file);

  printf("\nPrinting from %s...\n", filename);
  printf("\n\n\t%s\n\n", result);


  return 0;
}
