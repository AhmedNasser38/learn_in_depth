################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_Drivers/GPIO_Driver/stm32f103c6_GPIO_Driver.c 

OBJS += \
./stm32f103c6_Drivers/GPIO_Driver/stm32f103c6_GPIO_Driver.o 

C_DEPS += \
./stm32f103c6_Drivers/GPIO_Driver/stm32f103c6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_Drivers/GPIO_Driver/stm32f103c6_GPIO_Driver.o: ../stm32f103c6_Drivers/GPIO_Driver/stm32f103c6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/GPIO_Driver/stm32f103c6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

