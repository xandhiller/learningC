#include <stdio.h>

int main (void)
{
    int array[3] = {99, 10, 42};

    printf("array[-1] == %d\n", array[-1]);

    // Compiler gives a warning. Output a zero. But I think that might be it reading memory from a previous program. 

    return 0;
}
