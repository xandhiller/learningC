#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_ID_DATABASE "ProgramUsersIDandPrivelige.bin"
#define USER_NAME_DATABASE "ProgramUsersName.txt"
#define USER_PASSWORD_DATABASE "ProgramUsersPassword.txt"
#define MAX_PASSWORD_LENGTH 70
#define MAX_NAME_LENGTH 30

int readUserDatabase(int userID, char cipherPassword[]);

int readUserDatabase(int userID, char cipherPassword[])
{
  FILE* fp;
  fp = fopen(USER_ID_DATABASE, "rb");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }



  int comparison;
  char passwordCheck[3*MAX_PASSWORD_LENGTH];

  while ( !(feof(fp)) == 0 || comparison != userID)
  {
   fread(&comparison, sizeof(comparison), 1, fp);
  }


  if ( comparison == userID )
  {
    fclose(fp);
    fp = fopen(USER_PASSWORD_DATABASE, "r");
    if (fp == NULL)
    {
      fprintf(stdout, "Memory error");
      return 2;
    }

    while ( !(feof(fp)) == 0 || (strcmp(passwordCheck, cipherPassword)) != 0)
    {
      fscanf(fp, "%[^\n]s", passwordCheck);
    }

    if ( strcmp(passwordCheck, cipherPassword) == 0 )
    {
      return 1; /* Password match */
    }

    if ( strcmp(passwordCheck, cipherPassword) != 0 )
    {
      printf("Password or username was incorrect.\n");
      return 0; /* Password no match */
    }

    if ( !(feof(fp)) == 0 )
    /*
    If you reach the end of the password database and they're not there
    then return an ambiguous "password or username was incorrect". This
    is best security practice
    */
    {
      printf("Password or username was incorrect.\n");
      return 0;
    }
  }

  if ( !(feof(fp)) == 0 )
  {
    printf("Password or username was incorrect.\n");
    return 0;
  }

  return 5;
}
