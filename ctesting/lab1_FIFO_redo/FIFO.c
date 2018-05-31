/*
 * FIFO.c
 *
 *  Created on: 23 Mar 2018
 *      Author: 11850637 Alex Hiller and 12551382 Samin Saif
 */


const int FIRST_INDEX = 0;
const int LAST_INDEX = FIFO_SIZE-1;

void FIFO_Init(TFIFO * const FIFO)
{
  FIFO->End = FIRST_INDEX;
  FIFO->Start = FIRST_INDEX;
  FIFO->NbBytes = 0;
}

bool FIFO_Put(TFIFO * const FIFO, const uint8_t data)
{
  // FIFO full? If so, return error.
  if ( (FIFO->NbBytes) == FIFO_SIZE )
  {
    return false;
  }
  // Place byte into FIFO
  FIFO->Buffer[FIFO->End] = data;
  // Increment FIFO->End to be in next position
  if ( (FIFO->End) < (LAST_INDEX) )
  {
    FIFO->End++;
  }
  else
  {
    FIFO->End = 0;
  }
  // Increase number of bytes.
  FIFO->NbBytes++;
  // Success
  return true;
}


bool FIFO_Get(TFIFO * const FIFO, uint8_t * const dataPtr)
{
  // Check if FIFO is empty, if yes, nothing to fetch, return error.
  if ( (FIFO->NbBytes) == 0 )
  {
    return false;
  }
  // There's space, place data at address
  *(dataPtr) = FIFO->Buffer[FIFO->Start];
  // Increment Start index to be in next position, as long as <
  if ( (FIFO->Start) < (LAST_INDEX) )
  {
    FIFO->Start++;
  }
  else
  {
    FIFO->Start = 0;
  }
  // Decrement the count of the number of bytes
  FIFO->NbBytes--;
  // Success
  return true;
}
