#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createUser.h"
#include "readUserDatabase.h"

#define MAX_PASSWORD_LENGTH 70
#define MAX_NAME_LENGTH 30

/*
Returns 1 if success, 0 if fail, -1 to exit program.
Returns 2 if function logic fails.
*/

int login(void);

int login(void)
{
  /*
  Opening file checks if there is an existing database.
  If there is not, it makes the program user create an admin.
  If there is a database it will follow a standard login.
  */
  FILE* fp;
  fp = fopen(USER_DATABASE, "r");
  if (fp == NULL)
  {
    printf("No database exists.\n"
           "You will have to create an administrator.\n");
    createUser();
    printf("Now, please login.\n");
  }
  fclose(fp);


  int i = 100; /* Input */
  int enteredID;
  char enteredPswrd[MAX_PASSWORD_LENGTH];


  while ( i != 0)
  {
    /* intakes either the user ID or -1 */
    printf("Enter user ID or enter 0 to exit: ");
    scanf("%d", &i);

    /* Exit program if input was -1 */
    if (i == 0)
    {
      return 0;
    }
    else
    {
      int r;

      /* Set the input as ID  */
      enteredID = i;
      printf("Enter your password (note, it will appear on-screen): ");
      scanf("%s", enteredPswrd);

      r = readUserDatabase(enteredID, enteredPswrd);

      if (r == 0)
      {
        /*
        Result of read database determined that either the username
        or password was incorrect
        */
        printf("User ID or incorrect password, please try again.\n");
      }


      if (r == 1)
      {
        /* Successful login */
        printf("Successful login.\n"); /* We can remove this print statement */
        return 1;
      }
    }
  }
  return 2;
}





/* PSEUDOCODE from group brainstorm below.  */

/*
int login(void){
  user_t* usersLL = readdatabase;
  int ID;

if login not true or ID == -1, continue to try login.




  printf("Enter ID: ");
  scanf
  user enters id
  for(all users in database)
    if userid == userid
      user enters password
      if match
        return userid\

  user id != database
}

when the program starts up we need a userLL, so do this at boot up*/
