/* task 4, 5 and 6*/
#include <string.h> /* strlen */
#include <stdio.h> /* printf, scanf */

#define ARRAY_SIZE 4
#define PALND_SIZE 21

int palndCheck(char str[]);

int main (void)
{
  char word[ARRAY_SIZE], revWord[ARRAY_SIZE], palindrome[PALND_SIZE];
  int n, m;

  printf("Enter a three letter word: ");
  scanf("%s", word);

  printf("Word entered: %s\n", word);

  for(n=0, m=2; n<3; n++, m--)
  {
    revWord[n] = word[m];
  }
  printf("%s\n", revWord);

  printf("%sX%s\n", word, revWord);

  printf("Please enter a string less than %d characters: ", PALND_SIZE-1);
  scanf(" %20[^\n]s", palindrome);

  m = palndCheck(palindrome);

  if (m == 1)
  {
    printf("It's a palindrome!\n");
  }

  if (m == 0)
  {
    printf("Not a palindrome.\n");
  }

  return 0;
}

int palndCheck(char str[])
{
  int n, m, length;
  length = strlen(str);

  for(m=(length-1), n=0; n<=(length-1); n++, m--)
  {
    if (str[m] != str[n])
    {
      return 0; /* Not a palindrome */
    }
  }

  return 1; /* Is a palindrome */
}
