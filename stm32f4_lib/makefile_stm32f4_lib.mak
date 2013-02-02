#******************************************************************************
#* @file    makefile_stm32f4_lib.mak                                          *
#* @author  Gulek                                                             *
#* @version 1                                                                 *
#* @date    2013-02-02                                                        *
#* @brief   This file contains the makefile for the stm32f4 library           *
#******************************************************************************
#*                    History:                                                *
#* - Date ----|- Version --|- Description ----------------------------------- *
#* 2013-02-02 |          1 | file created                                     *
#*****************************************************************************/

CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

SRCDIR=src

# Compiler flags
# -O0                   no optimization
# -Wall                 all warnings
# -mcpu=cortex-m4       really?
# -mfpu=fpv4-sp-d16     activates floating point unit
# -g3                   debug-level 3
# -Wa,-adhlns="$@.lst"  creates assembler-listing of source
CFLAGS  += -O0 
#CFLAGS += -fsingle-precision-constant
CFLAGS += -Wall
#CFLAGS += -fmessage-length=0
CFLAGS += -mcpu=cortex-m4
#CFLAGS += -fno-common
#CFLAGS += -std=c99
#CFLAGS += -MD
#CFLAGS += -MP
#CFLAGS += -MF
#CFLAGS += -Wl,-nostdlib
#CFLAGS += -Wl,-nostartfiles
#CFLAGS += -Wl,-nodefaultlibs
#CFLAGS += -nodefaultlibs
#CFLAGS += -nostdlib
#CFLAGS += -nostartfiles 
CFLAGS += -mthumb
#CFLAGS += -mfloat-abi=hard
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -g3
CFLAGS += -gdwarf-2
#CFLAGS += -Wa,-adhlns="$@.lst"
CFLAGS += -Dassert_param(X)=((void)0)

MAIN_MAKEFILE_DIR = $(dir $(firstword $(MAKEFILE_LIST)))
# Include sub library makefiles
include $(MAIN_MAKEFILE_DIR)CMSIS\cmsis.mak
include $(MAIN_MAKEFILE_DIR)STM32F4xx_StdPeriph_Driver\STM32F4xx_StdPeriph_Driver.mak



# Linker flags
# -nostdlib             no standart libraries
LDFLAGS =

# Output directory
OBJDIR=Output
# Output file
OUTPUTFILE=$(OBJDIR)\libstm32f4.a

# Sources

OBJECTS=$(addprefix $(OBJDIR)\,$(SOURCES:.c=.o))


# Default target
cmsis_library : $(OUTPUTFILE)
	
# Debug target
debug:
	@echo MAIN_MAKEFILE_DIR : $(MAIN_MAKEFILE_DIR)
	@echo VPATH             : $(VPATH)
	@echo INCLUDEFLAGS      : $(INCLUDEFLAGS)
	
# don't allow echoing of commands
.SILENT:

# Target: CMSIS-Library
$(OUTPUTFILE): $(OBJECTS)
	@echo ### BUILDING $(OUTPUTFILE)
	$(AR) rcs $(OUTPUTFILE) $(OBJECTS)
	
# Automatic target for alle sources
$(OBJDIR)\\%.o: %.c | $(OBJDIR)
	@echo ### MAKING $(notdir $<)
	$(CC) $(INCLUDEFLAGS) $(CFLAGS) -c $< -o $@


$(OBJDIR):
	mkdir $(OBJDIR)


.PHONY: clean
clean:
	@echo ### CLEANING ...
	rmdir /q /s $(OBJDIR)
