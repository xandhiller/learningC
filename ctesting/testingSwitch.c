#include <stdio.h>

#define NUMBER 0

int main (void)
{
    const int success = 2;
    // success++; // causes error
    int choice = 1;
    int i = 0;
    for (NULL; i<=2; i++, choice++)
    {
        switch(choice, success)
        {


            case(1, 2):
                printf("This is case 1\n");
                continue;
                // continue breaks out of the switch statement and into the
                // parent loop.

            case(2, 2):
                printf("This is case 2\n");
                break;

            default:
                continue;
        }
    }
    return 0;
}

// nb:
// const int i = 0;
// FIFO->End = LAST_INDEX;
// switch(FIFO->End)
// {
//     case(i):
//         printf("You can use i!\n"); // Just can't do it in C99? What did PMcL say?
//
//     case(LAST_INDEX):
//         printf("You can use #define(s)!\n");
//         // Just can't do it in C99? What did PMcL say? "You can use #defines
//         // but you can't use const(s), solely for switch statements."
//         // Otherwise, try to use "const int var;"
//
//
//     default:
//         break;
//
// }
