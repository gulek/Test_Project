/******************************************************************************
 * @file    irq_exti.c                                                        *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @date    2013-02-02                                                        *
 * @brief   This file contains the IRQ handler for external interrupts        *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 ******************************************************************************
 *                    ToDo:                                                   *
 * -                                                                          *
 *****************************************************************************/

#define _file_ident_irqexti_
 
#include "stm32f4xx_exti.h"
#include "irq_exti.h"

/*
 * @brief   IRQ handler for external interrupt on line0
 * @param   void
 * @return  void
 */ 
void EXTI0_IRQHandler_v(void)
{
  /* clear interrupt bit */
  EXTI_ClearITPendingBit(EXTI_Line0);
  
  /* set interrupt flag */
  irq_mskEXTI_u8 |= USER_BTN;
}


/* End of File */
