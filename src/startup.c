/******************************************************************************
 * @file    startup.c                                                         *
 * @author  Gulek                                                             *
 * @version 2                                                                 *
 * @brief   This file contains the startup-functionality                      *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     * 
 * 2013-02-03 |          2 | call error handler after main                    * 
 *****************************************************************************/

#define _FILEIDENT_startup_
 
#include "stm32f4xx.h"
#include "irq_config.h"

/* 
 * @brief   functions from other units
 */
int main(void);


/* 
 * @brief   mem-adr from linker-file
 */
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;


/*
 * @brief     reset-handler
 * @params    void
 * @return    void
 *
 * Loads initialized data to RAM, and clears uninitialized data.
 */
void Reset_Handler_v(void)
{
  uint32_t *pSrc;
  uint32_t *pDest;

  /* Load initialized data from FLASH to RAM */
  pSrc = &__etext;
  pDest = &__data_start__;
  while (pDest < &__data_end__)
  {
    *pDest++ = *pSrc++;
  }

  /* Clear uninitialized data */
  pDest = &__bss_start__;
  while (pDest < &__bss_end__)
    *pDest++ = 0;

  /* call init from stm32-lib for clock, etc */
  SystemInit();
    
  /* start actual software */
  main();
  
  /* This should never happen. main() should not return */
  Error_Handler_v(1);
}

/* End of File */
