/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "../stm32f103c6_Drivers/Inc/stm32f103c6.h"
#include "../stm32f103c6_Drivers/Inc/stm32f103c6_GPIO_Driver.h"
#include "../HAL/KeyPad/KEYPAD.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/SevenSegment/SevenSegment.h"


void Clock_init(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}


int main(void)
{
	uint8_t ch;
	Clock_init();
	HAL_LCD_Init();
	HAL_Keypad_Init();
	HAL_SevenSegment_Init();
    /* Loop forever */
	HAL_LCD_Send_str("HEY Lcd");
	while(1){
		HAL_SevenSegment_Display(SevenSegment_0);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_1);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_2);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_3);
		Delay_ms(1000);

		HAL_SevenSegment_Display(SevenSegment_4);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_5);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_6);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_7);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_8);
		Delay_ms(1000);
		HAL_SevenSegment_Display(SevenSegment_9);
				Delay_ms(1000);
		//HAL_LCD_Clear_Screen();

	}
}