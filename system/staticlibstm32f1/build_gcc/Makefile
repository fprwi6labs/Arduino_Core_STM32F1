#
#  Copyright (c) 2011 Arduino.  All right reserved.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#

# Makefile for compiling libchip

SUBMAKE_OPTIONS=--no-builtin-rules --no-builtin-variables --no-print-directory

#-------------------------------------------------------------------------------
# Rules
#-------------------------------------------------------------------------------

all : NUCLEO_F103RB STM32F103C STM32F100RB

.PHONY: all
NUCLEO_F103RB:
	@echo ------------------------------------------------------------------------
	@echo --- Making $@
	@echo ---
	@$(MAKE) CHIP=STM32F103xB CHIP_STARTUP_FILE=startup_stm32f103xb.s LIBNAME=libstm32f1 CHIP_NAME=nucleo_f103rb OUTPUT_BIN=../../../variants/STM32F103RB_Nucleo $(SUBMAKE_OPTIONS) -f stm32f103c.mk
	@echo ------------------------------------------------------------------------

STM32F103C:
	@echo ------------------------------------------------------------------------
	@echo --- Making $@
	@echo ---
	@$(MAKE) CHIP=STM32F103xB CHIP_STARTUP_FILE=startup_stm32f103xb.s LIBNAME=libstm32f103c CHIP_NAME=stm32f103c OUTPUT_BIN=../../../variants/STM32F103C_BluePill $(SUBMAKE_OPTIONS) -f stm32f103c.mk
	@echo ------------------------------------------------------------------------

STM32F100RB:
	@echo ------------------------------------------------------------------------
	@echo --- Making $@
	@echo ---
	@$(MAKE) CHIP=STM32F100xB CHIP_STARTUP_FILE=startup_stm32f100xb.s LIBNAME=libstm32f1 CHIP_NAME=stm32f100rb OUTPUT_BIN=../../../variants/STM32F100RB_STM32VLDISCOVERY $(SUBMAKE_OPTIONS) -f stm32f103c.mk
	@echo ------------------------------------------------------------------------

.PHONY: clean
clean:
	@echo ------------------------------------------------------------------------
	@echo --- Cleaning lib release and debug
	@$(MAKE) CHIP=__STM32F103C__ $(SUBMAKE_OPTIONS) -f stm32f103c.mk $@
	@$(MAKE) CHIP=STM32F103xB CHIP_STARTUP_FILE=startup_stm32f103xb.s LIBNAME=libstm32f103c CHIP_NAME=stm32f103c OUTPUT_BIN=../../../variants/STM32F103C_BluePill $(SUBMAKE_OPTIONS) -f stm32f103c.mk $@
	@$(MAKE) CHIP=STM32F103xB CHIP_STARTUP_FILE=startup_stm32f103xb.s LIBNAME=libstm32f1 CHIP_NAME=nucleo_f103rb OUTPUT_BIN=../../../variants/STM32F103RB_Nucleo $(SUBMAKE_OPTIONS) -f stm32f103c.mk $@
	@$(MAKE) CHIP=STM32F100xB CHIP_STARTUP_FILE=startup_stm32f100xb.s LIBNAME=libstm32f1 CHIP_NAME=stm32f100rb OUTPUT_BIN=../../../variants/STM32F100RB_STM32VLDISCOVERY $(SUBMAKE_OPTIONS) -f stm32f103c.mk $@
	@echo ------------------------------------------------------------------------
