################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32f103c6_Drivers/GPIO_Driver/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include HAL/SevenSegment/subdir.mk
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
Integreate\ KeyPad_LCD.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Integreate\ KeyPad_LCD.list \

OBJCOPY_BIN += \
Integreate\ KeyPad_LCD.bin \


# All Target
all: Integreate\ KeyPad_LCD.elf secondary-outputs

# Tool invocations
Integreate\ KeyPad_LCD.elf: $(OBJS) $(USER_OBJS) F:\work_space\learn_in_depth\unit7_MCU_Essential_peripherals\Section3\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Integreate KeyPad_LCD.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\work_space\learn_in_depth\unit7_MCU_Essential_peripherals\Section3\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Integreate KeyPad_LCD.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Integreate\ KeyPad_LCD.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Integreate KeyPad_LCD.list"
	@echo 'Finished building: $@'
	@echo ' '

Integreate\ KeyPad_LCD.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Integreate KeyPad_LCD.bin"
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
