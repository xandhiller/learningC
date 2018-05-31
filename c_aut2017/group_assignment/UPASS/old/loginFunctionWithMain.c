#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_DATABASE "ProgramUsers.bin"
#define MAX_NAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20


#ifndef _USER_T_
  #define _USER_T_
  /*ID Format - 2[UserID]*/
  struct user{
    int id;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int privilege;
    /* Privilege: 1- Admin, 2- Leader, 3- Observer */
    struct user* next;
  };

  typedef struct user user_t;
#endif

int login(FILE* fp, user_t* head, user_t *user);

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
  fp = fopen(USER_DATABASE, "rb");
  if (fp == NULL)
  {
    printf("No database currently stored.\n");

    /* Force set-up of an administrator */
    printf("You must set up an administrator to begin using the program.\n");

    printf("Enter your staff ID: ");
    scanf("%d", &(userLL->id));
    printf("Enter your password (note, it will appear on-screen): ");
    scanf(" %s", userLL->password);
    printf("You will be set up as an administrator for this program.\n");
    userLL->privilege = 1;

    /* TODO: Write to the database */
  }

  else
  {
    user_t *loginName;
    loginName = (user_t*)malloc(sizeof(user_t));
    if(login(fp, userLL, loginName))
    {
      printf("Failed to log on.");
      return 1;
    }
    /*else{MENU_FUNCTION()}*/

  }


  return 0;


}

int login(FILE* fp, user_t* head, user_t* user)
{
	int inputID;
	char inputPassword[MAX_PASSWORD_LENGTH];
	int passCheck = 0;
	user_t* currentLogin;
	currentLogin = head;
	printf("Login:\n");
	while(1>0)
	{
		passCheck=0;
		printf("Enter user ID (enter '0' to exit)> ");
		scanf(" %d", &inputID);
		if(inputID==0)
			break;
		while(fread(currentLogin, sizeof(user_t), 1, fp) != EOF)
		{
			if(inputID == currentLogin->id)
			{
				while(!(passCheck))
				{
					printf("Enter password (enter '@end' to cancel)> ");
					scanf(" %s", inputPassword);
					if(!(strcmp(inputPassword, currentLogin->password)))
                    {
						user = currentLogin;
                        return 0;
                    }
					else if(!(strncmp(inputPassword, "@end", 4)))
						passCheck=1;
					else
						printf("Incorrect password.");
				}
			}
		}
		printf("No such user.\n");
	}
	return 1;
}
