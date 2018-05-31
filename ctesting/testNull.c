#include <stdio.h>
#include <stdint.h>

int main (void)
{
    int x = (int)NULL;

    printf("NULL cast as in int looks like: %d\n", x);

    // Spoiler: It comes out as a zero.
   
    int16_t y = -1;

    printf("int16_t assigned -1 comes out as: %d\n", y);

    // Prediction: It will come out negative.
    // It came out negative.

    uint16_t z = -1;
    
    printf("uint16_t assigned -1 comes out as: %d\n", z);

    // Prediction: It will come out negative.
    // It rolled around and came out as 65535. (Recall that a 16bit number can go up to 65536 = 2^(16).
 
    return 0;
}
