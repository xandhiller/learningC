#include "UPASS.h"
#include "StructCreators.c"
#include "ReadingandWritingDatabase_c.c"
#include "login.c"
#include "createCurrentUser.c"
#include "appendUserLL.c"

/*******************************************************************************
TODO
 - Implement Privilege
 - Implement Database**
 - Implement Mass Import**
 - Implement Login**
 - Check if structs exist when created**

*******************************************************************************/

/*******************************************************************************
Main
*******************************************************************************/
int main(void){
	int choice = -1;
	int logResult = 0; /* Integer carrying the login result */

	user_t* currentUser;
	subject_t* selectedSubject;
	user_t* selectedUser;
	student_t* selectedStudent;

/*******************************************************************************
 Login
*******************************************************************************/

	/* Login logic, based on output of login() function */
	while (logResult != -1)
	{
		/*
		Calling the login function and assigning its output to an integer value
		to allow for easy logical operations without re-evaluation of the login
		function.
		*/
		logResult = login();


		if (logResult == 0)
		{
			/* Login failure */
			continue;
		}


		if (logResult != 0 && logResult != -1)
		{
			/* This means success, meaning the logResult has the value of the user ID */

			/* Call createCurrentUser */
			printf("\nInitialising user credentials... \n\n");


			#ifdef DEBUG
			printf("\nValue of logResult is: %d \n\n", logResult);
			#endif


			currentUser = createCurrentUser(logResult);

			#ifdef DEBUG
			printf("Current User ID: %d\n", currentUser->ID);
			printf("Current User name: %s\n", currentUser->name);
			printf("Current User password: %s\n", currentUser->password);
			printf("Current User privilege: %d\n", currentUser->privilege);
			#endif

			/* Initialise user linked list */
			break;
		}
	}

	if (logResult == -1)
	{
		/* User exited program */
		return 0;
	}
/*******************************************************************************
	End Login
*******************************************************************************/


	subject_t* subjectLL ;
	subjectLL = (subject_t*) malloc(sizeof(subject_t));
	if (subjectLL == NULL){
		printf("Memory error.\n");
		return 0;
	}
	subjectLL->next = NULL;

	createSubjects(subjectLL);

	user_t* userLL;
	userLL = (user_t*) malloc(sizeof(user_t));
	if (userLL == NULL){
		printf("Memory error.\n");
		return 0;
	}
	userLL->next = NULL;

	userLL = createUserLL();

	student_t* studentsLL;
	studentsLL = (student_t*) malloc(sizeof(student_t));
	if (studentsLL == NULL){
		printf("Memory error.\n");
		return 0;
	}
	studentsLL->next = NULL;

	createStudents(studentsLL);

	while(choice != 0){
		printBaseMenu();
		scanf("%d", &choice);
		switch(choice){
			case 1 :
				CreateStudent(studentsLL);
				break;
			case 2 :
				/*importStudents()*/
				break;
			case 3 :
				appendUserLL(userLL);
				break;
			case 4 :
				CreateSubject(subjectLL);
				break;
			case 5 :
				selectedSubject = selectSubject(subjectLL);
				while(choice != 1 && selectedSubject != NULL){
					printSubjectMenu();
					scanf("%d", &choice);
					switch(choice){
						case 1 :break;
						case 2 :
							addSession(selectedSubject);
							break;
						case 3 :
							removeSession(selectedSubject);
							break;
						case 4 :
							allocateTutor(selectedSubject, userLL);
							break;
						case 5 :
							removeTutor(selectedSubject, userLL);
							break;
						case 6 :
							allocateStudent(selectedSubject, studentsLL);
							break;
						case 7 :
							removeStudent(selectedSubject);
							break;
						case 8 :
							markSession(selectedSubject->studentsLL, studentsLL, selectSession(selectedSubject->sessions, selectedSubject->sessionsAmt));
							break;
						case 9 :
							printStudents(selectedSubject->studentsLL);
							break;
						case 10 :
							printUsersByID(userLL, selectedSubject->userID, selectedSubject->usersAmt);
							break;
						case 11 :
							printStudentsBySession(selectedSubject->studentsLL, selectSession(selectedSubject->sessions, selectedSubject->sessionsAmt));
							break;
						default :
							printf("Invalid input \n");
					}
				}
				break;
			case 6 :
				selectedUser = selectUser(userLL);
				while(choice != 1 && selectedUser != NULL){
					printUserMenu();
					scanf("%d", &choice);
					switch(choice){
						case 1 :break;
						case 2 :
							updatePrivilege(selectedUser);
						case 3 :
							printUserSubjects(subjectLL, selectedUser->ID);
							break;
						default :
							printf("Invalid input \n");
					}
				}
				break;
			case 7 :
				selectedStudent = selectStudent(studentsLL);
				while(choice != 1 && selectedStudent != NULL){
					printStudentMenu();
					scanf("%d", &choice);
					switch(choice){
						case 1 :break;
						case 2 :
							printStudentSubjects(subjectLL, selectedStudent->ID);
							break;
						case 3 :
							printSessions(selectedStudent->attendance, selectedStudent->attendanceAmt);
							break;
						default :
							printf("Invalid input \n");
					}
				}
				break;
			case 0 :
				saveStudents(studentsLL);
				saveSubjects(subjectLL);
				break;
			default :
				printf("Invalid input \n");

		}
	}

	return 0;
}

/*******************************************************************************
printBaseMenu
This function prints the initial menu with all instructions on how to use this
program.
inputs:
- none
outputs:
- none
*******************************************************************************/
void printBaseMenu(void){
	printf("\n\n"
	"1. Create new student\n"
	"2. Import students\n"
	"3. Create new user\n"
	"4. Create new subject\n"
	"5. Select subject\n"
	"6. Select user\n"
	"7. Select student\n"
	"0. Exit the program\n"
	"Enter your choice>");
}

/*******************************************************************************
printSubjectMenu
This function prints the the contextual menu with all functions that modify a
subject struct
inputs:
- none
outputs:0

- none
*******************************************************************************/
void printSubjectMenu(void){
	printf("\n\n"
	"1. Return to main menu\n"
	"2. Add session\n"
	"3. Remove session\n"
	"4. Allocate tutor\n"
	"5. Remove tutor\n"
	"6. Allocate student\n"
	"7. Remove student\n"
	"8. Mark attendance\n"
	"9. View students\n"
	"10. View tutors\n"
	"11. View attendance\n"
	"Enter your choice>");
}

/*******************************************************************************
printUserMenu
This function prints the the contextual menu with all functions that modify a
user struct
inputs:
- none
outputs:
- none
*******************************************************************************/
void printUserMenu(void){
	printf("\n\n"
	"1. Return to main menu\n"
	"2. Update privilege\n"
	"3. Display subjects\n"
	"Enter your choice>");
}

/*******************************************************************************
printStudentMenu
This function prints the the contextual menu with all functions that modify a
student struct
inputs:
- none
outputs:
- none
*******************************************************************************/
void printStudentMenu(void){
	printf("\n\n"
	"1. Return to main menu\n"
	"2. Display subjects\n"
	"3. Display attendance\n"
	"Enter your choice>");
}

/*******************************************************************************
selectSubject
This function prompts the user to input a subject ID, giving the option to print
basic information for all subject structs (from the provided linked list)
inlcuding their ID's if the user is unaware of the ID. The function then returns
a student struct that contains the selected ID or returns a null pointer and
prints an error message if no struct exists in the list provided.
inputs:
- Root node of a subject struct linked list
outputs:
- Subject struct
*******************************************************************************/
subject_t* selectSubject(subject_t* root){
	int tempID;
	subject_t* ip = root;
	printf("\n\n"
		"Enter -1 to cancel, \n"
		"Enter 0 to display subject IDs or\n"
		"Enter subject ID: ");
	scanf("%d", &tempID);
	while(tempID == 0){
		printSubjects(root);
		printf("Enter subject ID: ");
		scanf("%d", &tempID);
	}

	while( ip != NULL && ip->next != NULL){
		if(ip->ID == tempID){

			#ifdef DEBUG
			printf("ID: %d\n", ip->ID);
			printf("Sessions Amt: %d\n", ip->sessionsAmt);
			printf("Users Amt: %d\n", ip->usersAmt);
			#endif
			return ip;
		}
		ip = ip->next;
	}


	printf("Subject doesn't exist\n");
	return NULL;
};

/*******************************************************************************
selectSession
This function prompts the user to input a session ID, giving the option to print
basic information for all session IDs (from the provided array)
inlcuding their full ID's if the user is unaware of the ID. The function then
returns the selected ID or negative 1 if no session ID can be returned.
inputs:
- Array of session IDs, amount of IDs in the array as an int
outputs:
- Session ID as an int
*****************************************************************************/
long selectSession(long sessions[], int sessionsAmt){
	int i;
	long tempID;
	printf("\n\n"
		"Enter -1 to cancel, \n"
		"Enter 0 to display session IDs or\n"
		"Enter session ID: ");
		scanf("%ld", &tempID);
	while(tempID == 0){
		printSessions(sessions, sessionsAmt);
		printf("Enter session ID: ");
		scanf("%ld", &tempID);
	}

	for(i = 0; i < sessionsAmt; i++){
		if(sessions[i] == tempID){
			return tempID;
		}
	}
	printf("Session doesn't exist\n");
	return -1;
};

/*******************************************************************************
selectUser
This function prompts the user to input a user ID, giving the option to print
basic information for all user structs (from the provided linked list)
inlcuding their ID's if the user is unaware of the ID. The function then returns
a user struct that contains the selected ID or returns a null pointer and
prints an error message if no struct exists in the list provided.
inputs:
- Root node of a user struct linked list
outputs:
- User struct
*******************************************************************************/
user_t* selectUser(user_t* root){
	int tempID;
	user_t* ip = root;

	printf("\n\n"
		"Enter -1 to cancel, \n"
		"Enter 0 to display user IDs or\n"
		"Enter user ID: ");
	scanf("%d", &tempID);
	while(tempID == 0){
		printUsers(root);
		printf("Enter user ID: ");
		scanf("%d", &tempID);
	}

	while( ip != NULL && ip->next != NULL){
		if(ip->ID == tempID){
			return ip;
		}
		ip = ip->next;
	}
	printf("User doesn't exist\n");
	return NULL;
};

/*******************************************************************************
selectStudent
This function prompts the user to input a student ID, giving the option to print
basic information for all student structs (from the provided linked list)
inlcuding their ID's if the user is unaware of the ID. The function then returns
a student struct that contains the selected ID or returns a null pointer and
prints an error message if no struct exists in the list provided.
inputs:
- Root node of a student struct linked list
outputs:
- Student struct
*******************************************************************************/
student_t* selectStudent(student_t* root){
	int tempID;
	student_t* ip = root;
	printf("\n\n"
		"Enter -1 to cancel, \n"
		"Enter 0 to display student IDs or\n"
		"Enter student ID: ");
	scanf("%d", &tempID);
	while(tempID == 0){
		printStudents(root);
		printf("Enter student ID: ");
		scanf("%d", &tempID);
	}

	while( ip != NULL && ip->next != NULL){
		if(ip->ID == tempID){
			return ip;
		}
		ip = ip->next;
	}
	printf("Student doesn't exist\n");
	return NULL;
};

/*******************************************************************************
printSubjects
This function prints the name and ID of all subjects in a provided linked list.
The information is printed in the following format

  ID   | Name
------ | ----

inputs:
- Root node of a subject linked list
outputs:
- none
*******************************************************************************/
void printSubjects(subject_t* root){
	subject_t* ip = root;
	printf(	"  ID   | Name\n"
			"------ | ----\n");
	while( ip != NULL && ip->next != NULL){
	    printf("%6d | %s\n", ip->ID, ip->name);
	    ip = ip->next;
	}
	printf("\n\n");
}

/*******************************************************************************
printSessions
This function prints the subject ID, date, time and full ID of all sessions
in a provided array. The array extrcts information from the full ID where
information is stored as follows.

[SubjectID][Date][Time]

Additionally if a date or time value contains single digit it is prefaced with
a 9 which is removed to display the correct time.
The information is printed in the following format

 Sub ID  |   Date   | Time  |     ID
-------- | dd/mm/yy | --:-- | ----------

inputs:
- Array of session IDs, amount of IDs in the array as an int
outputs:
- none
*******************************************************************************/
void printSessions(long sessions[], int sessionsAmt){
	int i, ID, day, month, year, hours, minutes;
	long temp;

	printf(	" Sub ID  |   Date   | Time  |     ID\n"
			"-------- | dd/mm/yy | --:-- | ----------\n");

	for(i = 0; i <  sessionsAmt; i++){

		#ifdef DEBUG
		printf("%ld\n", sessions[i]);
		#endif
		temp = sessions[i];
		minutes = temp % 100;
		temp = temp / 100;
		if(minutes / 10 == 9){
			minutes = concatenate(0, minutes % 10);
		}
		hours = temp % 100;
		temp = temp / 100;
		if(hours / 10 == 9){
			hours = concatenate(0, hours % 10);
		}
		year = temp % 100;
		temp = temp / 100;
		if(year / 10 == 9){
			year = concatenate(0, year % 10);
		}
		month = temp % 100;
		temp = temp / 100;
		if(month / 10 == 9){
			month = concatenate(0, month % 10);
		}

		day = temp % 100;
		temp = temp / 100;
		if(day / 10 == 9){
			day = concatenate(0, day % 10);
		}
		ID = temp;


	    printf("%8d | %02d/%02d/%02d | %02d:%02d | %ld\n", ID, day, month, year, hours, minutes, sessions[i]);
	}
	printf("\n\n");
}

/*******************************************************************************
printUsers
This function prints the name, privilege and ID of all users in a provided
linked list.
The information is printed in the following format

   ID    | Privilege | Name
-------- |     -     | ----

inputs:
- Root node of a user linked list
outputs:
- none
*******************************************************************************/
void printUsers(user_t* root){
	user_t* ip = root;
	printf(	"   ID    | Privilege | Name\n"
			"-------- |     -     | ----\n");
	while( ip != NULL && ip->next != NULL){

	    printf("%8d |     %d     | %s\n", ip->ID, ip->privilege, ip->name);
		ip = ip->next;
	}
	printf("\n\n");
}

/*******************************************************************************
printStudents
This function prints the name and ID of all students in a provided linked list.
The information is printed in the following format

  ID   | Name
------ | ----

inputs:
- Root node of a student linked list
outputs:
- none
*******************************************************************************/
void printStudents(student_t* root){
	student_t* ip = root;
	printf(	"   ID    | Name\n"
			"-------- | ----\n");
	while( ip != NULL && ip->next != NULL){
	    printf("%8d | %s\n", ip->ID, ip->name);
	    ip = ip->next;
	}
	printf("\n\n");
}

/*******************************************************************************
printUsersByID
This function prints the name, privilege and ID of all users from a linked list
whose IDs match those in a provided array.
The information is printed in the following format

   ID    | Privilege | Name
-------- |     -     | ----

inputs:
- Root node of a user linked list, an array of IDs, the amount of IDs in the
array as an int
outputs:
- none
*******************************************************************************/
void printUsersByID(user_t* root, int IDs[], int IDamt){
	int i;
	user_t* ip = root;
	printf(	"   ID    | Privilege | Name\n"
			"-------- |     -     | ----\n");
	while( ip != NULL && ip->next != NULL){
		for(i = 0; i < IDamt; i++){
			if(ip->ID == IDs[i]){
				printf("%8d |     %d     | %s\n", ip->ID, ip->privilege, ip->name);
			}
		}
		ip = ip->next;
	}
	printf("\n\n");
}

/*******************************************************************************
printUserSubjects
This function prints the name and ID of all subjects from a provided linked list,
whose userID array contains a provided ID.
The information is printed in the following format

  ID   | Name
------ | ----

inputs:
- Root node of a subject linked list, the ID to compare as an int
outputs:
- none
*******************************************************************************/
void printUserSubjects(subject_t* root, int userID){
	subject_t* ip = root;
	int i;

	printf(	"  ID   | Name\n"
			"------ | ----\n");
	while( ip != NULL && ip->next != NULL){
		for(i = 0; i < ip->usersAmt; i++){
			if(ip->userID[i] == userID){
				printf("%6d | %s\n", ip->ID, ip->name);
			}
		}
		ip = ip->next;
	}
	printf("\n\n");
}

/*******************************************************************************
printUserSubjects
This function prints the name and ID of all subjects from a provided linked list,
whose student linked list contains a provided ID.
The information is printed in the following format

  ID   | Name
------ | ----

inputs:
- Root node of a subject linked list, the ID to compare as an int
outputs:
- none
*******************************************************************************/
void printStudentSubjects(subject_t* subjectsLL, int ID){

	subject_t* subip = subjectsLL;
	student_t* stuip;

	printf(	"  ID   | Name\n"
			"------ | ----\n");

	while(subip != NULL && subip->next != NULL){
		stuip = subip->studentsLL;
		if(subip != NULL){
			while(stuip->next != NULL){
				if(stuip->ID == ID){
	    			printf("%6d | %s\n", subip->ID, subip->name);
				}
				stuip = stuip->next;
			}
		subip = subip->next;
		}

	}
}

/*******************************************************************************
printStudentsBySession
This function prints the name and ID of all students form a provided linked list,
whose attendance array contains a provided session ID.
The information is printed in the following format

  ID   | Name
------ | ----

inputs:
- Root node of a student linked list, the ID to compare as a long
outputs:
- none
*******************************************************************************/
void printStudentsBySession(student_t* student, long session){
	student_t* ip = student;
	int i;

	printf(	"   ID    | Name\n"
			"-------- | ----\n");
	while (ip != NULL && ip->next != NULL){
		for(i = 0; i < ip->attendanceAmt; i++){
			if(ip->attendance[i] == session){
				printf("%8d | %s\n", ip->ID, ip->name);
			}
		}
		ip = ip->next;
	}
}

/*******************************************************************************
addSession
This function prompts the user for all information required to create a session
ID. The function then concatenates all information in the following format.

[SubjectID][Date][Time]

If a single digit is provided for any variable that should be two digits the
function encodes the first 0 with a 9 that will be removed when printing.
i.e. 05 = 95
The function then stores the ID in the session array within a provided subject
struct.
inputs:
- The subject struct to be modified
outputs:
- none
*******************************************************************************/
void addSession(subject_t* subject){
	int day = 0, month = 0, year = 0, hours = -1, minutes = -1;
	long ID;

	while(day == -1 || month == 0 || year == 0){
		printf("Enter date separated by a space (DD MM YY): ");
		scanf("%d %d %d", &day, &month, &year);
		#ifdef DEBUG
		printf("Day: %d\n"
			"Month: %d\n"
			"Year: %d\n", day, month, year);
		#endif
		if(	day < 1 || day > 31 ||
			month < 1 || month > 12 ||
			year < 1 || year > 20){
				printf("Invalid date \n");
				day = 0;
				month = 0;
				year = 0;
		}
	}
	if(day/10 == 0){
		day = concatenate(9, day);
	}
	if(month/10 == 0){
		month = concatenate(9, month);
	}
	if(year/10 == 0){
		year = concatenate(9, year);
	}

	while(hours == -1 || minutes == -1){
		printf("Enter time separated by a space (24 hour time) (HH MM): ");
		scanf("%d %d", &hours, &minutes);

		#ifdef DEBUG
		printf(
			"Hours: %d\n"
			"Minutes: %d\n", hours, minutes);
		#endif

		if(	(minutes < 0 || minutes > 59 ||
			hours < 0 || hours > 24) ||
			(hours == 24 && minutes > 0 )){
				printf("Invalid time \n");
				minutes = -1;
				hours = 0;
		}
	}
	if(hours/10 == 0){
		hours = concatenate(9, hours);
	}
	if(minutes/10 == 0){
		minutes = concatenate(9, minutes);
	}

	ID = concatenate(subject->ID, day);
	ID = concatenate(ID, month);
	ID = concatenate(ID, year);
	ID = concatenate(ID, hours);
	ID = concatenate(ID, minutes);
	subject->sessions[subject->sessionsAmt] = ID;
	subject->sessionsAmt++;
}

/*******************************************************************************
removeSession
This function searches through a subjects session array for a session ID
provided by the user. If the function finds the ID it removes it from the array
if it's not found an error message is printed
inputs:
- The subject struct to be modified
outputs:
- none
*******************************************************************************/
void removeSession(subject_t* subject){
	int i, j;
	long ID;
	ID = selectSession(subject->sessions, subject->sessionsAmt);
	for(i = 0; i < subject->sessionsAmt; i++){
		if(subject -> sessions[i] == ID){
			for(j = 0;j < subject->sessionsAmt-1; j++){
				subject -> sessions[i] = subject -> sessions[i+1];
			}
			subject->sessionsAmt--;
			printf("Session removed");
			return;
		}
	}
	printf("Session doesn't exist");
}

/*******************************************************************************
updatePrivilege
The function changes a user struct's privilege value to an int provided by the
user.
inputs:
- The user struct to be modified
outputs:
- none
*******************************************************************************/
void updatePrivilege(user_t* user){
	int newPrivilege;
	printf("Enter new privilege: ");
	scanf("%d", &newPrivilege);
	user->privilege = newPrivilege;
}

/*******************************************************************************
allocateTutor
This function prompts the user to select a user struct. The struct's ID is then
added to the user ID array within a provided subject struct.
inputs:
- The subject struct to be modified, a list of possible users to be added as a
root node of a linked list
outputs:
- none
*******************************************************************************/
void allocateTutor(subject_t* subject, user_t* usersLL){
	user_t* user = selectUser(usersLL);
	int i;
	if(user != NULL){
		for(i = 0; i < subject->usersAmt; i++){
			if(subject->userID[i] == user->ID){
				printf("User already allocated");
				return;
			}
		}
		subject->userID[subject->usersAmt] = user->ID;
		subject->usersAmt++;
	}
}

/*******************************************************************************
printBaseMenu
This prompts the user for a user ID, then searches through a user ID array from
a provided subject struct comapring IDs to the selected ID. If the ID matches
it is removed otherwise an error message is printed
inputs:
- The subject struct to be modified, all user information as a root node of a
 linked list
outputs:
- none
*******************************************************************************/
void removeTutor(subject_t* subject, user_t* users){
	int i, j, ID;
	printUsersByID(users, subject->userID, subject->usersAmt);
	printf("Enter ID of user to remove: ");
	scanf("%d", &ID);
	for(i = 0; i < subject->usersAmt; i++){
		if(subject->userID[i] == ID){
			for(j = 0;j < subject->usersAmt-1; j++){
				subject->userID[i] = subject->userID[i+1];
			}
			subject->usersAmt--;
			printf("User removed");
			return;
		}
	}
	printf("User isn't allocated");
}

/*******************************************************************************
concatenate
This function concatenates two longs
inputs:
- The two longs to be concatenated
outputs:
- none
*******************************************************************************/
/*TODO - Check if this is plagiarism*/
long concatenate(long x, long y) {
    long pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}

/*******************************************************************************
allocateStudent
This function prompts the user to select a student struct. The struct is then
added to a student linked list within a provided subject struct
inputs:
- The subject struct to be modified, student struct information as the root
node of a linked list
outputs:
- none
*******************************************************************************/
void allocateStudent(subject_t* subject, student_t* studentsLL){

	student_t* ip = subject->studentsLL;
	student_t* student = selectStudent(studentsLL);

	if(student != NULL){
		while (ip->next != NULL){
			if(ip->ID == student->ID){
				printf("Student already allocated\n");
				return;
			}
			ip = ip->next;
		}

		ip->ID = student->ID;
		strcpy(ip->name, student->name);
		ip->attendanceAmt = student->attendanceAmt;

		ip->next = (student_t*) malloc(sizeof(student_t));
		if (ip == NULL)
		{
			printf("Memory error.\n");
			return;
		}

		ip = ip->next;
		ip->next = NULL;
	}

	printf("Student added\n");
}

/*******************************************************************************
removeStudent
This function prompts the user to select a student. The student is then removed
from the linked list within the provided subject struct.
inputs:
- The subject struct to be modified
outputs:
- none
*******************************************************************************/
void removeStudent(subject_t* subject){
	student_t* student  = selectStudent(subject->studentsLL);
	student_t* ip = subject->studentsLL;
	student_t* temp;

	if(student != NULL){
		while(ip != NULL && ip->next != NULL){
			if(ip->ID == student->ID){
				if(ip->next == NULL){
					subject->studentsLL = NULL;
				}else{
					subject->studentsLL = ip->next;
					free(ip);
				}
			}else if(ip->next->ID == student->ID){
				temp = ip->next->next;
				free(ip->next);
				if(temp != NULL){
					ip->next = temp;
				}else{
					ip->next = NULL;
				}
				return;
			}
			ip = ip->next;
		}
	}
}

/*******************************************************************************
markSession
This function prompts the user to select a student and a session. The student
then has a provided session ID added to its attendance array. The function then updates
the matching student struct from the database.
inputs:
- The student database as a root of a linked list, the student struct to be
modified, the session ID to be added
outputs:
- none
*******************************************************************************/
void markSession(student_t* studentsLL, student_t* studentsDB, long session){
	int i, repeat = 1;
	student_t* ip = studentsDB;

	if(session != -1){
		while(repeat == 1){
			student_t* student = selectStudent(studentsLL);
			if(student != NULL){
				for(i = 0; i < student->attendanceAmt; i++){
					if(student->attendance[i] == session){
						printf("Student already marked");
						return;
					}
				}
				student->attendance[student->attendanceAmt] = session;
				student->attendanceAmt++;
				while(ip->next != NULL){
					if(ip->ID == student->ID){
						ip->attendance[ip->attendanceAmt] = session;
						ip->attendanceAmt++;
						#ifdef DEBUG
						printf("Session %ld\n"
								"Student Session %ld\n"
								"Ip Session %ld\n"
								"attendanceAmt %d\n"
							, session, student->attendance[student->attendanceAmt-1], ip->attendance[ip->attendanceAmt-1], ip->attendanceAmt);
						#endif
					}
					ip = ip->next;
				}
				printf("Enter 0 to return to menu or\n"
						"1 to add another student: ");
				scanf("%d", &repeat);
			}else{
				repeat = 0;
			}
		}
	}
}
