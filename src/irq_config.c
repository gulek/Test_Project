/******************************************************************************
 * @file    irq_config.c                                                      *
 * @author  Gulek                                                             *
 * @version 1                                                                 *
 * @date    2013-02-02                                                        *
 * @brief   This file contains the basic interrupt configuration              *
 ******************************************************************************
 *                    History:                                                *
 * - Date ----|- Version --|- Description ----------------------------------- *
 * 2013-02-02 |          1 | file created                                     * 
 *****************************************************************************/

/* 
 * @brief   Top of stack. Defined in linker-file 
 */
extern char __StackTop;


/* 
 * @brief   typedef for interrupt vectors
 */
typedef void(* const irqFunction)(void);


/*
 * @brief     default exception handler
 * @params    void
 * @return    void
 *
 * Handles all unhandled exceptions
 */
void DefaultExceptionHandler_v(void)
{
  while (1) {}
}


/*
 * assign unhandled interrupts to the default irq-handler
 * remove __attribute__[...] to use non-default-handler
 */
void Reset_Handler_v(void);
void NMI_Handler_v(void)                        __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void HardFault_Handler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void MemManage_Handler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void BusFault_Handler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void UsageFault_Handler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void SVC_Handler_v(void)                        __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DebugMon_Handler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void PendSV_Handler_v(void)                     __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void SysTick_Handler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void WWDG_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void PVD_IRQHandler_v(void)                     __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TAMP_STAMP_IRQHandler_v(void)              __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void RTC_WKUP_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void FLASH_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void RCC_IRQHandler_v(void)                     __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI0_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI1_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI2_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI3_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI4_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream0_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream1_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream2_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream3_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream4_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream5_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream6_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void ADC_IRQHandler_v(void)                     __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN1_TX_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN1_RX0_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN1_RX1_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN1_SCE_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI9_5_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM1_BRK_TIM9_IRQHandler_v(void)           __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM1_UP_TIM10_IRQHandler_v(void)           __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM1_TRG_COM_TIM11_IRQHandler_v(void)      __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM1_CC_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM2_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM3_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM4_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void I2C1_EV_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void I2C1_ER_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void I2C2_EV_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void I2C2_ER_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void SPI1_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void SPI2_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void USART1_IRQHandler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void USART2_IRQHandler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void USART3_IRQHandler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void EXTI15_10_IRQHandler_v(void)               __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void RTC_Alarm_IRQHandler_v(void)               __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void OTG_FS_WKUP_IRQHandler_v(void)             __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM8_BRK_TIM12_IRQHandler_v(void)          __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM8_UP_TIM13_IRQHandler_v(void)           __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM8_TRG_COM_TIM14_IRQHandler_v(void)      __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM8_CC_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA1_Stream7_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void FSMC_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void SDIO_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM5_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void SPI3_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void UART4_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void UART5_IRQHandler_v(void)                   __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM6_DAC_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void TIM7_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream0_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream1_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream2_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream3_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream4_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void ETH_IRQHandler_v(void)                     __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void ETH_WKUP_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN2_TX_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN2_RX0_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN2_RX1_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CAN2_SCE_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void OTG_FS_IRQHandler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream5_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream6_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DMA2_Stream7_IRQHandler_v(void)            __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void USART6_IRQHandler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void I2C3_EV_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void I2C3_ER_IRQHandler_v(void)                 __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void OTG_HS_EP1_OUT_IRQHandler_v(void)          __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void OTG_HS_EP1_IN_IRQHandler_v(void)           __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void OTG_HS_WKUP_IRQHandler_v(void)             __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void OTG_HS_IRQHandler_v(void)                  __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void DCMI_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void CRYP_IRQHandler_v(void)                    __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void HASH_RNG_IRQHandler_v(void)                __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));
void FPU_IRQHandler_v(void)                     __attribute__ ((interrupt, weak, alias("DefaultExceptionHandler_v")));


/* 
 * @brief Table of IRQ-function. Table-location is defined in linker-file
 */
__attribute__ ((section(".interrupt_vector")))
irqFunction irqFunctionTable[] = {
  (void*) ((unsigned long) &__StackTop),    /* 0x0000 : Top of stack                                  */  
  
  /* Exception Interrupts */
  Reset_Handler_v,                          /* 0x0004 : Reset Handler                                 */
  NMI_Handler_v,                            /* 0x0008 : NMI Handler                                   */
  HardFault_Handler_v,                      /* 0x000C : Hard Fault Handler                            */
  MemManage_Handler_v,                      /* 0x0010 : MPU Fault Handler                             */
  BusFault_Handler_v,                       /* 0x0014 : Bus Fault Handler                             */
  UsageFault_Handler_v,                     /* 0x0018 : Usage Fault Handler                           */
  0,                                        /* 0x001C : Reserved                                      */
  0,                                        /* 0x0020 : Reserved                                      */
  0,                                        /* 0x0024 : Reserved                                      */
  0,                                        /* 0x0028 : Reserved                                      */
  SVC_Handler_v,                            /* 0x002C : SVCall Handler                                */
  DebugMon_Handler_v,                       /* 0x0030 : Debug Monitor Handler                         */
  0,                                        /* 0x0034 : Reserved                                      */
  PendSV_Handler_v,                         /* 0x0038 : PendSV Handler                                */
  SysTick_Handler_v,                        /* 0x003C : SysTick Handler                               */

  /* External Interrupts */
  WWDG_IRQHandler_v,                        /* 0x0040 : Window WatchDog                               */
  PVD_IRQHandler_v,                         /* 0x0044 : PVD through EXTI Line detection               */
  TAMP_STAMP_IRQHandler_v,                  /* 0x0048 : Tamper and TimeStamps through the EXTI line   */
  RTC_WKUP_IRQHandler_v,                    /* 0x004C : RTC Wakeup through the EXTI line              */
  FLASH_IRQHandler_v,                       /* 0x0050 : FLASH                                         */
  RCC_IRQHandler_v,                         /* 0x0054 : RCC                                           */
  EXTI0_IRQHandler_v,                       /* 0x0058 : EXTI Line0                                    */
  EXTI1_IRQHandler_v,                       /* 0x005C : EXTI Line1                                    */
  EXTI2_IRQHandler_v,                       /* 0x0060 : EXTI Line2                                    */
  EXTI3_IRQHandler_v,                       /* 0x0064 : EXTI Line3                                    */
  EXTI4_IRQHandler_v,                       /* 0x0068 : EXTI Line4                                    */
  DMA1_Stream0_IRQHandler_v,                /* 0x006C : DMA1 Stream 0                                 */
  DMA1_Stream1_IRQHandler_v,                /* 0x0070 : DMA1 Stream 1                                 */
  DMA1_Stream2_IRQHandler_v,                /* 0x0074 : DMA1 Stream 2                                 */
  DMA1_Stream3_IRQHandler_v,                /* 0x0078 : DMA1 Stream 3                                 */
  DMA1_Stream4_IRQHandler_v,                /* 0x007C : DMA1 Stream 4                                 */
  DMA1_Stream5_IRQHandler_v,                /* 0x0080 : DMA1 Stream 5                                 */
  DMA1_Stream6_IRQHandler_v,                /* 0x0084 : DMA1 Stream 6                                 */
  ADC_IRQHandler_v,                         /* 0x0088 : ADC1_v, ADC2 and ADC3s                        */
  CAN1_TX_IRQHandler_v,                     /* 0x008C : CAN1 TX                                       */
  CAN1_RX0_IRQHandler_v,                    /* 0x0090 : CAN1 RX0                                      */
  CAN1_RX1_IRQHandler_v,                    /* 0x0094 : CAN1 RX1                                      */
  CAN1_SCE_IRQHandler_v,                    /* 0x0098 : CAN1 SCE                                      */
  EXTI9_5_IRQHandler_v,                     /* 0x009C : External Line[9:5]s                           */
  TIM1_BRK_TIM9_IRQHandler_v,               /* 0x00A0 : TIM1 Break and TIM9                           */
  TIM1_UP_TIM10_IRQHandler_v,               /* 0x00A4 : TIM1 Update and TIM10                         */
  TIM1_TRG_COM_TIM11_IRQHandler_v,          /* 0x00A8 : TIM1 Trigger and Commutation and TIM11        */
  TIM1_CC_IRQHandler_v,                     /* 0x00AC : TIM1 Capture Compare                          */
  TIM2_IRQHandler_v,                        /* 0x00B0 : TIM2                                          */
  TIM3_IRQHandler_v,                        /* 0x00B4 : TIM3                                          */
  TIM4_IRQHandler_v,                        /* 0x00B8 : TIM4                                          */
  I2C1_EV_IRQHandler_v,                     /* 0x00BC : I2C1 Event                                    */
  I2C1_ER_IRQHandler_v,                     /* 0x00C0 : I2C1 Error                                    */
  I2C2_EV_IRQHandler_v,                     /* 0x00C4 : I2C2 Event                                    */
  I2C2_ER_IRQHandler_v,                     /* 0x00C8 : I2C2 Error                                    */
  SPI1_IRQHandler_v,                        /* 0x00CC : SPI1                                          */
  SPI2_IRQHandler_v,                        /* 0x00D0 : SPI2                                          */
  USART1_IRQHandler_v,                      /* 0x00D4 : USART1                                        */
  USART2_IRQHandler_v,                      /* 0x00D8 : USART2                                        */
  USART3_IRQHandler_v,                      /* 0x00DC : USART3                                        */
  EXTI15_10_IRQHandler_v,                   /* 0x00E0 : External Line[15:10]s                         */
  RTC_Alarm_IRQHandler_v,                   /* 0x00E4 : RTC Alarm (A and B) through EXTI Line         */
  OTG_FS_WKUP_IRQHandler_v,                 /* 0x00E8 : USB OTG FS Wakeup through EXTI line           */
  TIM8_BRK_TIM12_IRQHandler_v,              /* 0x00EC : TIM8 Break and TIM12                          */
  TIM8_UP_TIM13_IRQHandler_v,               /* 0x00F0 : TIM8 Update and TIM13                         */
  TIM8_TRG_COM_TIM14_IRQHandler_v,          /* 0x00F4 : TIM8 Trigger and Commutation and TIM14        */
  TIM8_CC_IRQHandler_v,                     /* 0x00F8 : TIM8 Capture Compare                          */
  DMA1_Stream7_IRQHandler_v,                /* 0x00FC : DMA1 Stream7                                  */
  FSMC_IRQHandler_v,                        /* 0x0100 : FSMC                                          */
  SDIO_IRQHandler_v,                        /* 0x0104 : SDIO                                          */
  TIM5_IRQHandler_v,                        /* 0x0108 : TIM5                                          */
  SPI3_IRQHandler_v,                        /* 0x010C : SPI3                                          */
  UART4_IRQHandler_v,                       /* 0x0110 : UART4                                         */
  UART5_IRQHandler_v,                       /* 0x0114 : UART5                                         */
  TIM6_DAC_IRQHandler_v,                    /* 0x0118 : TIM6 and DAC1&2 underrun errors               */
  TIM7_IRQHandler_v,                        /* 0x011C : TIM7                                          */
  DMA2_Stream0_IRQHandler_v,                /* 0x0120 : DMA2 Stream 0                                 */
  DMA2_Stream1_IRQHandler_v,                /* 0x0124 : DMA2 Stream 1                                 */
  DMA2_Stream2_IRQHandler_v,                /* 0x0128 : DMA2 Stream 2                                 */
  DMA2_Stream3_IRQHandler_v,                /* 0x012C : DMA2 Stream 3                                 */
  DMA2_Stream4_IRQHandler_v,                /* 0x0130 : DMA2 Stream 4                                 */
  ETH_IRQHandler_v,                         /* 0x0134 : Ethernet                                      */
  ETH_WKUP_IRQHandler_v,                    /* 0x0138 : Ethernet Wakeup through EXTI line             */
  CAN2_TX_IRQHandler_v,                     /* 0x013C : CAN2 TX                                       */
  CAN2_RX0_IRQHandler_v,                    /* 0x0140 : CAN2 RX0                                      */
  CAN2_RX1_IRQHandler_v,                    /* 0x0144 : CAN2 RX1                                      */
  CAN2_SCE_IRQHandler_v,                    /* 0x0148 : CAN2 SCE                                      */
  OTG_FS_IRQHandler_v,                      /* 0x014C : USB OTG FS                                    */
  DMA2_Stream5_IRQHandler_v,                /* 0x0150 : DMA2 Stream 5                                 */
  DMA2_Stream6_IRQHandler_v,                /* 0x0154 : DMA2 Stream 6                                 */
  DMA2_Stream7_IRQHandler_v,                /* 0x0158 : DMA2 Stream 7                                 */
  USART6_IRQHandler_v,                      /* 0x015C : USART6                                        */
  I2C3_EV_IRQHandler_v,                     /* 0x0160 : I2C3 event                                    */
  I2C3_ER_IRQHandler_v,                     /* 0x0164 : I2C3 error                                    */
  OTG_HS_EP1_OUT_IRQHandler_v,              /* 0x0168 : USB OTG HS End Point 1 Out                    */
  OTG_HS_EP1_IN_IRQHandler_v,               /* 0x016C : USB OTG HS End Point 1 In                     */
  OTG_HS_WKUP_IRQHandler_v,                 /* 0x0170 : USB OTG HS Wakeup through EXTI                */
  OTG_HS_IRQHandler_v,                      /* 0x0174 : USB OTG HS                                    */
  DCMI_IRQHandler_v,                        /* 0x0178 : DCMI                                          */
  CRYP_IRQHandler_v,                        /* 0x017C : CRYP crypto                                   */
  HASH_RNG_IRQHandler_v,                    /* 0x0180 : Hash and Rng                                  */
  FPU_IRQHandler_v,                         /* 0x0184 : FPU                                           */
};

/* End of File */
