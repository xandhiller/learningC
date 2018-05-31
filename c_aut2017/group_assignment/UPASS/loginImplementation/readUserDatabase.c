#include "UPASS.h"

/*
Return -1 if no database.
Return 1 if their entered ID and password match up to a pair in the database.
Return 0 if either the ID or the password is not correct.
*/

int readUserDatabase(int userID, char cipherPassword[])
{
  /* Open the user database */
  FILE* fp;
  fp = fopen(USER_DATABASE, "r");
  if (fp == NULL)
  {
    fprintf(stdout, "No database exists.\n");
    return -1;
  }

  int IDcomparison = -1;
  char passwordComparison[3*MAX_PASSWORD_LENGTH];

  #ifdef DEBUG
  int i, testPriv;
  i = 0;
  testPriv = 0;
  #endif

  while ( userID != IDcomparison)
  {
    fscanf(fp, "%d", &IDcomparison);
    fscanf(fp, "%*[\t]");
    fscanf(fp, "%*[^\t]s"); /* Skip over the name */
    fscanf(fp, "%*[\t]"); /* Read-only the tab after the name */

    fscanf(fp, "%[^\t]s", passwordComparison);
    fscanf(fp, "%*d"); /* Skip over the privilege */
    fscanf(fp, "%*[\n]");

    #ifdef DEBUG
    i++;
    printf("Reading database.\n Cycle %d\nID is: %d\n", i, IDcomparison);
    printf("Password is: %s\n", passwordComparison);
    /* printf("privilege is: %d\n", testPriv);*/
    #endif


    if(feof(fp))
    {
      break;
    }


  }
  /* Password comparison doesn't match && ID comparison doesn't match */

  #ifdef DEBUG
  printf("Password read from the database is: %s\n"
         "Password entered into the function: %s\n",
          passwordComparison, cipherPassword);
  #endif

if ( (strcmp(cipherPassword, passwordComparison) == 0)
      && (userID == IDcomparison)  )
{
  /* Successful login */
  return 1;

} else
{
  /* Unsuccessful login */
  return 0;
}

  /* Program should not reach this stage */
}
