/*
 * SevenSegment.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Ahmed Nasser
 */


#include "SevenSegment.h"

uint16_t SevenSegment_Pins[7] = {SevenSegment_PIN_0,SevenSegment_PIN_1,SevenSegment_PIN_2,SevenSegment_PIN_3,SevenSegment_PIN_4,SevenSegment_PIN_5,SevenSegment_PIN_6};

uint8_t SevenSegment_Value[10] = {SevenSegment_0,SevenSegment_1,SevenSegment_2,SevenSegment_3,SevenSegment_4,SevenSegment_5,SevenSegment_6,SevenSegment_7,SevenSegment_8,SevenSegment_9};

GPIO_PinConfig_t PinConfig;
void HAL_SevenSegment_Init(void){
	uint8_t i;
	for(i=0;i<7;i++){
		PinConfig.GPIO_PinNumber = SevenSegment_Pins[i];
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		PinConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(SevenSegment_PORT, &PinConfig);
	}

}

void HAL_SevenSegment_Display(uint8_t u8Value){

	#if SevenSegment_Type == Common_Anode
		MCAL_GPIO_WritePort(SevenSegment_PORT, u8Value << 9);

	#elif SevenSegment_Type == Common_Cathode
	// comman Cathod
	MCAL_GPIO_WritePort(SevenSegment_PORT, (~(u8Value) << 9));

	#endif

}
