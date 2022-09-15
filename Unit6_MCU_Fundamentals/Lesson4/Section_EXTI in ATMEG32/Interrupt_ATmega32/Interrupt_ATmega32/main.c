/*
 * Interrupt_ATmega32.c
 *
 * Created: 7/29/2022 11:42:27 PM
 * Author : Ahmed Nasser
 */ 

#include "HAL/LCD/LCD.h"
#include "MCAL/EXT_INT/EXT_INT.h"


void LED0 ();
void LED1 ();
void LED2 ();

int main(void)
{
	EXT_INT_INIT();
	
	DIO_Set_DDR_PIN(PORTD_REG,PIN5,OUTPUT);
	DIO_Set_DDR_PIN(PORTD_REG,PIN6,OUTPUT);
	DIO_Set_DDR_PIN(PORTD_REG,PIN7,OUTPUT);
    /* Replace with your application code */
    while (1) 
    {
		DIO_Set_PIN(PORTD_REG,PIN5,LOW);
		DIO_Set_PIN(PORTD_REG,PIN6,LOW);
		DIO_Set_PIN(PORTD_REG,PIN7,LOW);
		
		INT0_SetCallBack(&LED0);
		INT1_SetCallBack(&LED1);
		INT2_SetCallBack(&LED2);
	
    }
}

void LED0 (){
	SetBit(PORTD,PIN5);
	Delay_ms(1000);
	Delay_ms(1000);
	}
void LED1 (){
		SetBit(PORTD,PIN6);
		Delay_ms(1000);
		Delay_ms(1000);
}
void LED2 (){
		SetBit(PORTD,PIN7);
		Delay_ms(1000);
		Delay_ms(1000);
}