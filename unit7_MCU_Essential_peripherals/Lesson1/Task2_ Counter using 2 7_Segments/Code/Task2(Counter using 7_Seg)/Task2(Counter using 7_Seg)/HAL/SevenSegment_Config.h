/*
 * SevenSegment_Config.h
 *
 * Created: 9/9/2022 8:43:44 PM
 *  Author: Ahmed Nasser
 */ 


#ifndef SEVENSEGMENT_CONFIG_H_
#define SEVENSEGMENT_CONFIG_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BitMath.h"
#include "../LIB/Delay.h"

#include "../MCAL/Memory_Map.h"
/*Used Macros*/

#define Four_bits			4
#define Eight_bits			8



/*
	Mode define number of bits connected to 7-segment 
	
	four bit means that there's a BCD
	
	or eight bits and that means connected directly to MCU

	options :
		Four_bits
		Eight_bits
*/


#define SevenSegment_MODE	Four_bits

/*
	SevenSement_PORT   define which port connected to 7-segment
	
*/

#define SevenSegment_PORT		PORTC
#define SevenSegment_DDR		DDRC

#define SevenSegment_PIN0		0
#define SevenSegment_PIN1		1
#define SevenSegment_PIN2		2
#define SevenSegment_PIN3		3


#endif /* SEVENSEGMENT_CONFIG_H_ */