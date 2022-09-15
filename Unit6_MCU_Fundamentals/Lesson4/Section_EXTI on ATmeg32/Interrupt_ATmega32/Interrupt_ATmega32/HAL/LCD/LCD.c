/*
 * LCD.c
 *
 *  Created on: Nov 21, 2021
 *      Author: Ahmed Nasser
 */


#include "LCD.h"

void LCD_Kick(){
	LCD_CTRL_PORT &= ~(1<<EN);
 	asm volatile ("nop");
 	asm volatile ("nop");
	Delay_ms(50);
	LCD_CTRL_PORT |= (1<<EN);
}

void LCD_Isbusy(){

	//port>>input +> RW>>on RS>>off +> check d7 value

	LCD_PORT_DDR &= ~(0xFF << Data_shift);
	LCD_CTRL_PORT |= (1<<RW);
	LCD_CTRL_PORT &= ~(1<<RS);

	LCD_Kick();
	if((LCD_PORT<< PIN7) == 0)
	{
	LCD_PORT_DDR |= (0xFF << Data_shift);
	LCD_CTRL_PORT &= ~(1<<RW);
	}else{
		LCD_Isbusy();
	}
}

void LCD_Init(){
	Delay_ms(20);
	LCD_CTRL_DDR |= (1<<EN | 1<<RW | 1<<RS );
	LCD_CTRL_PORT &= ~(1<<EN | 1<<RW | 1<<RS );

	LCD_PORT_DDR |= (0xFF << Data_shift) ; // need to take alook fo 4bitmode
	Delay_ms(15);

	LCD_Clear_Screen();

	#ifdef EIGHT_BIT_MODE
	LCD_CMD(LCD_FUNCTION_8BIT_2LINES); // need more generalized
	#endif
	#ifdef FOUR_BIT_MODE

	LCD_CMD(LCD_RETURN_HOME);
	LCD_CMD(LCD_FUNCTION_4BIT_2LINES); // need more generalized
	#endif
	LCD_CMD(LCD_ENTRY_MODE);
	LCD_CMD(LCD_BEGIN_AT_FIRST_ROW);
	LCD_CMD(LCD_DISP_ON_CURSOR_BLINK);

}


void LCD_CMD(unsigned char cmd){
	#ifdef EIGHT_BIT_MODE
		LCD_Isbusy();

		LCD_PORT = cmd;
		LCD_CTRL_PORT &= ~(1<<RW | 1<<RS);
		LCD_Kick();
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_Isbusy();


	LCD_PORT = (LCD_PORT & 0x0F) |(cmd & 0xF0);
	LCD_CTRL_PORT &= ~(1<<RW | 1<<RS);
	LCD_Kick();

	LCD_PORT = (LCD_PORT & 0x0F) |(cmd << Data_shift);
	LCD_CTRL_PORT &= ~(1<<RW | 1<<RS);
	LCD_Kick();
	#endif

}

void LCD_Send_char(volatile unsigned char ch){

	#ifdef EIGHT_BIT_MODE
		LCD_Isbusy();
		LCD_CTRL_PORT |= (1<<RS);
		LCD_PORT = ((ch) << Data_shift );
		LCD_CTRL_PORT |= (1<<RS);
		LCD_CTRL_PORT &= ~(1<<RW );
		LCD_Kick();
	#endif
	#ifdef FOUR_BIT_MODE
	//	LCD_Isbusy();

		LCD_PORT = (LCD_PORT & 0x0F) |(ch & 0xF0);
		LCD_CTRL_PORT |= (1<<RS);
		LCD_CTRL_PORT &= ~(1<<RW);
		LCD_Kick();

		LCD_PORT = (LCD_PORT & 0x0F) |(ch << Data_shift);
		LCD_CTRL_PORT |= (1<<RS);
		LCD_CTRL_PORT &= ~(1<<RW );
		LCD_Kick();
	#endif

}
void LCD_Send_str(char* str){
	int count=0;
	while (*str > 0)
	{

		LCD_Send_char(*str++);
		count++;
		if(count == 16)
		{
			LCD_GotoXY(0,LCD_SECOND_LINE);
		}
		else if (count >= 32 )
		{
			LCD_Clear_Screen();
			LCD_GotoXY(0,LCD_FIRST_LINE);
			count = 0;
		}
	}

}
void LCD_Clear_Screen(void){
	LCD_CMD(LCD_CLEAR_SCREEN);
}
void LCD_GotoXY(unsigned char pos , unsigned char line){
	if (line == LCD_FIRST_LINE)
	{
		if(pos < 16 && pos >=0)
			LCD_CMD(LCD_BEGIN_AT_FIRST_ROW + pos);
	}
	else if (line == LCD_SECOND_LINE)
	{
		if(pos < 16 && pos >=0)
			LCD_CMD(LCD_BEGIN_AT_SECOND_ROW + pos);
	}
}
void LCD_Send_Num(int num){
	char str[10];
	sprintf(str,"%d",num);
	LCD_Send_str(str);
}
void LCD_Send_RealNum(double num){
	char str[16];

	char *Sign = (num < 0) ? "-" : "";

	float Val = (num < 0) ? -num : num ;
	int Int = (int)Val;
	float Fraction = Val - Int ;
	Fraction *= 10000;

	sprintf(str , "%s%d.%04d" , Sign , Int , (int)Fraction);
	LCD_Send_str(str);
}
