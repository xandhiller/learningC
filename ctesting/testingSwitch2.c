#define   FIFO_SIZE                 256
#define   FIFO_EMPTY                1
#define   FIFO_FULL                 2 // Better solution?
#define   FIFO_NOT_EMPTY_NOT_FULL   3

#include <stdio.h>
#include <stdint.h>



typedef struct
{
    uint16_t End;
    uint16_t Start;
    uint16_t NbBytes;
    uint8_t Buffer[FIFO_SIZE];
} TFIFO;

int countFIFO(TFIFO const * FIFO);

int main (void)
{
    TFIFO FIFO;

    FIFO.Start = 0;
    FIFO.End = FIFO_FULL;

    switch(countFIFO(&FIFO))
    {
      case(FIFO_EMPTY):
        printf("Empty!\n");
      case(FIFO_FULL):
        printf("Full!\n");
      case(FIFO_NOT_EMPTY_NOT_FULL):
        printf("Load her up!\n");
    }

    return 0;
}

int countFIFO(TFIFO const * FIFO)
{
  // Start - End < 0
  if ( ((FIFO->Start) - (FIFO->End)) < 0 )
  {
    switch()
    {

      
    }
  }

  // Start - End >= 0
  else
  {
    switch()
    {

    }
  }

  return 3;

}

// int i = 1;
// int j = 20;
//
// printf("%d\n", (j | i));

// printf("%d\n", (FIFO.Start - FIFO.End));
//
// switch(FIFO.End)
// {
//     case(FIFO_FULL):
//         printf("Full!\n");
// }
//
// switch(FIFO.Start - FIFO.End)
// {
//     case(FIFO_EMPTY):
//         printf("Empty!\n");
//     case(FIFO_FULL):
//         printf("Full!\n");
// }
