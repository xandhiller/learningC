#ifndef _UPASS_H_
#define _UPASS_H_

/*******************************************************************************
Header Files
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
Preprocessing directives
*******************************************************************************/
/*TODO - Change based on requirements*/
#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 64
/*12 Sessions per week, 13 week*/
#define MAX_SESSIONS 156
/*50 Leaders + 10 Office Staff*/
#define MAX_USERS 60

#define DEBUG

/*******************************************************************************
List structs
*******************************************************************************/
/*ID Format - 1[StudentID]*/
struct student{
  int ID;
  char name[MAX_NAME_LENGTH];
  /*TODO - Change attendance length(consider LinkList)*/
  int attendanceAmt;
  long attendance[64];
  struct student* next;
};
typedef struct student student_t;


/*ID Format - 2[UserID]*/
struct user{
  int ID;
  char name[MAX_NAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int privilege;
  struct user* next;
};
typedef struct user user_t;

/*ID Format - 4[SubjectID][Semester][Year]*/
struct subject{
  int ID;
  int sessionsAmt;
  int usersAmt;
  char name[MAX_NAME_LENGTH];
  long sessions[MAX_SESSIONS]; /*ID Format - 3[SubjectID][Date][Time]*/
  int userID[MAX_USERS];
  student_t* studentsLL;
  struct subject* next;
};
typedef struct subject subject_t;

int selectBaseMenu(void);
void printBaseMenu(void);
void printSessionMenu();
void printSubjectMenu();
void printUserMenu();
void printStudentMenu();
subject_t* selectSubject(subject_t* root);
user_t* selectUser(user_t* root);
student_t* selectStudent(student_t* root);
long selectSession(long sessions[], int sessionsAmt);
void printSubjects(subject_t* root);
void printSessions(long sessions[], int sessionsAmt);
void printUsers(user_t* root);
void printStudents(student_t* root);
long concatenate(long x, long y);
void addSession(subject_t* subject);
void removeSession(subject_t* subject);
void allocateTutor(subject_t* subject, user_t* usersLL);
void removeTutor(subject_t* subject, user_t* root);
void updatePrivilege(user_t* user);
int CreateUser(user_t* userLL);
int CreateSubject(subject_t* subjectLL);
int CreateStudent(student_t* studentLL);
void printUsersByID(user_t* root, int IDs[], int IDamt);
void printUserSubjects(subject_t* root, int userID);
void allocateStudent(subject_t* subject, student_t* studentsLL);
void printStudentSubjects(subject_t* subjectsLL, int ID);
void markSession(student_t* studentsLL, long session);
void printUsersBySession(student_t* student, long session);

#endif