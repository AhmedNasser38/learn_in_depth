################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32f103c6_Drivers/stm32f103c6_USART/subdir.mk
-include stm32f103c6_Drivers/stm32f103c6_RCC/subdir.mk
-include stm32f103c6_Drivers/GPIO_Driver/subdir.mk
-include stm32f103c6_Drivers/EXTI/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
USART_Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
USART_Driver.list \

OBJCOPY_BIN += \
USART_Driver.bin \


# All Target
all: USART_Driver.elf secondary-outputs

# Tool invocations
USART_Driver.elf: $(OBJS) $(USER_OBJS) F:\STM_Work\USART_Driver\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "USART_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\STM_Work\USART_Driver\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="USART_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

USART_Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "USART_Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

USART_Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "USART_Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
