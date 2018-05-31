#include <stdio.h>

#define CONSTANT 5.2
#define CONSTANT 5.2


int main (void)
{
  printf("Program worked. Value of CONSTANT is %lf\n", CONSTANT);

  return 0;
}


/*
Notes:
You can define the same constant twice. It won't cause errors.
If the value is an integer, use %d to call it in a print function.
If the value has a decimal place, use %lf or %f to call it in a
print function.
*/
