/******************************************************************************
 * @file    irq_timer.h                                                       *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @brief   This file contains export for timer interrupt                     *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 ******************************************************************************
 *                    ToDo:                                                   *
 * -                                                                          *
 *****************************************************************************/
 
#ifndef IRQ_TIMER_H
#define IRQ_TIMER_H

#ifdef _FILEIDENT_irq_timer_
  #define XEXTERN
#else
  #define XEXTERN extern
#endif

/*
 * @brief   enum for irq_mskTIM_u8
 */
enum IRQ_MskTIMER_Enum
{
  IRQ_TIM2_e  = 2
};

/* 
 * @brief   mask for captures interrupts
 *          see IRQ_MskTIMER_Enum for bit identification
 */
XEXTERN volatile uint8_t irq_mskTIM_u8;


#endif // IRQ_TIMER_H
/* End of File */
