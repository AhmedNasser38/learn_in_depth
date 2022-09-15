/*
 * LCD_config.h
 *
 *  Created on: Nov 21, 2021
 *      Author: Ahmed Nasser
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/******************************************************************************
*									INCLUDES				                  *
*******************************************************************************/

#include"../../MCAL/DIO/DIO.h"
#include<stdio.h>
#include"../../LIB/Delay.h"


/******************************************************************************
*									Configuration				              *
*******************************************************************************/

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*
	LCD Control Register
	 	 enter the port you connect d0:d7
*/
#define LCD_PORT 		PORTD
#define LCD_PORT_DDR 	DDRD

/*
	LCD Control Register
	 	 enter the port you connect RS , RW , EN
*/
#define LCD_CTRL_PORT 	PORTB
#define LCD_CTRL_DDR 	DDRB

/*MODES
 	 OPTIONS:
 	   MODE 4  for 4-bit mode (pins(D4:D7) connected with LCD_PORT_PINS(4:7))
 	   MODE 8  for 8-bit mode (pins(D0:D7) connected with LCD_PORT_PINS(0:7))
 */
#define MODE 			 4

// PINS in MCU Which Connected to (RS , RW , EN) pins in LCD
#define RS				 PB1
#define RW				 PB2
#define EN				 PB3


#endif /* HAL_LCD_LCD_CONFIG_H_ */
