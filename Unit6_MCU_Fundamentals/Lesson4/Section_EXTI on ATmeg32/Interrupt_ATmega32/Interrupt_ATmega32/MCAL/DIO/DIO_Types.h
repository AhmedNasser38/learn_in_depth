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
	PIN0_ID, 
	PIN1_ID, 
	PIN2_ID, 
	PIN3_ID, 
	PIN4_ID, 
	PIN5_ID, 
	PIN6_ID, 
	PIN7_ID
} DIO_PIN_ID;
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
typedef enum {
	PA0_ID, 
	PA1_ID, 
	PA2_ID, 
	PA3_ID, 
	PA4_ID, 
	PA5_ID, 
	PA6_ID, 
	PA7_ID
} PORTA_PIN_ID;
#define PA0		0
#define PA1		1
#define PA2		2
#define PA3		3
#define PA4		4
#define PA5		5
#define PA6		6
#define PA7		7
typedef enum {
	PB0_ID, 
	PB1_ID, 
	PB2_ID, 
	PB3_ID, 
	PB4_ID, 
	PB5_ID, 
	PB6_ID, 
	PB7_ID
} PORTB_PIN_ID;

#define PB0		0
#define PB1		1
#define PB2		2
#define PB3		3
#define PB4		4
#define PB5		5
#define PB6		6
#define PB7		7

typedef enum {
	PC0_ID,
	PC1_ID,
	PC2_ID,
	PC3_ID,
	PC4_ID,
	PC5_ID,
	PC6_ID,
	PC7_ID
} PORTC_PIN_ID;
#define PC0		0
#define PC1		1
#define PC2		2
#define PC3		3
#define PC4		4
#define PC5		5
#define PC6		6
#define PC7		7
typedef enum {
	PD0_ID=0,
	PD1_ID,
	PD2_ID,
	PD3_ID,
	PD4_ID,
	PD5_ID, 
	PD6_ID, 
	PD7_ID
}PORTD_PIN_ID;

#define PD0		0
#define PD1		1
#define PD2		2
#define PD3		3
#define PD4		4
#define PD5		5
#define PD6		6
#define PD7		7

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
