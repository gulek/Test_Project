/******************************************************************************
 * @file    gpio_config.c                                                     *
 * @author  Gulek                                                             *
 * @version 2                                                                 *
 * @brief   This file contains the GPIO configuration                         *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     *
 * 2013-02-02 |          2 | added User-Btn @ PA00                            *
 ******************************************************************************
 *                    ToDo:                                                   *
 * - try to make the configurations 'const' to use less ram                   *
 *****************************************************************************/
 
#define _FILEIDENT_gpio_config_
 
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

 
/*
 * @brief   datatype to store a GPIO configurations
 * 
 * initConfiguration of type GPIO_InitTypeDef:
 *    Stores the actual configuration to be used. Defines pin-id, mode, etc
 * port of type GPIO_TypeDef*:
 *    Stores the GPIO-port to be configured
 * portClock of type uint32_T:
 *    Stores the clock of GPIO-port to be enabled.
 */
typedef struct
{
  GPIO_InitTypeDef  initConfiguration;
  GPIO_TypeDef*     port;
  uint32_t          portClock;  
} GPIO_InitData_T; 
 
 
/*
 * @brief   number of GPIO configurations
 */
#define GPIO_LOCAL_NUM_CONFIGURATION 2
 
 
/*
 * @brief   array for all GPIO configurations
 */
GPIO_InitData_T GPIO_initCfg_vx[GPIO_LOCAL_NUM_CONFIGURATION] =
{
  /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode (LEDs)*/
  {
    .initConfiguration  = 
    {
      .GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15,
      .GPIO_Mode  = GPIO_Mode_OUT,
      .GPIO_Speed = GPIO_Speed_100MHz,
      .GPIO_OType = GPIO_OType_PP,    
      .GPIO_PuPd  = GPIO_PuPd_NOPULL
    },
    .port               = GPIOD,
    .portClock          = RCC_AHB1Periph_GPIOD
  },
  /* Configure PA00 for User-BTN */
  {
    .initConfiguration  = 
    {
      .GPIO_Pin   = GPIO_Pin_0,
      .GPIO_Mode  = GPIO_Mode_IN,
      .GPIO_Speed = GPIO_Speed_100MHz,
      .GPIO_OType = GPIO_OType_PP,
      .GPIO_PuPd  = GPIO_PuPd_NOPULL
    },
    .port               = GPIOA,
    .portClock          = RCC_AHB1Periph_GPIOA    
  }
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
    RCC_AHB1PeriphClockCmd(GPIO_initCfg_vx[i].portClock, ENABLE); 
  }  
  
  /* define input/output behaviour */
  for (i=0; i<GPIO_LOCAL_NUM_CONFIGURATION; i++)
  {
    GPIO_Init(GPIO_initCfg_vx[i].port, &(GPIO_initCfg_vx[i].initConfiguration));
  }
}
 
/* End of File */
 