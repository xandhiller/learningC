#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkEnrolment(int enteredID);

int checkEnrolment(int enteredID)
{
  int enrolment;

  /* Below: checks if student is enrolled */
  char filename[20];

  sprintf(filename, "%d", CurrentSubject->ID);
  strcat(filename, SUBJECT_ENROLMENT_DATABASE);
  FILE* f;

  f = fopen(filename, "rb")
  if (f == NULL)
  {
    printf("Memory error.");
    return 1;
  }

  do
  {
    int IDsearch;
    fread(&IDsearch, sizeof(int), 1, f);

  } while(IDsearch != enteredID || fread(&IDsearch, sizeof(int), 1, f) != EOF);

  if ( IDsearch != enteredID ||
          fread(&IDsearch, sizeof(int), 1, f) != EOF)
  {
    enrolment = 0;
  }

  if ( IDsearch == enteredID )
  {
    enrolment = 1;
  }

  return enrolment;
}
