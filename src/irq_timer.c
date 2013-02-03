/******************************************************************************
 * @file    irq_timer.c                                                       *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @brief   This file contains the timer interrupt handlers                   *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-03 |          1 | file created                                     * 
 *****************************************************************************/

#define _FILEIDENT_irq_timer_
 
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "irq_config.h"
#include "irq_timer.h"
 
/*
 * @brief   TIM2 interrupt handler
 * @param   void
 * @return  void
 */
void TIM2_IRQHandler_v(void)
{
  if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) != RESET)
  {
    TIM_ClearFlag(TIM2, TIM_IT_Update);
    irq_mskTIM_u8 |= IRQ_TIM2_e;
  }
  else
  {
    /* Unexpected Interrupt */
    Error_Handler_v(2);
  }
}
    
/* End of File */
