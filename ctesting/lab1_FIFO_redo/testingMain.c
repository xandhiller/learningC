#include <stdio.h>
#include "FIFO.h"
#include "FIFO.c"

void printX(bool x);

int main(void)
{
    TFIFO FIFO;

    FIFO_Init(&FIFO);
    printf("FIFO.End = %d\nFIFO.Start = %d\nFIFO.NbBytes = %d\n", FIFO.End, FIFO.Start, FIFO.NbBytes);

    int i; // Counter
    bool x; // Output check
    // Test writing
    for(i=0; i<FIFO_SIZE+2; i++)
    {

        x = FIFO_Put(&FIFO, i+10);
        if( x == true)
        {
        printf("i = %d\nFIFO.End = %d\nFIFO.Start = %d\nFIFO.NbBytes = %d\n", i, FIFO.End, FIFO.Start, FIFO.NbBytes);
        }
        if(x == false)
        {
            printf("FIFO is full.\n");
        }
    }

    // // Test that buffer has the data
    // for(i=0; i<FIFO_SIZE; i++)
    // {
    //     printf("Buffer[%d]: %d\n", i, FIFO.Buffer[i]);
    // }

    // Get the data out, print it. Go beyond the amount in there, see what happens.
    uint8_t j; // temp storage of buffer data for display.
    for(i=0; i<FIFO_SIZE+10; i++)
    {
        x = FIFO_Get(&FIFO, &j);
        printX(x);
        if( x == true)
        {
        printf("i = %d\nj = %d\nFIFO.End = %d\nFIFO.Start = %d\nFIFO.NbBytes = %d\n", i, j, FIFO.End, FIFO.Start, FIFO.NbBytes);
        }
        if(x == false)
        {
            printf("i = %d\nFIFO is empty!\n", i);
        }
    }

    // fill it up again
    for(i=0; i<FIFO_SIZE+2; i++)
    {

        x = FIFO_Put(&FIFO, i+10);
        if( x == true)
        {
        printf("i = %d\nFIFO.End = %d\nFIFO.Start = %d\nFIFO.NbBytes = %d\n", i, FIFO.End, FIFO.Start, FIFO.NbBytes);
        }
        if(x == false)
        {
            printf("FIFO is full.\n");
        }
    }

    // Test that buffer has the data
    for(i=0; i<FIFO_SIZE; i++)
    {
        printf("Buffer[%d]: %d\n", i, FIFO.Buffer[i]);
    }


    return 0;
}

void printX(bool x)
{
    if( x == true )
    {
        printf("x is true!\n");
    }

    if(x == false)
    {
        printf("x is false\n");
    }
}
