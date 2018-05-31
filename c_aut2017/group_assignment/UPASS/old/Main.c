#include "UPASS.h"
#include "StructCreators.c"

/*******************************************************************************
TODO
 - Implement Privilege
 - Implement Database**
 - Implement Mass Import**
 - Implement Login**
 - Check if structs exist when created

*******************************************************************************/

/*******************************************************************************
Main
*******************************************************************************/
int main(void){
	int choice = -1;

	user_t* currentUser;
	subject_t* selectedSubject;
	user_t* selectedUser;
	student_t* selectedStudent;

	subject_t* subjectLL;
	subjectLL = (subject_t*)malloc(sizeof(subject_t));
	if (subjectLL == NULL){
		printf("Memory error.\n");
		return 1;
	}
	subjectLL->next = NULL;

	user_t* userLL;
	userLL = (user_t*) malloc(sizeof(user_t));
	if (userLL == NULL){
		printf("Memory error.\n");
		return 0;
	}
	userLL->next = NULL;

	student_t* studentsLL;

	studentsLL = (student_t*) malloc(sizeof(student_t));
	if (studentsLL == NULL){
		printf("Memory error.\n");
		return 0;
	}
	studentsLL->next = NULL;

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
				CreateUser(userLL);
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
							markSession(studentsLL, selectSession(selectedSubject->sessions, selectedSubject->sessionsAmt));	
							/*TODO - This should be mark attendance also*/			
							break;	
						case 8 :
							printStudents(selectedSubject->studentsLL);				
							break;	
						case 9 :
							printUsersByID(userLL, selectedSubject->userID, selectedSubject->usersAmt);			
							break;
						case 10 :
							printUsersBySession(studentsLL, selectSession(selectedSubject->sessions, selectedSubject->sessionsAmt));			
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
				printf("Exiting\n");		
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
	"7. Mark attendance\n"
	"8. View students\n"
	"9. View tutors\n"
	"10. View attendance\n"
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
the selected ID.
inputs:
- Root node of a subject struct linked list
outputs:
- Subject ID as an int
*******************************************************************************/
subject_t* selectSubject(subject_t* root){
	int tempID;
	subject_t* ip = root;
	printf("\n\n"
		"Enter 0 to display subject IDs or\n"
		"Enter subject ID: ");
	scanf("%d", &tempID);
	while(tempID == 0){
		printSubjects(root);
		printf("Enter subject ID: ");
		scanf("%d", &tempID);
	}

	while( ip->next != NULL){
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
basic information for all session structs (from the provided linked list)
inlcuding their ID's if the user is unaware of the ID. The function then returns
the selected ID.
inputs:
- Root node of a session struct linked list
outputs:
- Subject ID as an int
*****************************************************************************/
long selectSession(long sessions[], int sessionsAmt){
	int i;
	long tempID;
	printf("\n\n"
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
the selected ID.
inputs:
- Root node of a session struct linked list
outputs:
- Subject ID as an int
*******************************************************************************/
user_t* selectUser(user_t* root){
	int tempID;
	user_t* ip = root;

	printf("\n\n"
		"Enter 0 to display user IDs or\n"
		"Enter user ID: ");
	scanf("%d", &tempID);
	while(tempID == 0){
		printUsers(root);
		printf("Enter user ID: ");
		scanf("%d", &tempID);
	}

	while( ip->next != NULL){
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
the selected ID.
inputs:
- Root node of a student struct linked list
outputs:
- Subject ID as an int
*******************************************************************************/
student_t* selectStudent(student_t* root){
	int tempID;
	student_t* ip = root;
	printf("\n\n"
		"Enter 0 to display student IDs or\n"
		"Enter student ID: ");
	scanf("%d", &tempID);
	while(tempID == 0){
		printStudents(root);
		printf("Enter student ID: ");
		scanf("%d", &tempID);
	}

	while( ip->next != NULL){
		if(ip->ID == tempID){
			return ip;
		}
		ip = ip->next;
	}
	printf("Student doesn't exist\n");
	return NULL;
};

/*
*  ID   | Name
*------ | ----
*/
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

/*ID Format - 3[SubjectID][Date][Time] - 97116798 12 07 96 12 10*/
/*
*  ID   |   Date   | Time
*------ | dd/mm/yy | --:--
*/
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


/*
*   ID    | Privilege | Name
*-------- |     -     | ----
*/
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

/*
*  ID   | Name
*------ | ----
*/
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

void printUsersBySession(student_t* student, long session){
	student_t* ip = student;
	int i;

	printf(	"   ID    | Name\n"
			"-------- | ----\n");
	while (ip != NULL && ip->next != NULL){
		for(i = 0; i < ip->attendanceAmt; i++){
			if(ip->attendance[i] == session){
				printf("%8d | %s\n", ip->ID, ip->name);
			}
			ip = ip->next;
		}
	}
}


void addSession(subject_t* subject){
	int day = 0, month = 0, year = 0, hours = -1, minutes = -1;
	long ID;

	while(day == -1 || month == 0 || year == 0){
		printf("Enter date separated by a space (DD MM YY): ");
		scanf("%d %d %d", &day, &month, &year);
		#ifdef DEBUG
		printf("Day: %d\n"
			"Month: %d\n"
			"Month: %d\n", day, month, year);
		#endif
		if(	day < 1 || day > 31 ||
			month < 1 || month > 12 ||
			year < 1 || year > 17){
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

void updatePrivilege(user_t* user){
	int newPrivilege;
	printf("Enter new privilege: ");
	scanf("%d", &newPrivilege);
	user->privilege = newPrivilege;
}

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

/*TODO - Check if this is plagiarism*/
long concatenate(long x, long y) {
    long pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

void allocateStudent(subject_t* subject, student_t* studentsLL){
	student_t* ip = subject->studentsLL;
	student_t* student = selectStudent(studentsLL);

	if(student != NULL){
		if(ip == NULL){
			subject->studentsLL = student;
			printf("First student added\n");
		}else{
			while(ip->next != NULL){
				if(ip->ID == student->ID){
					printf("Student already allocated\n");
					return;
				}
				ip = ip->next;
			}
			ip->next = student;
			printf("Student added\n");
		}
	}
}

void printStudentSubjects(subject_t* subjectsLL, int ID){

	subject_t* subip = subjectsLL;
	student_t* stuip;

	printf(	"  ID   | Name\n"
			"------ | ----\n");

	while(subip->next != NULL){
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

void markSession(student_t* studentsLL, long session){
	int repeat = 1;

	if(session != -1){
		while(repeat == 1){
			student_t* student = selectStudent(studentsLL);
			student->attendance[student->attendanceAmt] = session;
			student->attendanceAmt++;
			printf("Enter 0 to quit or 1 to continue: ");
			scanf("%d", &repeat);
		}
	}
}






































