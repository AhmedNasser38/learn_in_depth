################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_Drivers/stm32f103c6_USART/stm32f103c6_USART.c 

OBJS += \
./stm32f103c6_Drivers/stm32f103c6_USART/stm32f103c6_USART.o 

C_DEPS += \
./stm32f103c6_Drivers/stm32f103c6_USART/stm32f103c6_USART.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_Drivers/stm32f103c6_USART/stm32f103c6_USART.o: ../stm32f103c6_Drivers/stm32f103c6_USART/stm32f103c6_USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_Drivers/stm32f103c6_USART/stm32f103c6_USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

