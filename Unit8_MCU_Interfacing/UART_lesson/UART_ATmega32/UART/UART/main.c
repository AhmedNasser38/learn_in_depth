/*
* UART.c
*
* Created: 2/25/2022 1:08:38 AM
* Author : Ahmed Nasser
*/

#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/USART/USART.h"

#define F_CPU   8000000UL

int main(void)
{
	uint8 ch;
	uint8 str[100] = {0};
	USART_Init();
	LCD_Init();
	/* Replace with your application code */
	while (1)
	{
		// Test Send 
		USART_Send_char('a');
		USART_Send_char('h');
		USART_Send_char('m');
		USART_Send_char('e');
		USART_Send_char('d');
		USART_Send_char('\r');
		
		USART_Send_str("Nasser");
		
		// Test Receive
		
		ch = USART_Recieve_char();
		LCD_Clear_Screen();
		LCD_Send_char(ch);
		
		USART_Recieve_str(str);
		
		LCD_GotoXY(0,LCD_SECOND_LINE);
		LCD_Send_str(str);

		
	}
}

