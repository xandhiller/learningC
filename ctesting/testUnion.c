#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint16_t l;
    struct
    {
        uint8_t Lo;
        uint8_t Hi;    
    } s;
} uint16union_t;

int main (void)
{
    uint16union_t splitBoy;

    splitBoy.l = 500;

    printf("l is: %d\n", splitBoy.l); 

    uint8_t reg1 = splitBoy.s.Lo;
    uint8_t reg2 = splitBoy.s.Hi;

    printf("reg1 is: %d\nreg2 is: %d\n", reg1, reg2);

    splitBoy.s.Lo = 500;

    printf("reg1 is: %d\nreg2 is: %d\n", reg1, reg2);
   
}
