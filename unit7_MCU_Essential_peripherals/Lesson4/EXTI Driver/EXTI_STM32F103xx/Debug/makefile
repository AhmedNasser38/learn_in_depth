################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32f103c6_Drivers/GPIO_Driver/subdir.mk
-include stm32f103c6_Drivers/EXTI/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KeyPad/subdir.mk
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
EXTI_STM32F103xx.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
EXTI_STM32F103xx.list \

OBJCOPY_BIN += \
EXTI_STM32F103xx.bin \


# All Target
all: EXTI_STM32F103xx.elf secondary-outputs

# Tool invocations
EXTI_STM32F103xx.elf: $(OBJS) $(USER_OBJS) F:\work_space\learn_in_depth\unit7_MCU_Essential_peripherals\Lesson4\EXTI_STM32F103xx\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "EXTI_STM32F103xx.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\work_space\learn_in_depth\unit7_MCU_Essential_peripherals\Lesson4\EXTI_STM32F103xx\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="EXTI_STM32F103xx.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

EXTI_STM32F103xx.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "EXTI_STM32F103xx.list"
	@echo 'Finished building: $@'
	@echo ' '

EXTI_STM32F103xx.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "EXTI_STM32F103xx.bin"
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
