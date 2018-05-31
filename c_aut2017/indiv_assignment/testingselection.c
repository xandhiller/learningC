#include <stdio.h>
#include <stdlib.h>

void printMenu(void);
int Selection(void);

int main(void)
{
  /* The number entered by the user to select from menu */
  int menuchoice = '\0';

  do
  {
    if (menuchoice == 1)
    {
      printf("Menuchoice is %d\n", menuchoice);
    }
    else if (menuchoice == 2)
    {
      printf("Menuchoice is %d\n", menuchoice);
    }
    else if (menuchoice == 3)
    {
      printf("Menuchoice is %d\n", menuchoice);
    }
    else if (menuchoice == 4)
    {
      printf("Menuchoice is %d\n", menuchoice);
    }
    else if (menuchoice == 5)
    {
      printf("Menuchoice is %d\n", menuchoice);
    }
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
Selection
This function is to take in the user's selection.
inputs:
- none
outputs:
- none
*******************************************************************************/
int Selection(void)
{
char selection[50];

 /* Is assigned the numeric value of selection array */
int number;

printMenu();
scanf("%s", selection);

/*
Takes in as many integers entered into selection by the user (up to 10)
and assigns it to the variable 'number'
*/
number = atoi(&selection[0]);

/*
If the user enters a menu selection that is not offered, this 'while' loop
will remain active, performing similar functionality as to previously
*/
while (number <= 0 || number >= 7)
{
  printf("Invalid choice. Enter your choice>");
  scanf("%s", selection);
  number = atoi(&selection[0]);
}

  return number;
}
