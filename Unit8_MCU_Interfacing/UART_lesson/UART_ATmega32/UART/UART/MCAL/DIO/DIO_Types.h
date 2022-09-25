/*
 * DIO_Types.h
 *
 *  Created on: Nov 11, 2021
 *      Author: Ahmed Nasser
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_


#define	porta		0
#define	portb		1
#define	portc		2
#define	portd		3

#define	PA			0
#define	PB			1
#define	PC			2
#define	PD			3

#define	A			0
#define	B			1
#define	C			2
#define	D			3

#define	a 			0
#define	b 			1
#define	c 			2
#define	d 			3

typedef enum {
	INPUT,  // 0
	OUTPUT  // 1
} DIO_Direction;

typedef enum {
	LOW,  // 0
	HIGH  // 1
} DIO_Value;

typedef enum {
	PORTA_REG, 
	PORTB_REG, 
	PORTC_REG, 
	PORTD_REG
} DIO_PORT_ID;

typedef enum {
	PIN0, 
	PIN1, 
	PIN2, 
	PIN3, 
	PIN4, 
	PIN5, 
	PIN6, 
	PIN7
} DIO_PIN_ID;

typedef enum {
	PA0, 
	PA1, 
	PA2, 
	PA3, 
	PA4, 
	PA5, 
	PA6, 
	PA7
} PORTA_PIN_ID;

typedef enum {
	PB0, 
	PB1, 
	PB2, 
	PB3, 
	PB4, 
	PB5, 
	PB6, 
	PB7
} PORTB_PIN_ID;

typedef enum {
	PC0, 
	PC1, 
	PC2, 
	PC3, 
	PC4, 
	PC5, 
	PC6, 
	PC7
} PORTC_PIN_ID;

typedef enum {
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5, 
	PD6, 
	PD7
} PORTD_PIN_ID;

// Alternative functions pin
#define XCK   	 	PB0
#define T0   	 	PB0
#define T1   	 	PB1
#define INT2		PB2
#define AIN0		PB2
#define AIN1		PB3
#define OC0			PB3
#define SS	     	PB4
#define MOSI     	PB5
#define MISO   	 	PB6
#define SCK     	PB7

#define RXD   	 	PD0
#define TXD  	  	PD1
#define INT0    	PD2
#define INT1     	PD3
#define OC1B   	 	PD4
#define OC1A   	 	PD5
#define ICP1     	PD6
#define OC2	    	PD7

#define SCL	    	PC0
#define SDA	    	PC1
#define TCK	    	PC2
#define TMS     	PC3
#define TDO   	 	PC4
#define TDI   	 	PC5
#define TOSC1    	PC6
#define TOSC2    	PC7

#define ADC0     	PA0
#define ADC1     	PA1
#define ADC2     	PA2
#define ADC3     	PA3
#define ADC4     	PA4
#define ADC5     	PA5
#define ADC6     	PA6
#define ADC7     	PA7

#endif /* MCAL_DIO_DIO_TYPES_H_ */
