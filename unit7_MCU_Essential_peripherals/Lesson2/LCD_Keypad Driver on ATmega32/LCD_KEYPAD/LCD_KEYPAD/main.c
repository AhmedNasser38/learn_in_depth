/*
 * LCD_KEYPAD.c
 *
 * Created: 11/3/2021 10:44:36 AM
 * Author : Ahmed Nasser
 */ 

#include "LCD_Driver/LCD.h"
#include "KEYPAD_Driver/KEYPAD.h"

int main(void)
{
	char temp;
	LCD_Init();
	Keypad_Init();
    /* Replace with your application code */
    while (1) 
    {
		LCD_Send_str("HEllo IN Embedded-System Diploma By : Eng.Ahmed Nasser");
		_delay_ms(1000);
		LCD_Clear_Screen();
		LCD_Send_str("Numbers Example : ");
		LCD_Send_char(' ');
		LCD_Send_RealNum(30.127);
	    LCD_Send_str(" + ");
		LCD_Send_Num(120);_delay_ms(100);
		LCD_Send_char('A');_delay_ms(100);
		LCD_Send_char('H');_delay_ms(100);
		LCD_Send_char('M');_delay_ms(100);
		LCD_Send_char('E');_delay_ms(100);
		LCD_Send_char('D');_delay_ms(100);
		LCD_Send_char('N');_delay_ms(100);
		LCD_Send_char('A');_delay_ms(100);
		LCD_Send_char('S');_delay_ms(100);
		LCD_Send_char('S');_delay_ms(100);
		LCD_Send_char('E');_delay_ms(100);
		LCD_Send_char('R');
		_delay_ms(1000);
		LCD_Clear_Screen();
		_delay_ms(1000);
		LCD_Send_str("Test KeyPad  begin");
		_delay_ms(1000);
		LCD_Clear_Screen();
		
		// Keypad
		//while(Keypad_Getkey() != 'O'){
// 			temp = Keypad_Getkey();
// 			LCD_Send_char(temp);
// 			_delay_ms(100);
// 		
		
    }
	return 0;
}

