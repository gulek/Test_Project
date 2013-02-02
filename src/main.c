/******************************************************************************
 * @file    main.c                                                            *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @date    2013-02-02                                                        *
 * @brief   This file contains the main entrypoint for this software          *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     * 
 * 2013-02-02 |          2 | added waiting for USER_BTN interrupt             * 
 *****************************************************************************/

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "gpio_config.h"
#include "exti_config.h"
#include "timer_config.h"
#include "irq_exti.h"


/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);
/* Private functions ---------------------------------------------------------*/

uint32_t mycounter = 0;

/*
 * @brief    main entrypoint
 * @param    void
 * @retval   void
 */  
int main(void)
{ 
TIM_ClearITPendingBit(TIM2, TIM_IT_Update | TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4 | TIM_IT_COM | TIM_IT_Trigger | TIM_IT_Break);
  /* Init Unit GPIO */
  GPIO_Init_v();
  EXTI_Init_v();
  TIMER_Init_v();

  while (1)
  {
    mycounter++;
    if (mycounter == 100) mycounter = 0;
    
    while(0 == (irq_mskEXTI_u8 & USER_BTN));
    
    TIM_SetCounter(TIM2, 0);
    TIM_Cmd(TIM2, ENABLE);
    
    irq_mskEXTI_u8 &= ~USER_BTN;
    
    /* PD12 to be toggled */
    GPIO_SetBits(GPIOD, GPIO_Pin_12);
    
    /* Insert delay */
    Delay(0x3FFFFF);
    
    /* PD13 to be toggled */
    GPIO_SetBits(GPIOD, GPIO_Pin_13);
    
    /* Insert delay */
    Delay(0x3FFFFF);
  
    /* PD14 to be toggled */
    GPIO_SetBits(GPIOD, GPIO_Pin_14);
    
    /* Insert delay */
    Delay(0x3FFFFF);
    
    /* PD15 to be toggled */
    GPIO_SetBits(GPIOD, GPIO_Pin_15);
    
    /* Insert delay */
    Delay(0x7FFFFF);
    
    GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
    
    /* Insert delay */
    Delay(0xFFFFFF);
  }
}

/**
  * @brief  Delay Function.
  * @param  nCount:specifies the Delay time length.
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}