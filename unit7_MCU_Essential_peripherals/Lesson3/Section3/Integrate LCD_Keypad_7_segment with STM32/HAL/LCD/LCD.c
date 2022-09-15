/*
 * LCD.c
 *
 * Created: 11/3/2021 10:47:55 AM
 *  Author: Ahmed Nasser
 */ 

#include "LCD.h"

// General variables
uint16_t LCD_DataPins[8] = {LCD_D0,LCD_D1,LCD_D2,LCD_D3,LCD_D4,LCD_D5,LCD_D6,LCD_D7};
GPIO_PinConfig_t PinConfig;

void Delay_ms(uint32_t milles){
	uint32_t i,j;
	for(i=0;i<milles;i++)
		for(j=0;j<255;j++);
}

void config_LCD_Pin_INPUT(){
	// Set LCD_Dx x[0:7] as floating Input
	//	LCD_PORT_DDR &= ~(0xFF << Data_shift);  ******** update using for loop
	for(uint8_t i=0;i<8;i++){
		PinConfig.GPIO_PinNumber = LCD_DataPins[i];
		PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
		MCAL_GPIO_Init(LCD_PORT, &PinConfig);
	}


}
void config_LCD_Pin_OUTPUT(){
	// Set LCD_Dx x[0:7] as push-pull Output
	//	LCD_PORT_DDR |= (0xFF << Data_shift); ******** update using for loop
	for(uint8_t i=0;i<8;i++){
		PinConfig.GPIO_PinNumber = LCD_DataPins[i];
			PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
			PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(LCD_PORT, &PinConfig);
	}

}

void HAL_LCD_Isbusy(){
	//port>>input +> RW>>on RS>>off +> check d7 value
	// Set LCD_Dx x[0:7] as floating Input
	config_LCD_Pin_INPUT();

	// Set LCD_RW pin
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW, GPIO_PIN_SET);
	// Set LCD_RS pin
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS, GPIO_PIN_RESET);

	HAL_LCD_Kick();
	// Set LCD_Dx x[0:7] as push-pull Output
	config_LCD_Pin_OUTPUT();


	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW, GPIO_PIN_RESET);



}

void HAL_LCD_Init(){
	Delay_ms(20);
	// SET EN RW RS as Push-pull OUTPUT
	PinConfig.GPIO_PinNumber = EN;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = RS;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = RW;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinConfig);
	
	// Set LCD_Dx x[0:7] as push-pull Output
		config_LCD_Pin_OUTPUT();

	// Reset EN RW RS Value
//	LCD_CTRL_PORT &= ~(1<<EN | 1<<RW | 1<<RS );
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, EN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW, GPIO_PIN_RESET);



	Delay_ms(15);

	HAL_LCD_Clear_Screen();
//
////	#ifdef EIGHT_BIT_MODE
//	HAL_LCD_CMD(LCD_FUNCTION_8BIT_2LINES); // need more generalized
//	//#endif
////	#ifdef FOUR_BIT_MODE
////
////	HAL_LCD_CMD(LCD_RETURN_HOME);
////	HAL_LCD_CMD(LCD_FUNCTION_4BIT_2LINES); // need more generalized
////	#endif
	HAL_LCD_CMD(LCD_ENTRY_MODE);
	HAL_LCD_CMD(LCD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_CMD(LCD_DISP_ON_CURSOR_BLINK);
	
}

void HAL_LCD_Kick(){
	// Reset EN
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, EN, GPIO_PIN_SET);
	Delay_ms(50);
	// set EN
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, EN, GPIO_PIN_RESET);
}
void HAL_LCD_CMD(unsigned char cmd){
	//#ifdef EIGHT_BIT_MODE
		HAL_LCD_Isbusy();
		
//		write Port with command
//		LCD_PORT = cmd;
		MCAL_GPIO_WritePort(LCD_PORT, (uint8_t) cmd); // need to be More Generic
		// reset RW and RS Value
//		LCD_CTRL_PORT &= ~(1<<RW | 1<<RS);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS, GPIO_PIN_RESET);
		HAL_LCD_Kick();
	//#endif

//
//	#ifdef FOUR_BIT_MODE
//	//LCD_Isbusy();
//
//
//	LCD_PORT = (LCD_PORT & 0x0F) |(cmd & 0xF0);
//	LCD_CTRL_PORT &= ~(1<<RW | 1<<RS);
//	HAL_LCD_Kick();
//
//	LCD_PORT = (LCD_PORT & 0x0F) |(cmd << Data_shift);
//	LCD_CTRL_PORT &= ~(1<<RW | 1<<RS);
//	HAL_LCD_Kick();
//	#endif
	
}

void HAL_LCD_Send_char(unsigned char ch){


//	#ifdef EIGHT_BIT_MODE
		HAL_LCD_Isbusy();
		// SET RS
		//		LCD_CTRL_PORT |= (1<<RS);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS, GPIO_PIN_SET);

		//Send Data
		MCAL_GPIO_WritePort(LCD_PORT, (uint8_t) ch); // need to be More Generic


		// SET RS
		//		LCD_CTRL_PORT |= (1<<RS);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS, GPIO_PIN_SET);
		//Reset RW
		//		LCD_CTRL_PORT &= ~(1<<RW );
		MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW, GPIO_PIN_RESET);
		HAL_LCD_Kick();
//	#endif



//	#ifdef FOUR_BIT_MODE
//		//	LCD_Isbusy();
//
//		LCD_PORT = (LCD_PORT & 0x0F) |(ch & 0xF0);
//		LCD_CTRL_PORT |= (1<<RS);
//		LCD_CTRL_PORT &= ~(1<<RW);
//		HAL_LCD_Kick();
//
//		LCD_PORT = (LCD_PORT & 0x0F) |(ch << Data_shift);
//		LCD_CTRL_PORT |= (1<<RS);
//		LCD_CTRL_PORT &= ~(1<<RW );
//		HAL_LCD_Kick();
//	#endif
}
void HAL_LCD_Send_str(char* str){
	int count=0;
	while (*str > 0)
	{
		
		HAL_LCD_Send_char(*str++);
		count++;
		if(count == 16)
		{
			HAL_LCD_GotoXY(0,LCD_SECOND_LINE);
		}
		else if (count == 32 || count == 33)
		{
			HAL_LCD_Clear_Screen();
			HAL_LCD_GotoXY(0,LCD_FIRST_LINE);
			count = 0;
		}
	}
}
void HAL_LCD_Clear_Screen(void){
	HAL_LCD_CMD(LCD_CLEAR_SCREEN);
}
void HAL_LCD_GotoXY(unsigned char pos , unsigned char line){
	if (line == LCD_FIRST_LINE)
	{
		if(pos < 16 && pos >=0)
			HAL_LCD_CMD(LCD_BEGIN_AT_FIRST_ROW + pos);
	}
	else if (line == LCD_SECOND_LINE)
	{
		if(pos < 16 && pos >=0)
			HAL_LCD_CMD(LCD_BEGIN_AT_SECOND_ROW + pos);
	}
}
void HAL_LCD_Send_Num(int num){
	char str[7];
	sprintf(str,"%d",num);
	HAL_LCD_Send_str(str);
}
void HAL_LCD_Send_RealNum(double num){
	char str[16];
	
	char *Sign = (num < 0) ? "-" : "";
	float Val = (num < 0) ? -num : num ;
	int Int = (int)Val;
	float Fraction = Val - Int ;
	Fraction *= 10000;
	
	sprintf(str , "%s%d.%04d" , Sign , Int , (int)Fraction);
	HAL_LCD_Send_str(str);
}
