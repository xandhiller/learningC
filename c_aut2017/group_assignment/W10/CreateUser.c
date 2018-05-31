#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30

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

/* Save user database as well */


int CreateUser(user_t* userLL);

int main (void)
{
  user_t* userLL;
  userLL = (user_t*) malloc(sizeof(user_t));
  if (userLL == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  userLL->next = NULL;

  CreateUser(userLL);

  #ifdef DEBUG
  user_t* ip;
  int n; /* Counter to visually display number of element in linked list */


  /* Print the contents of the linked list */
  for (ip = userLL, n=0; (ip->next != NULL); n++)
  {
    printf("Element %d of linked list.\n"
          "ID is: %d\n"
          "Name is: %s\n"
          "Password is: %s\n"
          "Privilege is: %d\n",
          n, ip->ID, ip->name, ip->password, ip->privilege);

    ip = ip->next; /* Sets ip to the next node on the list. */
  }

  #endif

  return 0;
}

int CreateUser(user_t* userLL)
{
  user_t* ip;
  char passwordTest[MAX_PASSWORD_LENGTH];

  ip = userLL;


  while (ip->next != NULL)
  {
    ip = ip->next;
  }
  /*
  Finds the last element in the LL
  */

  printf("Enter user ID: ");
  scanf("%d", &ip->ID);

  printf("Enter user name: ");
  scanf("%s", ip->name);

do
  {

    printf("Enter password: ");
    scanf("%s", ip->password);

    printf("Enter password again: ");
    scanf("%s", passwordTest);

    if( strcmp(passwordTest, ip->password) != 0)
    {
      printf("Passwords don't match. Please enter again.\n");
    }

  } while ( strcmp(passwordTest, ip->password) != 0);

  printf("Enter user privilege: ");
  scanf("%d", &ip->privilege);


  ip->next = (user_t*) malloc(sizeof(user_t));
  if (ip == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  /*
  Creates the next node in the linked list
  */

  ip = ip->next;
  ip->next = NULL;
  /*
  Sets the new end node's pointer equal to NULL in order to find the last
  node, as in my while-loop above.
  */

  return 0;
}
