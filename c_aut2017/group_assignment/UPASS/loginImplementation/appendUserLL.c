#include "UPASS.h"

int appendUserLL(user_t* userLL)
{
  /* Open the database so you can save it as you go */
  FILE* fp;
  fp = fopen(USER_DATABASE, "a");
  if (fp==NULL)
  {
    printf("Memory error.\n");
    return 1;
  }


  user_t* ip;
  char passwordTest[MAX_PASSWORD_LENGTH];

  ip = userLL;

  /* Finds the last element in the LL */
  while (ip->next != NULL)
  {
    ip = ip->next;
  }

  /* Intake the ID, save it to the LL and save it to the database */
  printf("Enter user ID: ");
  scanf("%d", &ip->ID);
  fprintf(fp, "%d\t", ip->ID);


  /* Intake the name, save it to the LL and save it to the database */
  printf("Enter user name: ");
  scanf("%s", ip->name);
  fprintf(fp, "%s\t", ip->name);


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

  /* Cipher the user's password */
  strcpy(ip->password, cipher(ip->password));
  /* Write the ciphered password to the database  */
  fprintf(fp, "%s\t", ip->password);


  /* Take in and save the privelege of the user to the database and the LL */
  printf("Enter user privilege: ");
  scanf("%d", &ip->privilege);
  fprintf(fp, "%d\n", ip->privilege);

  /* Creates the next node in the linked list */
  ip->next = (user_t*) malloc(sizeof(user_t));
  if (ip == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }

  ip = ip->next;
  ip->next = NULL;
  /*
  Sets the new end node's pointer equal to NULL in order to find the last
  node, as in my while-loop above.
  */

  return 0;


}
