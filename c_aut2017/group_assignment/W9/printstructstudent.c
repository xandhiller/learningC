#include <stdio.h>
#include <stdlib.h>

#ifndef CONSTANTS
#define CONSTANTS
#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30
#endif

#ifndef _STUDENT_T_
#define _STUDENT_T_
/*
Begin with a 'define' if-statement that will ensure that the struct student
won't be defined twice
*/

struct student{
  int ID;
  char name[MAX_NAME_LENGTH];
  /* TODO - Change attendance length(consider LinkList)*/
  int attendance[64];
  struct student* next;
};

typedef struct student student_t;

#endif

void printstudent(student_t* headOfLinkedList) /* Change struct type if needed */
{
  student_t* ip;
  ip = headOfLinkedList;

  do
  {
    /* Structure variable print statements go here, print to check them  */
    printf("%d\n", ip->ID);
    printf("%s\n", ip->name);

    ip = ip->next;
    if (ip == NULL)
    {
      printf("Memory error.\n");
      /*
      Can't enter 'return 1' because this function isn't allowed
      to return values. Should we change function type to int?
      */
    }

  } while (ip->next != NULL);

}

/*
This object file isn't linking correctly right now.
*/
