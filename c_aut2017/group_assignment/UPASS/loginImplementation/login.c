#include "UPASS.h"
#include "createUserLL.c"
#include "createUser.c"
#include "readUserDatabase.c"

/*
Returns 0 if unsuccesful
Returns student ID if successful
Returns -1 if person using the program wants to exit
*/

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

  printf("\nATTENTION:\n"
        "Enter -1 for User ID to exit.\n"
        "Typed password will appear on-screen.\n");

  while ( 1 > 0 )
  {
    /* intakes either the user ID or -1 */
    printf("\n\t--LOGIN--\n"
          "\tUser ID: ");
    scanf("%d", &i);

    /* Exit program if input was -1 */
    if (i == -1)
    {
      return -1;
    }
    else
    {
      int r;

      /* Set the input as ID  */
      enteredID = i;
      printf(
              "\tPassword: ");
      scanf("%s", enteredPswrd);

      strcpy(enteredPswrd, cipher(enteredPswrd));

      r = readUserDatabase(enteredID, enteredPswrd);

      if (r == 0)
      {
        /*
        Result of read database determined that either the username
        or password was incorrect
        */
        printf("User ID or incorrect password, please try again.\n");
        return 0;
      }


      if (r == 1)
      {
        /* Successful login */
        printf("\n\nSuccessful login.\n"); /* We can remove this print statement */
        createUserLL();
        return enteredID;
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
