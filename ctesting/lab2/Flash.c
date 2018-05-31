#include <stdint.h>
#include <stdbool.h>
#include "Flash.h"

// Custom #defines
#define   KiB_PER_BANK        256
#define   SECTORS_PER_BANK    64
#define   PHRASES_PER_SECTOR  512
#define   BYTES_PER_PHRASE    8
#define   BITS_PER_PHRASE     BYTES_PER_PHRASE*8































bool Flash_Init(void)
{
  // If recently emptied (everything equals FFFFFF...FFF)
  // If erased, put in the tower module and my student number

  // Check if phrase empty
  if ( CheckPhraseEmpty( (uint32_t *)(FLASH_DATA_START) ) )
  {
    // Allocate student number var
    // 12551382
    // Allocate tower mode
    // Mode is 1 -> (TOWER_VERSION, 'v',1,0)
  }

  // What else to initialise?



  // To silence warnings
  return true;
}






























bool Flash_AllocateVar(volatile void** variable, const uint8_t size)
{
  // Check if size has valid input
  if ( ((size) != (1)) || ((size) != (2)) || ((size) != (4)) )
  {
    return false;
  }

  // How to check where to write to?

  // Pointer to most recent thing written?


  //

}



bool Flash_Write32(volatile uint32_t* const address, const uint32_t data)
{


  // To silence warnings
  return true;
}


bool Flash_Write8(volatile uint8_t* const address, const uint8_t data)
{

  // To silence warnings
  return true;
}



bool Flash_Erase(void)
{

  // To silence warnings
  return true;
}

// Private functions to facilitate the others.

// static bool LaunchCommand(TFCCOB * commonCommandObject){}

static bool WritePhrase(const uint32_t address, const uint64_t phrase){return true;}

static bool EraseSector(const uint32_t address){return true;}

static bool ModifyPhrase(const uint32_t address, const uint64_t phrase){return true;}













bool CheckPhraseEmpty(const uint32_t * variablePtr)
{
  // Only needs to count to 8, so 8-bit int will do.
  uint8_t i;

  // From start of flash to end of flash is set to ones, all along.
  for (i=0; i<BYTES_PER_PHRASE; i++)
  {
    // Check byte by byte at address
    if ( *( (uint8_t *)(variablePtr)+i ) == (0xFF) )
    {
      continue;
    }
    else
    {
      // At least one bit is not equal to 1, meaning something has been changed.
      return false;
    }
  }
  // All bits are one, which for flash memory means that it has been erased.
  return true;

}
