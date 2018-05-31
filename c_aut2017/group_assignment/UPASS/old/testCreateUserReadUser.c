#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createUser.h"
#include "readUserDatabase.h"

#define MAX_PASSWORD_LENGTH 70
#define MAX_NAME_LENGTH 30

int main(void)
{
  int ID;
  char password[MAX_PASSWORD_LENGTH];



  printf("Create user starts now.\n");
  createUser();

  printf("Starting test for reading database.\n");

  printf("Enter user ID: ");
  scanf("%d", &ID);

  printf("Enter password: ");
  scanf("%s", password);
  strcpy(password, cipher(password));

  if ( (readUserDatabase(ID, password)) == 1)
  {
    printf("Successful login.\n");
  }

  if ( (readUserDatabase(ID, password)) == 0)
  {
    printf("Unsuccessful login.\n");
  }

  return 0;
}
