#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.c"
#include "createUserLL.c"
#define DEBUG

#ifndef _USER_T_
#define _USER_T_
struct user{
  int ID;
  char name[MAX_NAME_LENGTH];
  char password[3*MAX_PASSWORD_LENGTH];
  int privilege;
  struct user* next;
};
typedef struct user user_t;
#endif

int main(void)
{

  user_t* userLL;
  userLL = createUserLL();
  appendUserLL(userLL);

  /* print the now appended linked list */
  #ifdef DEBUG
  user_t* ip;

  /* Print linked list */
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
