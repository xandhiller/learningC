#include <stdio.h>
#include <stdint.h>
#include "Flash.h"

// Testing functions
void castingPointer(void);
void testingCheckPhraseEmpty(void);

// MAIN to coordinate testing functions.
int main (void)
{
  testingCheckPhraseEmpty();

  return 0;
}

void castingPointer(void)
{
  long x;

  printf("Raw pointer address: %p\n", &x);
  printf("Cast in base-10: %ld\n", (long)&x);
}


void testingCheckPhraseEmpty(void)
{
  //
  // uint32_t apples = 0; // Empty test
  uint32_t apples = 0xFFFFFFFF;
  uint32_t apples2 = 0xFFFFFFFF;
  // Set two variables sequentially to act as if the whole phrase is full.

  printf("Location of first variable: %p\n", &apples);
  printf("Location of second variable: %p\n", &apples2);


  // For some reason the compiler allocates the first variable (apples) to a higher address value than the second variable (apples2), so I just had to emulate the tower by passing in the lower address first.
  if ( CheckPhraseEmpty( (&apples2) ) )
  {
    printf("Value is: %u\nCheckPhraseEmpty returned: True\n", apples);
  }
  else
  {
    printf("Value is: %u\nCheckPhraseEmpty returned: False\n", apples);
  }
}
