

#include <stdio.h>
#include <stdlib.h>

#define MAX_CLASS_SIZE 5
#define MAX_NAME_SIZE 11
#define DB_FILE_NAME "database"




/* Structures */
struct date
{
	int day;
	int month;
	int year;
};
typedef struct date date_t;

struct student
{
	char name[MAX_NAME_SIZE];
	float gpa;
	date_t birthday;
};
typedef struct student student_t;




/* Function prototypes */
int addstudent(student_t sl, int studentcount);






int main(void)
{
  student_t studentlist[MAX_CLASS_SIZE];
  int studentcount = 0;

  studentcount = addstudent(studentlist[studentcount], studentcount);

  printf("studentcount is now %d\n", studentcount);


  return 0;
}





/* Function to add student */
int addstudent(student_t sl, int studentcount)
{
  /*
  sl is the analogue of studentlist, the struct with student details
  */

  /* CHECK THE ORDER, WHITESPACE AND GRAMMAR */
  printf("Enter name>");
  scanf("%[^\n]", sl.name);

  printf("Enter birthday:\n");


  printf("Enter day>");
  scanf(" %d", &sl.birthday.day);

  /* Day input error check */
  while (sl.birthday.day == 0 || sl.birthday.day >= 32)
  {
    printf("Invalid choice. Enter day>");
    scanf(" %d", &sl.birthday.day);
  }


  printf("Enter month>");
  scanf(" %d", &sl.birthday.month);

  /* Month input error check */
  while (sl.birthday.month == 0 || sl.birthday.month >= 13)
  {
    printf("Invlaid choice. Enter month>");
    scanf(" %d", &sl.birthday.month);
  }


  printf("Enter year>");
  scanf(" %d", &sl.birthday.year);

  /* Year input error check */
  while (sl.birthday.year < 1800 || sl.birthday.year > 2017)
  {
    printf("Invlaid choice. Enter year>");
    scanf(" %d", &sl.birthday.year);
  }


  /* This part is for testing */
  printf("Of array element %d, the name is: %s\n", studentcount,
  sl.name);

  printf("Of array element %d, the birthday is: %02d %02d %04d\n",
  studentcount, sl.birthday.day, sl.birthday.month,
  sl.birthday.year);
  /* End of testing part */

  studentcount++;
  return studentcount;
}
