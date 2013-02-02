#******************************************************************************
#* @file    cmsis.mak                                                         *
#* @author  Gulek                                                             *
#* @version 1                                                                 *
#* @date    2013-02-02                                                        *
#* @brief   This file contains the makefile for the StdPeriph Driver part     *
#*          of the library 																										*
#******************************************************************************
#*                    History:                                                *
#* - Date ----|- Version --|- Description ----------------------------------- *
#* 2013-02-02 |          1 | file created                                     *
#*****************************************************************************/

# Adding Inc-Directory
INCLUDEFLAGS += -I$(MAIN_MAKEFILE_DIR)STM32F4xx_StdPeriph_Driver\inc

# Add Location for Sources
VPATH += $(MAIN_MAKEFILE_DIR)STM32F4xx_StdPeriph_Driver\src\

# Add Sources
SOURCES += misc.c
SOURCES += stm32f4xx_adc.c
SOURCES += stm32f4xx_can.c
SOURCES += stm32f4xx_crc.c
SOURCES += stm32f4xx_cryp.c
SOURCES += stm32f4xx_cryp_aes.c
SOURCES += stm32f4xx_cryp_des.c
SOURCES += stm32f4xx_cryp_tdes.c
SOURCES += stm32f4xx_dac.c
SOURCES += stm32f4xx_dbgmcu.c
SOURCES += stm32f4xx_dcmi.c
SOURCES += stm32f4xx_dma.c
SOURCES += stm32f4xx_exti.c
SOURCES += stm32f4xx_flash.c
SOURCES += stm32f4xx_fsmc.c
SOURCES += stm32f4xx_gpio.c
SOURCES += stm32f4xx_hash.c
SOURCES += stm32f4xx_hash_md5.c
SOURCES += stm32f4xx_hash_sha1.c
SOURCES += stm32f4xx_i2c.c
SOURCES += stm32f4xx_iwdg.c
SOURCES += stm32f4xx_pwr.c
SOURCES += stm32f4xx_rcc.c
SOURCES += stm32f4xx_rng.c
SOURCES += stm32f4xx_rtc.c
SOURCES += stm32f4xx_sdio.c
SOURCES += stm32f4xx_spi.c
SOURCES += stm32f4xx_syscfg.c
SOURCES += stm32f4xx_tim.c
SOURCES += stm32f4xx_usart.c
SOURCES += stm32f4xx_wwdg.c

# End of File
