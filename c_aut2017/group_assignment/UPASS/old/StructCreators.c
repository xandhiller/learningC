#include "UPASS.h"

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

  ip->usersAmt = 0; /* for now */


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

int CreateStudent(student_t* studentLL)
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

  if ( 1 ==1/*TODOcheckEnrolment(enteredID) == 1*/ )
  {
    ip->ID = enteredID;
    strcpy(ip->name, enteredName);
    ip->attendanceAmt = 0;

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

  /*if (checkEnrolment(enteredID) == 0 )
  {
    printf("No enrolment found in %d for student ID %d\n"
            "Please re-enter student ID.\n",
            CurrentSubject->ID, enteredID);

  }*/

  return 0;
}