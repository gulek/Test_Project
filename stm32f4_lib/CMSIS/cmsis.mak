#******************************************************************************
#* @file    cmsis.mak                                                         *
#* @author  Gulek                                                             *
#* @version 1                                                                 *
#* @date    2013-02-02                                                        *
#* @brief   This file contains the makefile for the CMSIS-part of the library *
#******************************************************************************
#*                    History:                                                *
#* - Date ----|- Version --|- Description ----------------------------------- *
#* 2013-02-02 |          1 | file created                                     *
#*****************************************************************************/

# Adding Inc-Directory
INCLUDEFLAGS += -I$(MAIN_MAKEFILE_DIR)CMSIS\inc

# Add Location for Sources
VPATH += $(MAIN_MAKEFILE_DIR)CMSIS\src\

# Add Sources
SOURCES += system_stm32f4xx.c

# End of File
