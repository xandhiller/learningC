#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cipherFunction.h"

#define USER_ID_DATABASE "ProgramUsersIDandPrivelige.bin"
#define USER_NAME_DATABASE "ProgramUsersName.txt"
#define USER_PASSWORD_DATABASE "ProgramUsersPassword.txt"
#define MAX_PASSWORD_LENGTH 70
#define MAX_NAME_LENGTH 30

/* #ifndef _USER_T_
#define _USER_T_ */
/*ID Format - 2[UserID]*/
/* struct user{
  int ID;
  char name[MAX_NAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int privilege;
  struct user* next;
}; */

/* typedef struct user user_t; */


int createUser(void);

int createUser(void)
{
  int ID;
  char name[MAX_NAME_LENGTH];
  char password[3*MAX_PASSWORD_LENGTH];
  int privilege;

  char passwordTest[MAX_PASSWORD_LENGTH];

  FILE* fp;
  fp = fopen(USER_ID_DATABASE, "ab");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }

  printf("Enter user ID: ");
  scanf("%d", &ID);
  fwrite(&ID, sizeof(ID), 1, fp);

  printf("Enter user privilege: ");
  scanf("%d", &privilege);
  fwrite(&privilege, sizeof(privilege), 1, fp);

  fp = fopen(USER_NAME_DATABASE, "a");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }

  printf("Enter user name: ");
  scanf("%s", name);
  fprintf(fp, "%s\n", name);

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

  strcpy(password, cipher(password)); /* Converts the password to the cipher */

  fclose(fp);

  fp = fopen(USER_PASSWORD_DATABASE, "a");
  if (fp == NULL)
  {
    fprintf(stdout, "Memory error");
    return 1;
  }
  fprintf(fp, "%s\n", password);

  fclose(fp);

  return 0;
}
