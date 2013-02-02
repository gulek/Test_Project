/******************************************************************************
 * @file    irq_exti.h                                                        *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @date    2013-02-02                                                        *
 * @brief   This file contains export for external interupt stuff             *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 ******************************************************************************
 *                    ToDo:                                                   *
 * -                                                                          *
 *****************************************************************************/
 
#ifndef IRQ_EXTI_H
#define IRQ_EXTI_H

#ifdef _file_ident_irqexti_
  #define XEXTERN
#else
  #define XEXTERN extern
#endif

/*
 * @brief   enum for irq_mskEXTI_u8
 */
enum IRQMsk_Enum
{
  USER_BTN  = 1
};

/* 
 * @brief   mask for captures interrupts
 *          see IRQMsk_Enum for bit identification
 */
XEXTERN uint8_t irq_mskEXTI_u8;


#endif // IRQ_EXTI_H
/* End of File */
