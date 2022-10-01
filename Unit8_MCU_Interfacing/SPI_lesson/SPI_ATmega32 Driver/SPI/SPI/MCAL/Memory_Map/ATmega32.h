/*
 * ATmega8.h
 *
 *  Created on: Nov 21, 2021
 *      Author: Ahmed Nasser
 */

#ifndef MCAL_MEMORY_MAP_ATMEGA32_H_
#define MCAL_MEMORY_MAP_ATMEGA32_H_

//GPIO
#define PIND  			*( (volatile unsigned char *) 0x30 )
#define DDRD  			*( (volatile unsigned char *) 0x31 )
#define PORTD			*( (volatile unsigned char *) 0x32 )

#define PINC  			*( (volatile unsigned char *) 0x33 )
#define DDRC  			*( (volatile unsigned char *) 0x34 )
#define PORTC 			*( (volatile unsigned char *) 0x35 )

#define PINB  			*( (volatile unsigned char *) 0x36 )
#define DDRB  			*( (volatile unsigned char *) 0x37 )
#define PORTB 			*( (volatile unsigned char *) 0x38 )

#define PINA  			*( (volatile unsigned char *) 0x39 )
#define DDRA  			*( (volatile unsigned char *) 0x3A )
#define PORTA 			*( (volatile unsigned char *) 0x3B )

//ADC
#define ADCL         	*( (volatile unsigned char *) 0x24 )
#define ADCH         	*( (volatile unsigned char *) 0x25 )
#define ADCSRA         	*( (volatile unsigned char *) 0x26 )
#define ADMUX         	*( (volatile unsigned char *) 0x27 )

//TIMERS
#define OCR2       	  	*( (volatile unsigned char *) 0x43 )
#define TCNT2       	*( (volatile unsigned char *) 0x44 )
#define TCCR2      	  	*( (volatile unsigned char *) 0x45 )
#define ICR1L         	*( (volatile unsigned char *) 0x46 )
#define ICR1H         	*( (volatile unsigned char *) 0x47 )
#define OCR1BL         	*( (volatile unsigned char *) 0x48 )
#define OCR1BH         	*( (volatile unsigned char *) 0x49 )
#define OCR1AL         	*( (volatile unsigned char *) 0x4A )
#define OCR1AH         	*( (volatile unsigned char *) 0x4B )
#define TCNT1L         	*( (volatile unsigned char *) 0x4C )
#define TCNT1H         	*( (volatile unsigned char *) 0x4D )
#define TCCR1B        	*( (volatile unsigned char *) 0x4E )
#define TCCR1A        	*( (volatile unsigned char *) 0x4F )
#define SFIOR        	*( (volatile unsigned char *) 0x50 )
#define OSCCAL        	*( (volatile unsigned char *) 0x51 )
#define TCNT0        	*( (volatile unsigned char *) 0x52 )
#define TCCR0         	*( (volatile unsigned char *) 0x53 )

// FLAGS
#define TIFR        	*( (volatile unsigned char *) 0x58 )
#define TIMSK        	*( (volatile unsigned char *) 0x59 )
#define GIFR        	*( (volatile unsigned char *) 0x5A )
#define GICR         	*( (volatile unsigned char *) 0x5B )

//SPI
#define SPCR         	*( (volatile unsigned char *) 0x2D )
#define SPSR        	*( (volatile unsigned char *) 0x2E )
#define SPDR        	*( (volatile unsigned char *) 0x2F )

//interrupt
#define SREG        	*( (volatile unsigned char *) 0x5F )
#endif /* MCAL_MEMORY_MAP_ATMEGA32_H_ */
