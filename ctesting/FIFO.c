#define FIFO_LENGTH 10
//#define DEBUG
//#define TEST_WHERE_WRITE
//#define TEST_READ_FIFO
//#define TEST_WRITE_FIFO
//#define TEST_CONVERT_BINARY
#define TEST_BIT
#include <stdio.h>
#include <stdint.h>

struct FIFO
{
    uint16_t stamp[FIFO_LENGTH];
    uint16_t * read;
    uint16_t * write;
};
typedef struct FIFO FIFO_t;






// Write Calling - ORANGE LED PRESSED
PackedTime_t stampTime = makePacket(Seconds, Minutes, Hours);
writeFIFO(&TimeStamps, stampTime);






struct time
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
};
typedef struct time time_t;

void initWrite(FIFO_t * ptrTimeStamps);
void writeFIFO(FIFO_t * ptrTimeStamps, uint16_t * currentTime);
void printFIFO(FIFO_t * ptrTimeStamps);
int whereIsWrite(FIFO_t * ptrTimeStamps);
long convertToBinary(uint16_t number);
uint16_t * timeStamp16Bit(time_t * currentTime);

time_t currentTime;

int main (void)
{
    int i;
    FIFO_t timeStamps;

    // Zero the array. (Can't do {0} trick with an array in a struct)
    for(i=0; i<=FIFO_LENGTH; i++)
    {
        timeStamps.stamp[i] = 0;
    }

    initWrite(&timeStamps);

    #ifdef TEST_WHERE_WRITE
    timeStamps.write = &(timeStamps.stamp[7]);
    printf("The locations of the 8th element (index 7) of stamp is: %p\n", &(timeStamps.stamp[7]));
    printf("The location of write is: %p\n", timeStamps.write);
    printf("Calling whereIsWrite(&timeStamps)...\n");
    printf("whereIsWrite(&timeStamps) returned: %d\n", whereIsWrite(&timeStamps));
    #endif

    #ifdef TEST_READ_FIFO
    for (i=0; i<FIFO_LENGTH; i++)
    {
        timeStamps.stamp[i] = i+3;
    }
    printFIFO(&timeStamps);
    #endif

    #ifdef TEST_WRITE_FIFO
    uint16_t testInt;
    for (testInt=1; testInt<=15; testInt++)
    {
        writeFIFO(&timeStamps, &testInt);
        printf("FIFO register is currently: \n");
        for (i=0; i<FIFO_LENGTH; i++)
        {
            printf("Index: %d\t Value: %d\n", i, timeStamps.stamp[i]);
        }
    } // Will write 1-10, then overflow, and write 11-15 at the beginning of the array.
    #endif

    #ifdef TEST_CONVERT_BINARY
    int number = 8;
    long result;
    result = convertToBinary(number);
    printf("The input was: %d\nThe output is: %lu\n", number, result);
    #endif

    #ifdef TEST_BIT

    #endif

    return 0;
}

void initWrite(FIFO_t * ptrTimeStamps)
{
    ptrTimeStamps->write = &(ptrTimeStamps->stamp[0]);

    #ifdef DEBUG
    printf("write pointer is at: %p\n", ptrTimeStamps->write);
    printf("location of stamp[0] is: %p\n", &(ptrTimeStamps->stamp[0]));
    #endif
}

void writeFIFO(FIFO_t * ptrTimeStamps, uint16_t * currentTime)
{
    // Check if at NULL, if so overwrite element 0
    if (ptrTimeStamps->write == NULL)
    {
        #ifdef DEBUG
        printf("FIFO is full\n");
        #endif

        ptrTimeStamps->write = &(ptrTimeStamps->stamp[0]);
        *(ptrTimeStamps->write) = *(currentTime);
        ptrTimeStamps->write = &(ptrTimeStamps->stamp[1]);
    }

    // If write is at the end of FIFO, write to index 9 and point it to NULL.
    else if (whereIsWrite(ptrTimeStamps) == 9)
    {
        *(ptrTimeStamps->write) = *(currentTime);
        ptrTimeStamps->write = NULL;
    }

    // Write it to the next place in the array.
    else
    {
        #ifdef DEBUG
        printf("Prior to writing, address of write is: %p\n", ptrTimeStamps->write);
        #endif

        *(ptrTimeStamps->write) = *(currentTime);
        ptrTimeStamps->write++;

        #ifdef DEBUG
        printf("After writing, address of write is: %p\n", ptrTimeStamps->write);
        #endif
    }
}

void printFIFO(FIFO_t * ptrTimeStamps)
{
    int i;

    for (i=0; i<FIFO_LENGTH; i++)
    {
        printf("%d\n", ptrTimeStamps->stamp[i]);
    }
}

int whereIsWrite(FIFO_t * ptrTimeStamps)
{
    int16_t index;

    if (ptrTimeStamps->write == NULL)
    {
        index = -1;
    }

    for (index=0; index<FIFO_LENGTH; index++)
    {
        if (ptrTimeStamps->write == &(ptrTimeStamps->stamp[index]))
        {
            break; // Got the array value that write is pointing to.
        }
    }
    return index;
}

long convertToBinary(uint16_t number)
{
    if (number == 0) return 0;
    if (number ==1) return 1;
    return (number%2) + 10*convertToBinary(number/2);
}

uint16_t * timeStamp16Bit(time_t * currentTime)
{

}
