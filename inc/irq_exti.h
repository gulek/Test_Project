/******************************************************************************
 * @file    irq_exti.h                                                        *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @brief   This file contains export for external interupt                   *
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

#ifdef _FILEIDENT_irq_exti_
  #define XEXTERN
#else
  #define XEXTERN extern
#endif

/*
 * @brief   enum for irq_mskEXTI_u8
 */
enum IRQ_MskEXTI_Enum
{
  USER_BTN_e  = 1
};

/* 
 * @brief   mask for captures interrupts
 *          see IRQ_MskEXTI_Enum for bit identification
 */
XEXTERN volatile uint8_t irq_mskEXTI_u8;


#endif // IRQ_EXTI_H
/* End of File */
