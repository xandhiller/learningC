#include <stdio.h>
#include <stdint.h>

int main (void) 
{
    uint16_t x, y, z;
    printf( 
            "Address of x: %p\n",
            "Address of y: %p\n",
            "Address of z: %p\n",
            &x, &y, &z);

    x = 8;
    printf("x is: %d\nx in binary is: %d\n", x, (bin)x);
    return 0;    
}
