#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_DATABASE "ProgramUsers.bin"
#define STUDENT_DATABASE "_enrolment.bin"
#define SUBJECT_DATABASE "subjects.bin"
#define NEW_STUDENT_CSV "students"
#define MAX_NAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

#ifndef _USER_T_
  #define _USER_T_
  /*ID Format - 2[UserID]*/
  struct user{
    int id;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int privilege;
    /* Privilege: 1- Admin, 2- Leader, 3- Observer */
    struct user* next;
  };

  typedef struct user user_t;
#endif

#ifndef _STUDENT_T_
  #define _STUDENT_T_
  struct student{
    int id;
    char name[MAX_NAME_LENGTH];
    struct student* next;
  }; typedef struct student student_t;
#endif

#ifndef _SUBJECT_T_
  #define _SUBJECT_T_
  struct subject{
    int id;
    student_t* studentList;
    struct subject* next;
  }; typedef struct subject subject_t;
#endif

user_t createUsers(void)
{
	user_t head;
	head.next = NULL;
	user_t *prior;
	prior = &head;
	user_t current;
	FILE* f;
	f = fopen(USER_DATABASE, "rb");
	/*DECRYPTION*/
	while(fread(&current, sizeof(user_t), 1, f) == 1)
	{
		current.next = NULL;
		prior->next = malloc(sizeof *(prior->next));
		*(prior->next) = current;
		prior = prior->next;
	}
	fclose(f);
	return *(head.next);
}

student_t *createStudents(void)
{
	student_t head;
	head.next = NULL;
	student_t *prior;
	prior = &head;
	student_t current;
	FILE* f;
	f = fopen(STUDENT_DATABASE, "rb");
	/*DECRYPTION*/
	while(fread(&current, sizeof(student_t), 1, f) == 1)
	{
		current.next = NULL;
		prior->next = malloc(sizeof *(prior->next));
		*(prior->next) = current;
		prior = prior->next;
	}
	fclose(f);
	return head.next;
}

void importStudents(student_t* head, subject_t* currentSubject)
{
	char name[MAX_NAME_LENGTH];
	int id;
    FILE* f;
    f = fopen(NEW_STUDENT_CSV, "r");
	/*DECRYPTION*/
	while((fscanf(f, "%d", &id))!= EOF)
	{
		fscanf(f, "%[20]s", name);
		/*CreateNewStudent(head, currentSubject, id, name);*/
	}
    fclose(f);
}

void SaveStudents(student_t* head, subject_t curSub)
{
	student_t* saving;
	saving = head;
	FILE* f;
	char filename[20];
	sprintf(filename, "%d", curSub.id);
	strcat(filename, STUDENT_DATABASE);
	f = fopen(filename, "wb");
	
	while(saving != NULL)
	{
		fwrite(saving, sizeof(student_t), 1, f);
		saving = saving->next;
	}
	fclose(f);
}

void SaveUsers(user_t* head)
{
	user_t* saving;
	saving = head;
	FILE* f;
	f = fopen(USER_DATABASE, "wb");
	
	while(saving != NULL)
	{
		fwrite(saving, sizeof(user_t), 1, f);
		saving = saving->next;
	}
	fclose(f);
}

void SaveSubjects(subject_t* head)
{
	subject_t* saving;
	saving = head;
	FILE* f;
	f = fopen(SUBJECT_DATABASE, "wb");
	
	while(saving != NULL)
	{
		fwrite(saving, sizeof(user_t), 1, f);
		saving = saving->next;
	}
	fclose(f);
}