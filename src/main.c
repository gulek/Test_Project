/******************************************************************************
 * @file    main.c                                                            *
 * @author  Gulek                                                             *
 * @version 3                                                                 *
 * @brief   This file contains the main entrypoint for this software          *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     * 
 * 2013-02-02 |          2 | added waiting for USER_BTN interrupt             * 
 * 2013-02-03 |          3 | test of timer & user-btn                         * 
 *****************************************************************************/

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "gpio_config.h"
#include "exti_config.h"
#include "timer_config.h"
#include "irq_exti.h"
#include "irq_timer.h"



/*
 * @brief    main entrypoint
 * @param    void
 * @retval   void
 */  
int main(void)
{ 
  /* local variables */
  uint8_t i;
  
  
  /* Init Unit GPIO */
  GPIO_Init_v();
  
  /* Init Unit EXTI */
  EXTI_Init_v();
  
  /* Init Unit TIMER */
  TIMER_Init_v();
  
  irq_mskEXTI_u8 = 0;
  irq_mskTIM_u8 = 0;
  
  while (1)
  {
    /* Wait for User-Button-Interrupt */
    while(0 == (irq_mskEXTI_u8 & USER_BTN_e));
    /* reset interrupt mask */
    irq_mskEXTI_u8 &= ~USER_BTN_e;
    
    /* Start Timer */
    TIM_Cmd(TIM2, ENABLE);
    
    for (i=0; i<4; i++)
    {      
      /* set LED-Bit */
      GPIO_SetBits(GPIOD, GPIO_Pin_12<<i);      
      /* wait for timer interrupt (1s) */
      while(0 == (irq_mskTIM_u8 & IRQ_TIM2_e));
      /* reset interrupt mask */
      irq_mskTIM_u8 &= ~IRQ_TIM2_e;
    }
    GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
    TIM_Cmd(TIM2, DISABLE);
    TIM_SetCounter(TIM2, 0);
  }
}


/* End of File */
