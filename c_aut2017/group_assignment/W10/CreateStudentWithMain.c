#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkEnrolment.c"
/* #include "printstructstudent.c" */

#define TEST
#define CONSTANTS
#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30
#define SUBJECT_ENROLMENT_DATABASE "enrolment"


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

#ifdef TEST
struct subject{
  int ID;
};
typedef struct subject subject_t;

#endif


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

  #ifdef TEST
  subject_t* testSubject;
  testSubject->ID = 68037;
  #endif


  CreateStudent(studentLL, testSubject);

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



int CreateStudent(student_t* studentLL, subject_t* CurrentSubject)
{
  student_t* ip;
  /* Index pointer */

  int enteredID;
  char enteredName[MAX_PASSWORD_LENGTH];

  ip = studentLL;

  while (ip->next != NULL)
  {
    ip = ip->next;
  }
  /*
  Find the last entry of the linked list, so as to add to the end of the list
  */

  printf("Enter student ID: ");
  scanf("%d", &enteredID);

  printf("Enter student name: ");
  scanf("%s", enteredName);

  /*
  How to read? What is the format of enrolment database? csv?
  Or will it be binary that has been converted to csv?
  Methodology for comparison of strings between enteredID?
  */

  if ( checkEnrolment(enteredID) == 1 )
  {
    ip->ID = enteredID;
    ip->name = enteredName;

    /*
    This sets the values of the last node in the list if they are enrolled in the
    course - which is checked above with the temporary variables enteredID
    and enteredName

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
  }

  if ( checkEnrolment(enteredID) == 0 )
  {
    printf("No enrolment found in %d for student ID %d\n"
            "Please re-enter student ID.\n",
            CurrentSubject->ID, enteredID);

  }

  return 0;
}
