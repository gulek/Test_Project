/******************************************************************************
 * @file    exti_config.c                                                     *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @date    2013-02-02                                                        *
 * @brief   This file contains the EXTI configuration (External Interrupts)   *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 ******************************************************************************
 *                    ToDo:                                                   *
 * -                                                                          *
 *****************************************************************************/
 
#define _file_ident_exti_
 
#include "stm32f4xx_rcc.h"
#include "misc.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_exti.h"

 
/*
 * @brief   number of EXTI configurations
 */
#define EXTI_LOCAL_NUM_CONFIGURATION 1
 
 
/*
 * @brief   datatype to store a EXTI configurations
 * 
 * sourcePort of type uint8_t:
 *    Stores the source port
 * sourcePin of type uint8_t:
 *    Stores the source pin
 * initEXTI of type uint8_t:
 *    Stores the EXTI configuration
 * initNVIC of type NVIC_InitTypeDef:
 *    Stores the NVIC configuration
 */
typedef struct
{
  uint8_t           sourcePort;
  uint8_t           sourcePin;
  EXTI_InitTypeDef  initEXTI;
  NVIC_InitTypeDef  initNVIC;
} EXTI_InitData_T;
 
 
/*
 * @brief   array for all GPIO configurations
 */
EXTI_InitData_T EXTI_initCfg_vx[EXTI_LOCAL_NUM_CONFIGURATION] =
{
  {
    .sourcePort = EXTI_PortSourceGPIOA,
    .sourcePin  = EXTI_PinSource0,
    .initEXTI   =
    {
      .EXTI_Line    = EXTI_Line0,
      .EXTI_Mode    = EXTI_Mode_Interrupt,
      .EXTI_Trigger = EXTI_Trigger_Rising,
      .EXTI_LineCmd = ENABLE
    },
    .initNVIC   =
    {
      .NVIC_IRQChannel                    = EXTI0_IRQn,
      .NVIC_IRQChannelPreemptionPriority  = 0x01,
      .NVIC_IRQChannelSubPriority         = 0x01,
      .NVIC_IRQChannelCmd                 = ENABLE
    }
  }
};
 
 
 /*
 * @brief   init all used External Interrupts
 * @param   void
 * @return  void
 */ 
void EXTI_Init_v(void)
{
  /* local variables */
  uint8_t i;

  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  for (i=0; i<EXTI_LOCAL_NUM_CONFIGURATION; i++)
  {
    /* Connect Portpin with Line */
    SYSCFG_EXTILineConfig(EXTI_initCfg_vx[i].sourcePort, EXTI_initCfg_vx[i].sourcePin);
    
    /* Configure EXTI Line */
    EXTI_Init(&(EXTI_initCfg_vx[i].initEXTI));
    
    /* Configure NVIC */
    NVIC_Init(&(EXTI_initCfg_vx[i].initNVIC));    
  }
}
 
 
/* End of File */
 