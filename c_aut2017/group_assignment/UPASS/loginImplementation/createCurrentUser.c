#include "UPASS.h"

/*
INPUT: a user ID
OUTPUT: a user_t type pointer for the current user with values assigned to all
variables of the struct, as read from the database.

TLDR: It reads the user database and returns the info on the current user.

NOTE: You should only use this function when the login has returned a valid
response.
*/

user_t* createCurrentUser(int userID);

/* This function should only be called in the event of a successful login */
user_t* createCurrentUser(int userID)
{
  /* Initialise current user variable */
  user_t* currentUser = (user_t*)malloc(sizeof(user_t));

  /* We won't use the 'next' pointer for current user, so set it to NULL */
  currentUser->next = NULL;



  /* Open the user database */
  FILE* fp;
  fp = fopen(USER_DATABASE, "r");
  if (fp == NULL)
  {
    printf("Memory error\n");
  }



  while ( userID != currentUser->ID)
{
  /*
  Whilst the given ID doesn't equal the one found in the database,
  it will keep reading the user database file
  */

  fscanf(fp, "%d", &currentUser->ID);
  fscanf(fp, "%*[\t]"); /* Absorb the tab */
  fscanf(fp, "%[^\t]s", currentUser->name); /* Skip over the name */
  fscanf(fp, "%*[\t]"); /* Read-only the tab after the name */

  fscanf(fp, "%[^\t]s", currentUser->password);
  fscanf(fp, "%d", &currentUser->privilege);
  fscanf(fp, "%*[\n]"); /* Absorb the new line character */

  if ( userID == currentUser->ID)
  {
    break;
  }

  if(feof(fp))
  {
    /*
    If the end of the file was reached, this function was incorrectly used.
    Only valid user IDs should be passed to this function.
    But this is here just for future-proofing purposes anyway.
    */
    printf("User not found.\n");
    currentUser->ID = 0;
    strcpy(currentUser->name, "[Empty]");
    strcpy(currentUser->password, "[Empty]");
    currentUser->privilege = 0;

    return currentUser;
  }
}
  return currentUser;
}
