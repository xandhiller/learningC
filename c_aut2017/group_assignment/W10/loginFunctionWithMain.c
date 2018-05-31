#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_DATABASE "ProgramUsers.txt"

#ifndef _USER_T_
  #define _USER_T_
  /*ID Format - 2[UserID]*/
  struct user{
    int ID;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int privilege;
    /* Privilege: 1- Admin, 2- Leader, 3- Observer */
    struct user* next;
  };

  typedef struct user user_t;
#endif

int main (void)
{
  user_t* userLL;
  userLL = (user_t*)malloc(sizeof(user_t));
  if (userLL == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  userLL->next = NULL;

  /* Check if any users in database */
  FILE* fp;
  fp = fopen(USER_DATABASE, "r");
  if (fp == NULL)
  {
    printf("No database currently stored.\n");

    /* Force set-up of an administrator */
    printf("You must set up an administrator to begin using the program.\n");

    printf("Enter your staff ID: ");
    scanf("%s", userLL->ID);
    printf("Enter your password (note, it will appear on-screen): ");
    scanf("%s", userLL->password);
    printf("You will be set up as an administrator for this program.\n");
    userLL->privilege = 1;

    /* TODO: Write to the database */
  }

  if ( /* users > 0 */ )
  {
    /* Have to log on */

  }




  return 0;


}
