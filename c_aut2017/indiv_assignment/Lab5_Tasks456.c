#include <stdio.h>

struct player
{
	char letter;
	int age;
	double avg;

	int read_ret;
};
typedef struct player player_t;

player_t scanPlayer(void);
int savePlayerDetails (player_t p, char filename[]);
player_t readPlayerDetails (char filename[]);

int main(void)
{
	player_t player, readPlayerDetails_ret;
	char filename[30];
	int savePlayerDetails_ret; 

	/*Getting player details*/
	player = scanPlayer();

	/*Asking user for desired filename and creating that filename*/
	fprintf(stdout, "Enter the name of the file you would like to save these details to> ");
	fscanf(stdin, "%s", filename);

	/*Displaying if savePlayerName function succeeded or failed*/
	savePlayerDetails_ret = savePlayerDetails(player, filename);
	if (savePlayerDetails_ret == 0)
	{
		fprintf(stdout, "0 - Player details were successfully written to the filename specified\n");
	}
	else
	{
		fprintf(stdout, "1 - Error, attempt to save player details unsuccessful\n");
	}

	/*Displaying if readPlayerDetails function succeeded or failed*/
	readPlayerDetails_ret = readPlayerDetails(filename);
	if (readPlayerDetails_ret.read_ret == 1)
	{
		fprintf(stdout, "1 - Error, attempt to read player details unsuccessful\n\n");
	}
	else
	{
		fprintf(stdout, "Player details: %c %d %0.2f\n\n", readPlayerDetails_ret.letter, readPlayerDetails_ret.age, readPlayerDetails_ret.avg);
	}

	return 0;
}

player_t scanPlayer(void)
{
	player_t p;

	fprintf(stdout, "\nEnter the first letter of the player name> ");
	fscanf(stdin, " %c", &p.letter);
	fprintf(stdout, "Enter the age> ");
	fscanf(stdin, "%d", &p.age);
	fprintf(stdout, "Enter the batting average> ");
	fscanf(stdin, "%lf", &p.avg);

	return p;
}


int savePlayerDetails (player_t p, char filename[])
{
	FILE *player_details_file = fopen(filename, "w");

	fprintf(stdout, "\nWriting player details to filename '%s'...\n", filename);

	if (player_details_file == NULL)
	{	
		return 1;
	}

	fprintf(player_details_file, "%c %d %.2f", p.letter, p.age, p.avg);
	fclose(player_details_file);

	return 0;
}

player_t readPlayerDetails (char filename[])
{
	FILE *player_details_file = fopen(filename, "r");
	player_t p;

	fprintf(stdout, "\nReading player details from filename '%s'...\n", filename);

	if (player_details_file == NULL)
	{
		p.read_ret = 1;
		return p;
	}

	fscanf(player_details_file, "%c%d%lf", &p.letter, &p.age, &p.avg);

	return p;
}