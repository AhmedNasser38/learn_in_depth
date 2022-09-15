/*
 * DIO.c
 *
 *  Created on: Nov 11, 2021
 *      Author: Ahmed Nasser
 */
#include "../Memory_Map/ATmega32.h"

#include "DIO.h"

void DIO_Set_PIN_PORT(DIO_PORT_ID PORT, DIO_Direction DDR) {
	if (DDR == OUTPUT) {
		switch (PORT) {
		case PORTA_REG:
			DDRA = 0xFF;
			break;
		case PORTB_REG:
			DDRB = 0xFF;
			break;
		case PORTC_REG:
			DDRC = 0xFF;
			break;
		case PORTD_REG:
			DDRD = 0xFF;
			break;
		}

	}
	if (DDR == INPUT) {
		switch (PORT) {
		case PORTA_REG:
			DDRA = 0x00;
			break;
		case PORTB_REG:
			DDRB = 0x00;
			break;
		case PORTC_REG:
			DDRC = 0x00;
			break;
		case PORTD_REG:
			DDRD = 0x00;
			break;
		}

	}

}
void DIO_Set_PORT(DIO_PORT_ID PORT, unsigned char value) {
	switch (PORT) {
	case PORTA_REG:
		PORTA = value;
		break;
	case PORTB_REG:
		PORTB = value;
		break;
	case PORTC_REG:
		PORTC = value;
		break;
	case PORTD_REG:
		PORTD = value;
		break;
	}
}

void DIO_Set_DDR_PIN(DIO_PORT_ID PORT, DIO_PIN_ID PIN, DIO_Direction DDR) {
	if (PORT <= PORTD_REG && PIN <= PIN7) {
		if (DDR == OUTPUT) {
			switch (PORT) {
			case PORTA_REG:
				SetBit(DDRA, PIN);
				break;
			case PORTB_REG:
				SetBit(DDRB, PIN);
				break;
			case PORTC_REG:
				SetBit(DDRC, PIN);
				break;
			case PORTD_REG:
				SetBit(DDRD, PIN);
				break;
			}

		}
		if (DDR == INPUT) {
			switch (PORT) {
			case PORTA_REG:
				ClearBit(DDRA, PIN);
				break;
			case PORTB_REG:
				ClearBit(DDRB, PIN);
				break;
			case PORTC_REG:
				ClearBit(DDRC, PIN);
				break;
			case PORTD_REG:
				ClearBit(DDRD, PIN);
				break;
			}

		}
	}
}
void DIO_Set_PIN(DIO_PORT_ID PORT, DIO_PIN_ID PIN, DIO_Value value) {
	if (PORT <= PORTD_REG && PIN <= PIN7) {
		if (value == HIGH) {
			switch (PORT) {
			case PORTA_REG:
				SetBit(PORTA, PIN);
				break;
			case PORTB_REG:
				SetBit(PORTB, PIN);
				break;
			case PORTC_REG:
				SetBit(PORTC, PIN);
				break;
			case PORTD_REG:
				SetBit(PORTD, PIN);
				break;
			}

		}
		if (value == LOW) {
			switch (PORT) {
			case PORTA_REG:
				ClearBit(PORTA, PIN);
				break;
			case PORTB_REG:
				ClearBit(PORTB, PIN);
				break;
			case PORTC_REG:
				ClearBit(PORTC, PIN);
				break;
			case PORTD_REG:
				ClearBit(PORTD, PIN);
				break;
			}

		}
	}
}

DIO_Value DIO_Get_PIN(DIO_PORT_ID PORT, DIO_PIN_ID PIN) {
	DIO_Value PIN_Value = 0;

	if (PORT <= PORTD_REG && PIN <= PIN7) {

		switch (PORT) {
		case PORTA_REG:
			PIN_Value = GetBit(PINA, PIN);
			break;
		case PORTB_REG:
			PIN_Value = GetBit(PINB, PIN);
			break;
		case PORTC_REG:
			PIN_Value = GetBit(PINC, PIN);
			break;
		case PORTD_REG:
			PIN_Value = GetBit(PIND, PIN);
			break;
		}

	}
	return PIN_Value;
}
