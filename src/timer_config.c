/******************************************************************************
 * @file    timer_config.c                                                    *
 * @author  Gulek                                                             *
 * @version 2                                                                 *
 * @brief   This file contains the timer configuration                        *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 * 2013-02-03 |          2 | reconfigure TIM2 for 1Hz interrupts              *
 ******************************************************************************
 *                    ToDo:                                                   *
 * -                                                                          *
 *****************************************************************************/

#define _FILEIDENT_timer_config_
 
#include "stm32f4xx_tim.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"

/*
 * @brief   number of TIMER configurations
 */
#define TIMER_LOCAL_NUM_CONFIGURATION 1


/*
 * @brief   typedef for a Clock-Config-Function
 *          possible values: RCC_APB1PeriphClockCmd
 *                           RCC_APB2PeriphClockCmd
 *          others are NOT intended!
 */
typedef void(* const rccPeriphClockCmd_fcnPtr)(uint32_t, FunctionalState);


/*
 * @brief   datatype to store a TIMER configurations
 *
 * rccPeriphClockCmd of type rccPeriphClockCmd_fcnPtr:
 *    Stores the function to activate the needed clock
 * timer of type TIM_TypeDef*
 *    TIMER to be used
 * timerClock of type uint32_t
 *    Stores the matching clock
 * interruptSource of type uint16_t
 *    Stores the source for interrupts (see TIM_interrupt_sources) 
 * initNVIC of type NVIC_InitTypeDef:
 *    Stores the NVIC configuration
 * initTIM of type TIM_TimeBaseInitTypeDef
 *    Stores the TIMER configuration
 */
typedef struct
{
  rccPeriphClockCmd_fcnPtr  rccPeriphClockCmd;
  TIM_TypeDef*              timer;
  uint32_t                  timerClock;
  uint16_t                  interruptSource;
  NVIC_InitTypeDef          initNVIC;
  TIM_TimeBaseInitTypeDef   initTIM;  
} TIMER_InitData_T;


/*
 * @brief   array for all TIMER configurations
 */
TIMER_InitData_T TIMER_initCfg_vx[TIMER_LOCAL_NUM_CONFIGURATION] =
{
  {
    .rccPeriphClockCmd  = RCC_APB1PeriphClockCmd,
    .timer              = TIM2,
    .timerClock         = RCC_APB1Periph_TIM2,
    .interruptSource    = TIM_IT_Update,
    .initNVIC           =
    {
      .NVIC_IRQChannel                    = TIM2_IRQn,
      .NVIC_IRQChannelPreemptionPriority  = 0x00,
      .NVIC_IRQChannelSubPriority         = 0x01,
      .NVIC_IRQChannelCmd                 = ENABLE,
    },
    .initTIM            =
    {
      .TIM_Prescaler          = 84-1, /* APB1-Timer-Clock is 84MHz, so this makes 1MHz @TIM2 */
      .TIM_CounterMode        = TIM_CounterMode_Up,
      .TIM_Period             = 1000000 - 1, /* 1MHz down to 1Hz */
      .TIM_ClockDivision      = 0x00,
      .TIM_RepetitionCounter  = 0
    }
  }
};
 
 
/*
 * @brief   init all used Timers
 * @param   void
 * @return  void
 */  
void TIMER_Init_v(void)
{
  /* local variables */
  uint8_t i;
  
  /* activate the used clocks */
  for (i=0; i<TIMER_LOCAL_NUM_CONFIGURATION; i++)
  {
    TIMER_initCfg_vx[i].rccPeriphClockCmd(TIMER_initCfg_vx[i].timerClock, ENABLE);  
  }
  
  for (i=0; i<TIMER_LOCAL_NUM_CONFIGURATION; i++)
  {
    /* Configure NVIC */
    NVIC_Init(&(TIMER_initCfg_vx[i].initNVIC));
    
    /* Configure TIMER */
    TIM_TimeBaseInit(TIMER_initCfg_vx[i].timer, &(TIMER_initCfg_vx[i].initTIM));
    
    /* Configure TIM Update-Interrupt */
    TIM_ITConfig(TIMER_initCfg_vx[i].timer, TIMER_initCfg_vx[i].interruptSource, ENABLE);
  }
} 
 
 
/* End of File */
