/*
 * KEYPAD.h
 *
 * Created: 11/3/2021 8:29:23 PM
 *  Author: Ahmed Nasser
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

//-----------------------------
//Includes
//-----------------------------
#include "../stm32f103c6_Drivers/Inc/stm32f103c6.h"
#include "../stm32f103c6_Drivers/Inc/stm32f103c6_GPIO_Driver.h"





//-----------------------------
//	Macros
//-----------------------------


//----------------------------------------------------------------------------------------------//
//	Macros : Connected PINs to KeyPad @ref GPIO_PINS_define in (stm32f103c6_GPIO_Driver.h)file--//
//----------------------------------------------------------------------------------------------//

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

//----------------------------------------------------------------------------------------------//
//		Macros : Connected PORT to KeyPad It Must be GPIOx where x is [A:D]					  --//
//----------------------------------------------------------------------------------------------//
#define KEYPAD_PORT GPIOB


void HAL_Keypad_Init(void);
char HAL_Keypad_Getkey(void);


#endif /* KEYPAD_H_ */
