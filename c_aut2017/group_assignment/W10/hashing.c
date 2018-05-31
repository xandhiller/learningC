#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH_LENGTH 70
#define MAX_PASSWORD_LENGTH 40


char[] salt(char[] password);

int main (void)
/*
When making the header file, add the funciton prototype above and
change the main
*/
{

  #ifdef TEST
  char enteredPassword[MAX_PASSWORD_LENGTH];
  printf("Enter password to be hashed.\n");
  scanf ("%s", enteredPassword);
  #endif


  char hashedP[MAX_PASSWORD_LENGTH];

  salt(enteredPassword);

  



  return 0;
  /*
  When making header file, change the return value to be the salted and
  hashed password.
  */
}

char[] salt(char[] password)
{
  /* TODO: Add strings for every letter of the alphabet */
  strcat(enteredPassword, "poop");

  return saltedPassword;
}
