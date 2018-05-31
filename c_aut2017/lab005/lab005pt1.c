#include <stdio.h>
#include <stdlib.h>

struct player
{
  char letter;
  int age;
  double avg;
};
typedef struct player player_t;

player_t writedetails(void);
void printdetails(player_t playerA);
void compAB (player_t playerA, player_t playerB);

int main (void)
{
  player_t playerA;
  player_t playerB;
  printf("\nPlayer A:\n");
  playerA = writedetails();
  printf("Player B:\n");
  playerB = writedetails();
  printf("\n");
  printdetails(playerA);
  printdetails(playerB);
  printf("\n");
  compAB(playerA, playerB);
  printf("\n");

  return 0;
}
/*******************************************************************************
Functions
*******************************************************************************/


player_t writedetails(void)
{
  player_t playerdetails;
  printf("\nEnter the first letter of the player's name> ");
  scanf(" %c", &playerdetails.letter);
  printf("\nEnter the player's age> ");
  scanf("%d", &playerdetails.age);
  printf("\nEnter the player's batting average> ");
  scanf("%lf", &playerdetails.avg);
  printf("\n");
  return playerdetails;
}

void printdetails(player_t playerA)
{
  printf("%c %d %lf\n", playerA.letter, playerA.age, playerA.avg);
}

void compAB(player_t playerA, player_t playerB)
{
  if(playerA.avg >= playerB.avg+10)
  {
    printf("1: Player A is better than B\n");
  }
  else if(playerB.avg >= playerA.avg+10)
  {
    printf("-1: Player B is better than A\n");
  }
  else if(abs(playerA.avg - playerB.avg) <= 10)
  {
    if(abs(playerA.age - playerB.age) >= 15)
    {
      if(playerA.age >= playerB.age)
      {
        printf("1: Player A is better than player B\n");
      }
      else if(playerB.age >= playerA.age)
      {
        printf("-1: Player B is better than player A\n");
      }
    }
    else
    {
      printf("0: players are indifferent\n");
    }
  }
}
