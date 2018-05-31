#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30
#define MAX_USERS
#define MAX_SESSIONS

#ifndef _SUBJECT_T_
#define _SUBJECT_T_

struct subject{
  int ID;
  int sessionsAmt;
  char name[MAX_NAME_LENGTH];
  int sessions[MAX_SESSIONS];
  int userID[MAX_USERS];
  struct subject* next;
};

typedef struct subject subject_t;

#endif

int CreateSubject(subject_t* subjectLL, session_t* sessionsLL,
    user_t* usersLL, student_t* studentsLL);

int main (void)
{
  subject_t* subjectLL;
  subjectLL = (subject_t*)malloc(sizeof(subject_t));
  if (subjectLL == NULL)
  {
    printf("Memory error.\n");
    return 1;
  }
  subjectLL->next = NULL;

  CreateSubject(subjectLL);

  #ifdef DEBUG
  subject_t* ip;
  int n; /* Counter to visually display number of element in linked list */


  /* Print the contents of the linked list */
  for (ip = subjectLL, n=0; (ip->next != NULL); n++)
  {
    printf("TODO: Enter struct variables to be printed here.")

    ip = ip->next; /* Sets ip to the next node on the list. */
  }

  #endif

  return 0;
}

int CreateSubject(subject_t* subjectLL)
{
  subject_t* ip;
  /* Index pointer */

  ip = subjectLL;

  while (ip->next != NULL)
  {
    ip = ip->next;
  }
  /*
  Find the last entry of the linked list, so as to add to the end of the list
  */


  /*
  (Below) CHECK: Is this everything we want to set?
  */

  /* Take in data */
  printf("Please enter subject ID: ");
  scanf("%d", &ip->ID);

  printf("Enter subject name: ");
  scanf("%s", ip->name);

  ip->sessionsAmt = 0;

  ip->userID = 0; /* for now */


  ip->next = (subject_t*) malloc(sizeof(subject_t));
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
