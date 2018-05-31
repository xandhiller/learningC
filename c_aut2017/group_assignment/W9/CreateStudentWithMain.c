#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include "printstructstudent.c" */


#define CONSTANTS
#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30


/*#define DEBUG */ /* Comment this out when you don't want debug features */


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
/*
Ends the check for whether the student struct is already defined
in any program that wishes to use this as a function.
*/



int CreateStudent(student_t* studentLL);

int main (void)
{
  student_t* studentLL;
  studentLL = (student_t*) malloc(sizeof(student_t));
  if (studentLL == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  studentLL->next = NULL;


  CreateStudent(studentLL);

  #ifdef DEBUG
  student_t* ip;
  int n; /* Counter to visually display number of element in linked list */


  /* Print the contents of the linked list */
  for (ip = studentLL, n=0; (ip->next != NULL); n++)
  {
    printf("Element %d of linked list.\n"
          "ID is: %d\n"
          "Name is: %s\n"
          "Next address is: %p\n",
          n, ip->ID, ip->name, ip->next);

    ip = ip->next; /* Sets ip to the next node on the list. */
  }

  #endif

  return 0;
}



int CreateStudent(student_t* studentLL)
{
  student_t* ip;
  /* Index pointer */

  ip = studentLL;

  while (ip->next != NULL)
  {
    ip = ip->next;
  }
  /*
  Find the last entry of the linked list, so as to add to the end of the list
  */


  printf("Enter student ID: ");
  scanf("%d", &ip->ID);

  printf("Enter student name: ");
  scanf("%s", ip->name);
  /*
  Set the values of the last node in the list

  Not setting attendance in this function because that will be used to access
  this student's individual attendance history over time. That should be
  implemented in a separate function. This function is simply to create a
  new student.
  */


  ip->next = (student_t*) malloc(sizeof(student_t));
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
