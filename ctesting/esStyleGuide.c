// ITEM_1: OPENING COMMENTS
/*

Opening comments
1. Reference to the file name
2. Overall purpose of module
3. Names of programmers
4. Creation date
5. Last update date
6. Hardware configuration required to use the module
7. Software configuration required to use the module
8. Copyright information

*/




// ITEM_2: INCLUDING .H FILES
// Start at the lowest level and move to the highest.

#include <stdio.h>
#include <stdint.h>       // Commonly used but perhaps unfamiliar libraries
#include <stdbool.h>

#define   SIZE    10      // No magic numbers

int main (void)
{
  uint8_t * varPtr;       // Give hint about the type of the variable.
  uint8_t byteBuf[SIZE];  // Also give hints about whether it's a buffer or not.
  bool varFlag;           // Indicate if it's a boolean flag
  uint8_t varIndex;       // Index to an array
  uint8_t nbBytes;        // If you want to indicate the word number, use the
                          //  abbreviation "nb" not "no". This would be used
                          //  a counter.
  //
  // Use the same name to refer to the same type of object.





  return 0;
}
