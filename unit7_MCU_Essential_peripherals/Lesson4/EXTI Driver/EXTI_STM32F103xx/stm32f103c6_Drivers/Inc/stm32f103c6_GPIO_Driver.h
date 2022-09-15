/*
 * stm32f103c6_GPIO_Driver.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Ahmed Nasser
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_


//-----------------------------
//Includes
//-----------------------------

#include "stm32f103c6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct{

	uint16_t GPIO_PinNumber;	// Specifies the GPIO pins to be configured
								// This Parameter Must be a Value of @ref GPIO_PINS_define

	uint8_t  GPIO_Mode;			// Specifies the operating Mode for selected pins
								// This Parameter Must be a Value of @ref GPIO_MODE_define


	uint8_t  GPIO_OUTPUT_Speed;		// Specifies the Speed of selected pins
								// This Parameter Must be a Value of @ref GPIO_SPEED_define


}GPIO_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINS_define

#define GPIO_PIN_0				((uint16_t) (1<<0))   /* PIN0 Selected*/
#define GPIO_PIN_1				((uint16_t) (1<<1))   /* PIN1 Selected*/
#define GPIO_PIN_2				((uint16_t) (1<<2))   /* PIN2 Selected*/
#define GPIO_PIN_3				((uint16_t) (1<<3))   /* PIN3 Selected*/
#define GPIO_PIN_4				((uint16_t) (1<<4))   /* PIN4 Selected*/
#define GPIO_PIN_5				((uint16_t) (1<<5))   /* PIN5 Selected*/
#define GPIO_PIN_6				((uint16_t) (1<<6))   /* PIN6 Selected*/
#define GPIO_PIN_7				((uint16_t) (1<<7))   /* PIN7 Selected*/
#define GPIO_PIN_8				((uint16_t) (1<<8))   /* PIN8 Selected*/
#define GPIO_PIN_9				((uint16_t) (1<<9))   /* PIN9 Selected*/
#define GPIO_PIN_10				((uint16_t) (1<<10))  /* PIN10 Selected*/
#define GPIO_PIN_11				((uint16_t) (1<<11))  /* PIN11 Selected*/
#define GPIO_PIN_12				((uint16_t) (1<<12))  /* PIN12 Selected*/
#define GPIO_PIN_13				((uint16_t) (1<<13))  /* PIN13 Selected*/
#define GPIO_PIN_14				((uint16_t) (1<<14))  /* PIN14 Selected*/
#define GPIO_PIN_15				((uint16_t) (1<<15))  /* PIN15 Selected*/
#define GPIO_PIN_All			((uint16_t) 0xFFFF)   /* All pins Selected*/


#define GPIO_PIN_MASK			(0x0000FFFF)		  /* PIN MASK for assert test*/

//@ref GPIO_MODE_define
/*
 *
 	 0: Analog mode
 	 1: Floating input (reset state)
	 2: Input with pull-up
	 3: Input with pull-down
	 4: General purpose output push-pull
	 5: General purpose output Open-drain
	 6: Alternate function output Push-pull
	 7: Alternate function output Open-drain
	 8: Alternate function Input
 *
 */

#define GPIO_MODE_INPUT_Analog			(0x0u)	/*INPUT : Analog mode*/
#define GPIO_MODE_INPUT_FLO				(0x1u)	/*INPUT : Floating (reset state)*/
#define GPIO_MODE_INPUT_PU				(0x2u)	/*INPUT : pull-up*/
#define GPIO_MODE_INPUT_PD				(0x3u)	/*INPUT : pull-down*/

#define GPIO_MODE_OUTPUT_PP				(0x4u)	/*OUTPUT : push-pull*/
#define GPIO_MODE_OUTPUT_OD				(0x5u)	/*OUTPUT : Open-drain*/

#define GPIO_MODE_OUTPUT_AF_PP			(0x6u)	/*AF_OUTPUT : Alternate function output Push-pull*/
#define GPIO_MODE_OUTPUT_AF_OD			(0x7u)	/*AF_OUTPUT : Alternate function output Open-drain*/
#define GPIO_MODE_INPUT_AF				(0x8u)	/*AF_INPUT : Alternate function Input*/



// @ref GPIO_SPEED_define
/*
 *
	1: Output mode, max speed 10 MHz.
	2: Output mode, max speed 2 MHz.
	3: Output mode, max speed 50 MHz.
 *
 * */

#define GPIO_SPEED_10M			0x1u	/*Output mode, max speed 10 MHz.*/
#define GPIO_SPEED_2M			0x2u	/*Output mode, max speed 2 MHz.*/
#define GPIO_SPEED_50M			0x3u	/*Output mode, max speed 50 MHz.*/






/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

// Initialization Function

status_t MCAL_GPIO_Init(GPIO_t *GPIOx , GPIO_PinConfig_t* PinConfig);
status_t MCAL_GPIO_DeInit(GPIO_t *GPIOx);

// Read Functions
uint8_t  MCAL_GPIO_ReadPin(GPIO_t *GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx);


// Write Functions
status_t  MCAL_GPIO_WritePin(GPIO_t *GPIOx , uint16_t PinNumber , uint8_t Value);
status_t  MCAL_GPIO_WritePort(GPIO_t *GPIOx , uint16_t Value);

status_t  MCAL_GPIO_TogglePin(GPIO_t *GPIOx , uint16_t PinNumber );

// Lock Function

status_t  MCAL_GPIO_LockPin(GPIO_t *GPIOx , uint16_t PinNumber );


#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
