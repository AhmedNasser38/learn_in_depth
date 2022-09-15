/*
 * toggle_8Leds_onebyone.c
 *
 * Created: 9/9/2022 4:04:36 AM
 * Author : Ahmed Nasser
 */ 
#include "LIB/STD_TYPES.h"
#include "LIB/BitMath.h"
#include "LIB/Delay.h"

#include "MCAL/Memory_Map.h"


// Button on PORTB >> P0


int main(void)
{
    /* Replace with your application code */
	int8 i;
	// Set pin0 in DDRB as INPUT
	ClearBit(DDRB,PIN0);
	// Set all pins in PORTA as OUTPUT
	SetBit(DDRA,PIN0);
	SetBit(DDRA,PIN1);
	SetBit(DDRA,PIN2);
	SetBit(DDRA,PIN3);
	SetBit(DDRA,PIN4);
	SetBit(DDRA,PIN5);
	SetBit(DDRA,PIN6);
	SetBit(DDRA,PIN7);
	// or //PORTA=0xFF;
	// init pin0 in portb
	//ClearBit(PORTB,PIN0);
    while (1) 
    {
		if(GetBit(PINB,PIN0) == 1){
			// ON LED1 
			SetBit(PORTA,PIN0);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED2
			SetBit(PORTA,PIN1);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED3
			SetBit(PORTA,PIN2);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED4
			SetBit(PORTA,PIN3);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED5
			SetBit(PORTA,PIN4);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED6
			SetBit(PORTA,PIN5);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED7
			SetBit(PORTA,PIN6);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			// ON LED8
			SetBit(PORTA,PIN7);
			Delay_ms(900);
			// Wait until Push again
			while(GetBit(PINB,PIN0) == 0);
			
			for ( i=7;i>=0;i--)
			{
				Delay_ms(900);
				ClearBit(PORTA,i);
			}
			Delay_ms(900);
		}
	
		
		
    }
}

