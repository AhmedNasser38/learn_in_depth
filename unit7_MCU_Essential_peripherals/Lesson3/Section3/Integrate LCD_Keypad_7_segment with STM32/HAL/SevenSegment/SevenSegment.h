/*
 * SevenSegment.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Ahmed Nasser
 */

#ifndef SEVENSEGMENT_SEVENSEGMENT_H_
#define SEVENSEGMENT_SEVENSEGMENT_H_

//-----------------------------
//Includes
//-----------------------------
#include "../stm32f103c6_Drivers/Inc/stm32f103c6.h"
#include "../stm32f103c6_Drivers/Inc/stm32f103c6_GPIO_Driver.h"



//-----------------------------
//		Configuration Section
//-----------------------------

#define Common_Cathode 		'A'
#define Common_Anode		'C'


#define SevenSegment_Type 			Common_Anode//Common_Cathode

#define SevenSegment_PORT			GPIOB



#define SevenSegment_PIN_0			GPIO_PIN_9
#define SevenSegment_PIN_1			GPIO_PIN_10
#define SevenSegment_PIN_2			GPIO_PIN_11
#define SevenSegment_PIN_3			GPIO_PIN_12
#define SevenSegment_PIN_4			GPIO_PIN_13
#define SevenSegment_PIN_5			GPIO_PIN_14
#define SevenSegment_PIN_6			GPIO_PIN_15





//-----------------------------
//		7-Segment Macros
//-----------------------------
#define SevenSegment_0			0x01
#define SevenSegment_1			0x79
#define SevenSegment_2			0x24
#define SevenSegment_3			0x30
#define SevenSegment_4			0x58
#define SevenSegment_5			0x12
#define SevenSegment_6			0x02
#define SevenSegment_7			0x19
#define SevenSegment_8			0x00
#define SevenSegment_9			0x10


//-----------------------------
//		7-Segment APIs
//-----------------------------
void HAL_SevenSegment_Init(void);

void HAL_SevenSegment_Display(uint8_t u8Value);
#endif /* SEVENSEGMENT_SEVENSEGMENT_H_ */
