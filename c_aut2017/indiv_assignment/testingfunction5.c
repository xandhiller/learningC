#include <stdio.h>
#include <string.h>
#define DB_FILE_NAME "database"

int main (void)
{
  FILE* data;
  int length = 0;
  char array[750];
  /* int testnumber;*/

  data = fopen(DB_FILE_NAME, "r");

  fscanf(data, "%[^\t]", array);
  length = strlen(array);
  printf("Length of array is %d\n", length);

  /* nb: Each student's data will take up 30chars in database, everytime. */
  studentcount = (length % 30);

  /* Correctly assign the  */

  fclose(data);

  printf("The array contains: %s\n", array);

  return 0;
}
