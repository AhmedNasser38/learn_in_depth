/*
 * KEYPAD.h
 *
 * Created: 11/3/2021 8:29:23 PM
 *  Author: Ahmed Nasser
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 8000000UL


#include<avr/io.h>
#include<util/delay.h>


#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTD
#define KEYPAD_PORT_DDR DDRD
#define keypadPIN PIND

void Keypad_Init(void);
char Keypad_Getkey(void);


#endif /* KEYPAD_H_ */