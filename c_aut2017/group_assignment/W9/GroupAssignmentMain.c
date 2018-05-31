#include <stdio.h>
#include <stdlib.h>


/*TODO - Change based on requirements*/
#define MAX_PASSWORD_LENGTH 16
#define MAX_NAME_LENGTH 30


/*ID Format - 1[StudentID]*/
struct student{
  int ID;
  char name[MAX_NAME_LENGTH];
  /*TODO - Change attendance length(consider LinkList)*/
  int attendance[64];
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

/*ID Format - 3[SubjectID][Date][Time]*/
struct session{
  int ID;
  student_t* studentsLL;
  /*TODO - Change location length*/
  char location[64];
  int time;
  struct session* next;
};

typedef struct session session_t;


/*ID Format - 4[SubjectID]*/
struct subject{
  int ID;
  session_t* sessionsLL;
  user_t* usersLL;
  student_t* studentsLL;
  struct subject* next;
};

typedef struct subject subject_t;

int main(void){
	return 0;
}
