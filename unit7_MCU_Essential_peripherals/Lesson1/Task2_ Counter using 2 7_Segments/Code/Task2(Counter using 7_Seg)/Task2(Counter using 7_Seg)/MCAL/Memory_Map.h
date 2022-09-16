/*
 * Memory_Map.h
 *
 *  Created on: Oct 28, 2021
 *      Author: Ahmed Nasser
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "../LIB/STD_TYPES.h"

#define PIND  		*( (volatile uint8 *) 0x30 )
#define DDRD  		*( (volatile uint8 *) 0x31 )
#define PORTD		*( (volatile uint8 *) 0x32 )

#define PINC  		*( (volatile uint8 *) 0x33 )
#define DDRC  		*( (volatile uint8 *) 0x34 )
#define PORTC 		*( (volatile uint8 *) 0x35 )

#define PINB  		*( (volatile uint8 *) 0x36 )
#define DDRB  		*( (volatile uint8 *) 0x37 )
#define PORTB 		*( (volatile uint8 *) 0x38 )

#define PINA  		*( (volatile uint8 *) 0x39 )
#define DDRA  		*( (volatile uint8 *) 0x3A )
#define PORTA 		*( (volatile uint8 *) 0x3B )


// PINS

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7





#endif /* MEMORY_MAP_H_ */
