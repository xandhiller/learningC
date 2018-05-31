/*!
** @file
** @version 1.0
** @brief
**         Main module.
**         This module implements a simple 12-hour clock.
**         It time-stamps button pushes and stores them in a FIFO used a packed representation.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         

/* MODULE main */

// Authors: Alexander Hiller and Samin Saif, Autumn 2018, Embedded Software 48434

// Our #defines
#define FIFO_LENGTH 10
// END our #defines

// #includes from PMcL
// CPU module - contains low level hardware initialization routines
#include "Cpu.h"
// Simple timer
#include "timer.h"
// Button functions
#include "buttons.h"
// LED functions
#include "LEDs.h"
// END #includes from PMcL


// The packed time representation

//   15             12   11                        6    5                       0
// |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
// |       hours       |          minutes            |          seconds            |

typedef uint16_t PackedTime_t;

struct FIFO
{
    uint16_t stamp[FIFO_LENGTH];
    uint16_t * write;
};
typedef struct FIFO FIFO_t;

static uint8_t Seconds;
static uint8_t Minutes;
static uint8_t Hours;

static FIFO_t TimeStamps;

// ***
// You will need to create a FIFO object with a size suitable to store 10 time-stamps using the packed time representation.
// ***

// Function prototypes
void writeFIFO(FIFO_t * ptrTimeStamps, uint16_t * currentTime);
int whereIsWrite(FIFO_t * ptrTimeStamps);
void incrementBySecond();
uint16_t makePacket(uint8_t seconds, uint8_t minutes, uint8_t hours);
// END function prototypes

// PMcL functions
static void OneSecondElapsed(void)
{
  LEDs_Toggle(LED_BLUE);
  // One second has elapsed - update the time here
  incrementBySecond();

}

static void Button1Pressed(void)
{
  LEDs_Toggle(LED_ORANGE);
  // The button has been pressed - put a time-stamp into the FIFO
  PackedTime_t stampTime = makePacket(Seconds, Minutes, Hours);
  writeFIFO(&TimeStamps, &stampTime);
}

static void TowerInit(void)
{
  PE_low_level_init();
  Timer_Init(OneSecondElapsed);
  Buttons_Init(Button1Pressed);
  LEDs_Init();
  __EI();
}
// END PMcL functions


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Initialising */

  initFIFOstruct(&TimeStamps);

  TowerInit();
  /* Write your code here */
  for (;;)
  {

  }
}
/* END main */

/*!
** @}
*/

// Our functions
void incrementBySecond()
{
  if (Seconds == 59)
    {
      if (Minutes == 59)
	{
	  if (Hours == 12)
	    {
	      Seconds = 0;
	      Minutes = 0;
	      Hours = 0;
	    }
	  else
	    Minutes = 0;
	    Hours++;
	}
      else
	Seconds = 0;
	Minutes++;
    }
  else
    Seconds++;
}

void initFIFOstruct(FIFO_t * ptrTimeStamps)
{
    ptrTimeStamps->write = &(ptrTimeStamps->stamp[0]);
    int i;
    // Zero the array. (Can't do {0} trick with an array in a struct)
    for(i=0; i<=FIFO_LENGTH; i++)
    {
        ptrTimeStamps->stamp[i] = 0;
    }

    #ifdef DEBUG
    printf("write pointer is at: %p\n", ptrTimeStamps->write);
    printf("location of stamp[0] is: %p\n", &(ptrTimeStamps->stamp[0]));
    #endif
}

int whereIsWrite(FIFO_t * ptrTimeStamps)
{
    int16_t index;

    //Commented out this statement because it's redundant due to the first statement in writeFIFO   
    /*if (ptrTimeStamps.write == NULL)
    {
        index = -1;
    }*/

    for (index=0; index<FIFO_LENGTH; index++)
    {
        if (ptrTimeStamps.write == &(ptrTimeStamps.stamp[index]))
        {
            break; // Got the array value that write is pointing to.
        }
    }
    return index;
}

void writeFIFO(FIFO_t * ptrTimeStamps, uint16_t * currentTime)
{

    // Check if at NULL
    if (ptrTimeStamps.write == NULL)
    {
        #ifdef DEBUG
        printf("FIFO is full\n");
        #endif

        // Point to the beginning to overwrite the first element bc it's a circular buffer
        ptrTimeStamps.write = &(ptrTimeStamps.stamp[0]);
        ptrTimeStamps->write = *currentTime;
        // Now the value at array element 0 is set, move write to stamp[1]
        ptrTimeStamps.write = &(ptrTimeStamps.stamp[1]);
    }

    // If write is at the end of FIFO, write to index 9 and then point it to NULL.
    else if (whereIsWrite(ptrTimeStamps) == 9)
    {
        ptrTimeStamps->write = *currentTime;
        ptrTimeStamps.write = NULL;
    }

    // Write it to the next place in the array.
    else
    {
        #ifdef DEBUG
        printf("Prior to writing, address of write is: %p\n", ptrTimeStamps->write);
        #endif

        ptrTimeStamps->write = *currentTime;
        ptrTimeStamps.write = &(ptrTimeStamps.stamp[whereIsWrite(ptrTimeStamps)+1]);

        #ifdef DEBUG
        printf("After writing, address of write is: %p\n", ptrTimeStamps->write);
        #endif
    }
}

uint16_t makePacket(uint8_t seconds, uint8_t minutes, uint8_t hours)
{
  uint16_t packet = 0;
  uint16_t transfer = 0;

  transfer = seconds;
  packet |= transfer;

  transfer = minutes;
  transfer <<= 6;
  packet |= transfer;

  transfer = hours;
  transfer <<= 12;
  packet |= transfer;

  return packet;
}

// END our functions
