################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SevenSegment/SevenSegment.c 

OBJS += \
./HAL/SevenSegment/SevenSegment.o 

C_DEPS += \
./HAL/SevenSegment/SevenSegment.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SevenSegment/SevenSegment.o: ../HAL/SevenSegment/SevenSegment.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/SevenSegment/SevenSegment.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

