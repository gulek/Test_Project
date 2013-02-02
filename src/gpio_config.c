/******************************************************************************
 * @file    gpio_config.c                                                     *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @date    2013-02-02                                                        *
 * @brief   This file contains the GPIO configuration                         *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 ******************************************************************************
 *                    ToDo:                                                   *
 * - try to make the configurations 'const' to use less ram                   *
 *****************************************************************************/
 
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
 
/*
 * @brief   number of GPIO configurations
 */
#define GPIO_LOCAL_NUM_CONFIGURATION 1
 
 
/*
 * @brief   array for all GPIO configurations
 */
GPIO_InitTypeDef GPIO_initCfg_vx[GPIO_LOCAL_NUM_CONFIGURATION] =
{
  /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode (LEDs)*/
  {
    .GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15,
    .GPIO_Mode  = GPIO_Mode_OUT,
    .GPIO_OType = GPIO_OType_PP,
    .GPIO_Speed = GPIO_Speed_100MHz,
    .GPIO_PuPd  = GPIO_PuPd_NOPULL
  }
};


/*
 * @brief   array of all used GPIO-Clocks
 */
uint32_t GPIO_initClocks_u32[GPIO_LOCAL_NUM_CONFIGURATION] =
{
  RCC_AHB1Periph_GPIOD /* GPIOD for LEDs */  
};
 
/*
 * @brief   init all GPIO-Pins
 * @param   void
 * @return  void
 */ 
void GPIO_Init_v(void)
{
  /* local variables */
  uint8_t i;
 
  /* activate all needed GPIO-Clocks */  
  for (i=0; i<GPIO_LOCAL_NUM_CONFIGURATION; i++)
  {
    RCC_AHB1PeriphClockCmd(GPIO_initClocks_u32[i], ENABLE); 
  }  
  
  /* define input/output behaviour */
  for (i=0; i<GPIO_LOCAL_NUM_CONFIGURATION; i++)
  {
    GPIO_Init(GPIOD, &(GPIO_initCfg_vx[i]));
  }
}
 
 /* End of File */
 