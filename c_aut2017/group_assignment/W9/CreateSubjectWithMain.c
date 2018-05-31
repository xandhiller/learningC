#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30

#ifndef _SUBJECT_T_
#define _SUBJECT_T_

struct subject{
  int ID;
  session_t* sessionsLL;
  user_t* usersLL;
  student_t* studentsLL;
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

  /* We have to pass addresses for the user, student and session? */



  return 0;
}
