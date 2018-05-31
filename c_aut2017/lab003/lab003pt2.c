#include <stdio.h>

int main (void)
{
  int x = '\0';
  int y = '\0';

  printf("This program continues until (x,y) = (0,0)\n")

  int inputX(int x);
  int inputY(int y);

  /*
  Include a do-while loop around the boolean logic to cause an execution
  before exiting because variables are intialised to zero. (?) Or do we set
  abritrary starting values to get around this?
  */
  for (input(x,y); x != 0 && y != 0; inputX(x), inputY(y)) {
      printf("Your input is (%d,%d)", x, y);
    if (/* condition */) {
      /* code */
    }
  }

  return 0;
}
/*******************************************************************************
Function input: To take in x and y values.
*******************************************************************************/
int input (x)
{
  scanf("%d", &x);

  return y; 
}
int inputY (y)
{
    scanf("%d", &y);
    return y;
}
