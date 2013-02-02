#******************************************************************************
#* @file    makefile                                                          *
#* @author  Gulek                                                             *
#* @version 1                                                                 *
#* @date    2013-02-02                                                        *
#* @brief   This file contains the makefile for the stm32f4 test project      *
#******************************************************************************
#*                    History:                                                *
#* - Date ----|- Version --|- Description ----------------------------------- *
#* 2013-02-02 |          1 | file created                                     * 
#*****************************************************************************/

CC=arm-none-eabi-gcc


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
CFLAGS += -std=c99
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


# Linker-Flags
LDFLAGS += -Tlink\stm32f407vg.ld
LDFLAGS += -nostdlib
LDFLAGS += -Wl,-Map,$(OUTPUTFILE:.elf=.map)

# don't allow echoing of commands
.SILENT:

# Output-File
OBJDIR=Output
OUTPUTFILE=$(OBJDIR)\test.elf


# Source-Files
SOURCES += main.c
SOURCES += irq_config.c
SOURCES += startup.c
SOURCES += gpio_config.c
SOURCES += exti_config.c
SOURCES += irq_exti.c
SOURCES += timer_config.c

OBJECTS=$(addprefix $(OBJDIR)\,$(SOURCES:.c=.o))

VPATH += src

INCLUDEFLAGS += -Istm32f4_lib\STM32F4xx_StdPeriph_Driver\inc
INCLUDEFLAGS += -Istm32f4_lib\CMSIS\inc
INCLUDEFLAGS += -Iinc

LIBRARIES = stm32f4
LIBRARYFILES = $(addsuffix .a,$(addprefix $(OBJDIR)\lib,$(LIBRARIES)))

LIBRARYFLAGS = $(addprefix -l,$(LIBRARIES))

LIBRARYLOCATION += -L$(OBJDIR)\

# Default-Target
all: $(OUTPUTFILE)

# debug target
debug:
	@echo INCLUDEFLAGS: 
	@echo 

# Target: Hello
$(OUTPUTFILE): $(OBJECTS) | $(LIBRARYFILES)
	@echo ### BUILDING $(OUTPUTFILE)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(LIBRARYFLAGS) $(LIBRARYLOCATION) -o $(OUTPUTFILE)
	
# Automatic Target for alle Source-Files
$(OBJDIR)\\%.o: %.c | $(OBJDIR)
	@echo ### MAKING $(notdir $<)
	$(CC) $(INCLUDEFLAGS) $(CFLAGS) -c $< -o $@
	
$(OBJDIR):
	mkdir $(OBJDIR)
	
$(OBJDIR)\\%.a:
	echo ### BUILDING LIBRARY $(notdir $@)
	$(MAKE) -f $(subst .a,_lib,$(subst lib,,$(notdir $@)))\makefile_$(subst .a,_lib,$(subst lib,,$(notdir $@))).mak
	echo ### BUILDING LIBRARY DONE
	
	
.PHONY: clean
clean:
	@echo ### CLEANING ...
	rmdir /q /s $(OBJDIR)