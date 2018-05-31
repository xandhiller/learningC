/*******************************************************************************
48430 Fundamentals of C Programming - Assignment 2
Name: Alexander Hiller
Student ID: 11850637
Date of submission: 2nd May 2017

A brief statement on what you could achieve (less than 50 words):
Able to meet all requirements, including being able to handle spaces in names.
Characters can also be entered in the menu without causing an error (i.e. not
an entry of 1-6).

A brief statement on what you could NOT achieve (less than 50 words):
Can't handle chars being entered into a year, month, day or GPA.

*******************************************************************************/

/*******************************************************************************
List of header files - do NOT use any other header files. Note that stdlib and
cstring are included in case you want to use any of the functions in there.
However the task can be achieved with stdio only.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
List preprocessing directives - you may define your own.
*******************************************************************************/
/* Maximum number of students in the class */
#define MAX_CLASS_SIZE 5
/* Maximum length of the string - student name. Note that all strings in C are
NULL terminated i.e. '\0' at the end of the string. Hence the length of the
actual name can be 10 characters at most*/
#define MAX_NAME_SIZE 11
/* Static file name of the text file where student list is stored */
#define DB_FILE_NAME "database"

/*******************************************************************************
List structs - you may define struct date and struct student only. Each struct
definition should have only the fields mentioned in the assignment description.
*******************************************************************************/
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

/*******************************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
*******************************************************************************/
void printMenu(void);
int Selection(void);
int addstudent(student_t studentlist[], int studentcount);
void printHeading(void);
void printList(student_t studentlist[], int studentcount);
void saveList(student_t studentlist[], int studentcount);
int readList(student_t studentlist[], int studentcount);

/*******************************************************************************
Main
*******************************************************************************/
int main(void)
{
	/* Main function variables */
	student_t studentlist[MAX_CLASS_SIZE]; /* Array of students */
	int studentcount = 0; /* Number of students currently in the student list */
	int menuchoice = 0; /* The number entered by the user to select from menu */

	do
	{
		/*
		Conditional statements for actions to be taken by the program,
		based on the input from the user based on the available options
		*/
		if (menuchoice == 1)
		{
			if (studentcount < 5)
			{
				studentcount = addstudent(studentlist, studentcount);
			}
			else
			{
				printf("Class is full\n");
			}
		}
		else if (menuchoice == 2)
		{
			if (studentcount > 0)
			{
				studentcount--;
			}
			else
			{
				printf("Class is empty\n");
			}
			/*
			Deleting last student is performed by simply decrementing the count.
			Because 'studentcount' is used to print and save the studentlist,
			it will print one less student and save one less student than
			before the user selected '2'. This allows this array element to also
			be overwritten; essentially deleting it.
			*/
		}
		else if (menuchoice == 3)
		{
			if (studentcount > 0)
			{
				printList(studentlist, studentcount);
			}
			else
			{
				printf("Class is empty\n");
			}
		}
		else if (menuchoice == 4)
		{
			saveList(studentlist, studentcount);
		}
		else if (menuchoice == 5)
		{
			studentcount = readList(studentlist, studentcount);
		}

		/*
		Line below this comment ensures the menu is continually reprinted
		and takes input from the user about what they want to do in the menu
		 */
		menuchoice = Selection();

	} while (menuchoice != 6);

	return 0;
}


/*******************************************************************************
printMenu
This function prints the initial menu with all instructions on how to use this
program.

inputs:
- none
outputs:
- none
*******************************************************************************/
void printMenu(void)
{
	printf("\n\n"
	"1. add student\n"
	"2. delete last student\n"
	"3. display student list\n"
	"4. save the student list to the database\n"
	"5. read the student list from the database\n"
	"6. exit the program\n"
	"Enter your choice>");
}

/*******************************************************************************
addstudent
This function gives adds a student to the student list.

inputs:
studentlist[], studentcount
outputs:
studentcount
*******************************************************************************/
int addstudent(student_t studentlist[], int studentcount)
{
  printf("Enter name>");
  scanf(" %10[^\n]%*[^\n]", studentlist[studentcount].name);


	#ifdef DEBUG
	printf("String in array is: %s\n", studentlist[studentcount].name);
	#endif


  printf("Enter birthday: day>");
  scanf(" %d", &studentlist[studentcount].birthday.day);

  /* Day input error check */
  while (studentlist[studentcount].birthday.day <= 0
				|| studentlist[studentcount].birthday.day >= 32)
  {
    printf("Invalid day. Enter birthday: day>");
    scanf(" %d", &studentlist[studentcount].birthday.day);
  }


  printf("Enter birthday: month>");
  scanf(" %d", &studentlist[studentcount].birthday.month);

  /* Month input error check */
  while (studentlist[studentcount].birthday.month <= 0
				|| studentlist[studentcount].birthday.month >= 13)
  {
    printf("Invalid month. Enter birthday: month>");
    scanf(" %d", &studentlist[studentcount].birthday.month);
  }


  printf("Enter birthday: year>");
  scanf(" %d", &studentlist[studentcount].birthday.year);

  /* Year input error check */
  while (studentlist[studentcount].birthday.year < 1800
				|| studentlist[studentcount].birthday.year > 2017)
  {
    printf("Invalid year. Enter birthday: year>");
    scanf(" %d", &studentlist[studentcount].birthday.year);
  }

	printf("Enter GPA>");
	scanf(" %f", &studentlist[studentcount].gpa);

	/* GPA input error check */
	while (studentlist[studentcount].gpa < 0
		|| studentlist[studentcount].gpa > 4)
  {
    printf("Invalid GPA. Enter GPA>");
    scanf(" %f", &studentlist[studentcount].gpa);
  }

  studentcount++;
  return studentcount;
}
/*******************************************************************************
printHeading
This function prints the heading of the student list.
Making this function makes the list-printing function easier to read.

inputs:
- none
outputs:
- none
*******************************************************************************/
void printHeading(void)
{
	int i;
	char listHeading[26];

	/*
	Prints the words for the heading of the student list
	*/
	strcpy(listHeading, "Name       Birthday   GPA");
	printf("%s\n", listHeading);

	/*
	Prints the '-' characters for the heading in the correct format.
	*/
	for (i=0; i<10; i++)
	{
		printf("-");
	}
	printf(" ");

	for (i=0; i<10; i++)
	{
		printf("-");
	}
	printf(" ");

	for (i=0; i<6; i++)
	{
		printf("-");
	}
	printf("\n");
}

/*******************************************************************************
printList
This function displays the student list, reading from the array by using
the studentcount

inputs:
studentlist[], studentcount
outputs:
- none
*******************************************************************************/
void printList(student_t studentlist[], int studentcount)
{
	int i;

	printHeading();

	/* Prints the contents of the array up to the count of student count */
	for (i=0; i < studentcount; i++)
  {
    printf("%-10s", studentlist[i].name);

		printf(" %02d-%02d-%d ",
		studentlist[i].birthday.day, studentlist[i].birthday.month,
			studentlist[i].birthday.year);

		printf("%.4f", studentlist[i].gpa);
    printf("\n");
  }
}

/*******************************************************************************
saveList
This function saves the current student list to a file named by
the macro DB_FILE_NAME

inputs:
studentlist[], studentcount
outputs:
- none
*******************************************************************************/
void saveList(student_t studentlist[], int studentcount)
{
	FILE* data;
	int i;

	data = fopen(DB_FILE_NAME, "w");

	if(data == NULL)
	{
		printf("Write error\n");
	}
	/*
	Tested the write error by changing permissions of 'database' using chmod
	555 to selection the permissions of the file to read and execute only.
	*/

	fprintf(data, "%d\t", studentcount);

	for (i=0; i < studentcount; i++)
	{
		fprintf(data, "%-10s\t", studentlist[i].name);

		fprintf(data, "%02d\t%02d\t%d\t",
		studentlist[i].birthday.day, studentlist[i].birthday.month,
			studentlist[i].birthday.year);

		fprintf(data, "%.4f\t", studentlist[i].gpa);
	}
	fclose(data);
}

/*******************************************************************************
readList();
This function reads the student list named by the macro DB_FILE_NAME and
assigns it to the array studentlist[], replacing whatever was in there.

inputs:
studentlist[], studentcount
outputs:
studentcount
*******************************************************************************/
int readList(student_t studentlist[], int studentcount)
{
	FILE* data; /* points to the database */
	int j; /* counter */

	data = fopen(DB_FILE_NAME, "r");

	if (data == NULL) /* If there's no database it well return Read Error */
	{
		printf("Read error\n");
		return studentcount;
	}
	else
	{
		/*
		This reassignment of studentcount makes it so that the student count is
		the correct length with respect to the database
		*/
		fscanf(data, " %d ", &studentcount);

		/* Correctly assign the student name to studentlist array */
		for (j=0; j < studentcount; j++)
		{
			fscanf(data, "%11s", studentlist[j].name);
			fscanf(data, "%d", &studentlist[j].birthday.day);
			fscanf(data, "%d", &studentlist[j].birthday.month);
			fscanf(data, "%d", &studentlist[j].birthday.year);
			fscanf(data, "%f", &studentlist[j].gpa);
		}

		fclose(data);

		return studentcount;
	}
}

/*******************************************************************************
Selection();
This function is to take in the user's selection in the menu.

inputs:
- none
outputs:
menuchoice - the variable used to indicate what the user has chosen.
*******************************************************************************/
int Selection(void)
{
	char selection[50];

	 /* Is assigned the numeric value of selection array */
	int number;

	printMenu();
	scanf("%s", selection);

	/*
	Takes in the first integer entered by the user
	and assigns it to the variable 'number'
	*/
	number = atoi(&selection[0]);

	/*
	If the user enters a menu selection that is not offered, this 'while' loop
	will remain active, performing similar functionality as to previously
	*/
	while (number <= 0 || number >= 7)
	{
	  printf("Invalid choice.\n");
		printMenu();
	  scanf("%s", selection);
	  number = atoi(&selection[0]);
	}

	  return number;
}
