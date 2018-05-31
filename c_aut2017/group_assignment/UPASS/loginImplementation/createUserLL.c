#include "UPASS.h"

user_t* createUserLL(void)
{
  FILE* fp;
  fp = fopen(USER_DATABASE, "r");
  if ( fp == NULL )
  {
    printf("Memory error.\n");
  }

  user_t* ip; /* Index pointer */
  user_t* userLL; /* Head of linked list */
  userLL = (user_t*) malloc(sizeof(user_t));
  if (userLL == NULL)
  {
    printf("Memory error.\n");
  }
  userLL->next = NULL;

  ip = userLL;

  while (1>0)
  {
    /* Set ID */
    fscanf(fp, "%d", &ip->ID);
    fscanf(fp, "%*[\t]"); /* Skips over the tab */

    /* Set name from database */
    fscanf(fp, "%[^\t]s", ip->name); /* Read the name */
    fscanf(fp, "%*[\t]"); /* Read-only the tab after the name */

    /* Set password from database */
    fscanf(fp, "%[^\t]s", ip->password);


    /* Set privelege from database */
    fscanf(fp, "%d", &ip->privilege); /* Read  the privilege */
    fscanf(fp, "%*[\n]"); /* Absorb the new line character */

    /* Initialise new node in linked list */
    ip->next = (user_t*) malloc(sizeof(user_t));
    if (ip == NULL)
    {
      printf("Memory error.\n");
    }

    /* Set ip equal to new address */
    ip = ip->next;

    /* Set new node's "next" to NULL */
    ip->next = NULL;

    /* If we reach the end of the file, break the loop. */
    if(feof(fp))
    {
      break;
    }
  }

  /* Debug section to print out the linked list and checked it worked */
  #ifdef DEBUG

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



  return userLL;
}
