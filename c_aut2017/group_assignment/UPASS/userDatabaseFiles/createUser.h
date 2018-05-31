#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cipherFunction.h"
 
#define USER_DATABASE "ProgramUsers.txt"
#define MAX_PASSWORD_LENGTH 70
#define MAX_NAME_LENGTH 30

/* Return 0 on success, returns -1 on memory failure */

int createUser(void);

int createUser(void)
{
  int ID;
  char name[MAX_NAME_LENGTH];
  char password[3*MAX_PASSWORD_LENGTH];
  int privilege;

  char passwordTest[MAX_PASSWORD_LENGTH];

  /* Opening file user database for appending */
  FILE* fp;
  fp = fopen(USER_DATABASE, "a");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return -1;
  }

  /* Intake new user information */
  printf("Enter user ID: ");
  scanf("%d", &ID);

  printf("Enter user privilege: ");
  scanf("%d", &privilege);

  printf("Enter user name: ");
  scanf("%s", name);

do
  {
    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter password again: ");
    scanf("%s", passwordTest);

    if( strcmp(passwordTest, password) != 0)
    {
      printf("Passwords don't match. Please enter again.\n");
    }

  } while ( strcmp(passwordTest, password) != 0);

  /* Converts the password to the cipher */
  strcpy(password, cipher(password));

  /* Write to the database */
  fprintf(fp, "%d\t", ID);
  fprintf(fp, "%s\t", name);
  fprintf(fp, "%s\t", password);
  fprintf(fp, "%d\n", privilege);

  fclose(fp);

  return 0;
}
