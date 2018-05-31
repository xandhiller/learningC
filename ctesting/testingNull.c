#define FIFO_SIZE 256

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t End;
    uint8_t Start;
    uint8_t NbBytes;
    uint8_t Buffer[FIFO_SIZE];
} TFIFO;

void assign(TFIFO * const FIFO);

int main (void)
{
    TFIFO FIFO;

    printf("%p\n", &(FIFO.End));
    assign(&FIFO);

    if (NULL == FIFO.End)
    {
        printf("NULL == FIFO.End\n");
    }
}

void assign(TFIFO * const FIFO)
{
    uint8_t * p;
    p = &(FIFO->End);
    printf("%p\n", p);
}
