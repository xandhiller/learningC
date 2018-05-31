#include "UPASS.h"
#include "StructCreators.c"

void saveStudents(student_t* root){
	student_t* ip = root;
	int i;

	FILE* database = fopen(STUDENT_DATABASE, "w+");

	if(database == NULL){
		printf("Failed\n");
		return;
	}

	while(ip != NULL && ip->next != NULL){
		fprintf(database, "%d\n%s\n%d\n",
			ip->ID,
			ip->name,
			ip->attendanceAmt);
		for(i = 0; i < ip->attendanceAmt; i++){
			fprintf(database, "%ld ", ip->attendance[i]);
		}
		fprintf(database, "\n");
		ip = ip->next;
	}
	fclose(database);
}

void createStudents(student_t* root){
	student_t* ip = root;
	int i;


	FILE* database = fopen(STUDENT_DATABASE, "r");

	if(database == NULL){
		printf("Initialising database\n");
		return;
	}

	while(1){
	    fscanf(database, "%d", &ip->ID);
	    fscanf(database, "%*[\n]");
	    fscanf(database, "%[^\n]s", ip->name);
	    fscanf(database, "%*[\n]");
	    fscanf(database, "%d", &ip->attendanceAmt);
	    fscanf(database, "%*[\n]");

	    for(i = 0; i < ip->attendanceAmt; i++){
	    	fscanf(database, "%ld ", &ip->attendance[i]);
	    }

		fscanf(database, "%*[\n]");

	    ip->next = (student_t*) malloc(sizeof(student_t));
	    if (ip == NULL)
	    {
	      printf("Memory error.\n");
	      return;
	    }

	    if(feof(database)){
	      break;
	    }

	    ip = ip->next;
	}

    ip = ip->next;
    ip->next = NULL;

    fclose(database);
}

void saveSubjects(subject_t* root){
	subject_t* ip = root;
	student_t* stuIp;
	int i, studentPrints = 0;

	FILE* database = fopen(SUBJECT_DATABASE, "w+");

	if(database == NULL){
		printf("failed\n");
		return;
	}

	while(ip != NULL && ip->next != NULL){
		fprintf(database, "%d\n%s\n%d\n%d\n",
			ip->ID,
			ip->name,
			ip->sessionsAmt,
			ip->usersAmt);
		for(i = 0; i < ip->sessionsAmt; i++){
			fprintf(database, "%ld ", ip->sessions[i]);
		}
		fprintf(database, "\n");
		for(i = 0; i < ip->usersAmt; i++){
			fprintf(database, "%d ", ip->userID[i]);
		}
		fprintf(database, "\n");

		stuIp = ip->studentsLL;
		while(stuIp != NULL && stuIp->next != NULL){
			studentPrints++;
			stuIp = stuIp->next;
		}
		fprintf(database, "%d\n", studentPrints);

		stuIp = ip->studentsLL;
		while(stuIp != NULL && stuIp->next != NULL){
			fprintf(database, "%d\n%s\n%d\n",
				stuIp->ID,
				stuIp->name,
				stuIp->attendanceAmt);
			for(i = 0; i < stuIp->attendanceAmt; i++){
				fprintf(database, "%ld ", stuIp->attendance[i]);
			}
			fprintf(database, "\n");
			stuIp = stuIp->next;
		}
		
		ip = ip->next;
	}
	fclose(database);
}

void createSubjects(subject_t* root){
	subject_t* ip = root;
	student_t* stuIp;
	int i, j, temp = 0;


	FILE* database = fopen(SUBJECT_DATABASE, "r");

	if(database == NULL){
		printf("Initialising database\n");
		return;
	}

	while(1){
	    fscanf(database, "%d", &ip->ID);
	    fscanf(database, "%*[\n]");
	    fscanf(database, "%[^\n]s", ip->name);
	    fscanf(database, "%*[\n]");
	    fscanf(database, "%d", &ip->sessionsAmt);
	    fscanf(database, "%*[\n]");
	    fscanf(database, "%d", &ip->usersAmt);
	    fscanf(database, "%*[\n]");

	    for(i = 0; i < ip->sessionsAmt; i++){
	    	fscanf(database, "%ld ", &ip->sessions[i]);
	    }

	    fscanf(database, "%*[\n]");

	    for(i = 0; i < ip->usersAmt; i++){
	    	fscanf(database, "%d ", &ip->userID[i]);
	    }

		fscanf(database, "%*[\n]");

		ip->studentsLL = (student_t*) malloc(sizeof(student_t));
		if (ip->studentsLL == NULL){
			printf("Memory error.\n");
			return;
		}
		
		fscanf(database, "%d", &temp);
		fscanf(database, "%*[\n]");

		stuIp = ip->studentsLL;
		printf("Temp: %d\n", temp);
		for(i = 0; i < temp; i++){
		    fscanf(database, "%d", &stuIp->ID);
		    fscanf(database, "%*[\n]");
		    fscanf(database, "%[^\n]s", stuIp->name);
		    fscanf(database, "%*[\n]");
		    fscanf(database, "%d", &stuIp->attendanceAmt);
		    fscanf(database, "%*[\n]");

		    for(j = 0; j < stuIp->attendanceAmt; j++){
		    	fscanf(database, "%ld ", &stuIp->attendance[i]);
		    }

			fscanf(database, "%*[\n]");

		    stuIp->next = (student_t*) malloc(sizeof(student_t));
		    if (stuIp == NULL)
		    {
		      printf("Memory error.\n");
		      return;
		    }
		    stuIp = stuIp->next;
		    stuIp->next = NULL;
		    printf("Test\n");
		}

	    ip->next = (subject_t*) malloc(sizeof(subject_t));
	    if (ip == NULL)
	    {
	      printf("Memory error.\n");
	      return;
	    }

	    if(feof(database)){
	      break;
	    }

	    ip = ip->next;
	}

    ip = ip->next;
    ip->next = NULL;

    fclose(database);
}
