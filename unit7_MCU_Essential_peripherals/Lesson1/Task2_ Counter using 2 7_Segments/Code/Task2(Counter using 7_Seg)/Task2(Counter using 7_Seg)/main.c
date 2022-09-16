/*
 * Task2(Counter using 7_Seg).c
 *
 * Created: 9/9/2022 5:11:55 PM
 * Author : Ahmed Nasser
 */ 

#include<stdio.h>
#include <avr/io.h>
#include "LIB/Delay.h"

uint8_t		SevenSegment[] ={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x58,0x00,0x10};

int main(void)
{
    /* Replace with your application code */
	DDRA |= (0xFF);
	DDRB |= (0xFF);
	DDRC |= (0xFF);
    while (1) 
    {
		
		
		PORTB = SevenSegment[0];
		PORTA = SevenSegment[0];
		
		// Counter 0:99 using 8pins + 2*BCD to 7-segment
		for(uint8_t i=0;i<10;i++){
			PORTC &= ~(0x0F);
			PORTC |= i;
			Delay_ms(1000);
			for (uint8_t j=0;j<10;j++)
			{
				PORTC &= ~(0xF0);
				PORTC |= (uint8_t)(j<<4);
				Delay_ms(1000);

			}
			PORTC &= ~(0xF0);
			
		}
		
		PORTC &= ~(0xFF);
		
		// Counter 0:99 using 16pins 
		for(uint8_t i=0;i<10;i++){
			PORTA = SevenSegment[i];
			Delay_ms(1000);
			for (uint8_t j=0;j<10;j++)
			{
				PORTB = SevenSegment[j];
				Delay_ms(1000);

			}
			PORTB = SevenSegment[0];
			
		}
		
    }
}

