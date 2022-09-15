/*
 * KEYPAD.c
 *
 * Created: 11/3/2021 8:29:00 PM
 *  Author: Ahmed Nasser
 */ 

#include "KEYPAD.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns

// General PINconfig structure

GPIO_PinConfig_t PinConfig;

void HAL_Keypad_Init(){
	//	KEYPAD_PORT_DDR &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3)); // Row Inputs
	// Set ROW Pins as PULL UP INPUT  (modify using for loop)
	PinConfig.GPIO_PinNumber = R0;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R1;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R2;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R3;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);


	//	KEYPAD_PORT_DDR |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3)); // column Output
	// Set Columns Pins as Push-Pull OUTPUT  (modify using for loop)
	PinConfig.GPIO_PinNumber = C0;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C1;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);


	PinConfig.GPIO_PinNumber = C2;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C3;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	// SET all PINs
	MCAL_GPIO_WritePort(KEYPAD_PORT, (uint8_t) 0xFF);
	//	KEYPAD_PORT = 0xFF;
}

char HAL_Keypad_Getkey(){
	int i,j;
	char ch = '\0';
	while(ch == '\0'){
	for (i = 0; i < 4; i++){
//		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
		// Set Columns Pins (may be update by for loop)
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);
		// reset pin according to i
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);
		//KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		for(j = 0; j < 4; j++){
			if (!(MCAL_GPIO_ReadPort(KEYPAD_PORT) & ( Key_padRow[j])))
			{
				while(!(MCAL_GPIO_ReadPort(KEYPAD_PORT) & ( Key_padRow[j])));
				switch(i){
					case (0):
						if (j == 0)		 ch = '7';
						else if (j == 1) ch = '4';
						else if (j == 2) ch = '1';
						else if (j == 3) ch = 'O';
						break;
					case (1):
						if (j == 0)		 ch = '8';
						else if (j == 1) ch = '5';
						else if (j == 2) ch = '2';
						else if (j == 3) ch = '0';
						break;
					case (2):
						if (j == 0)		 ch = '9';
						else if (j == 1) ch = '6';
						else if (j == 2) ch = '3';
						else if (j == 3) ch = '=';
						break;
					case (3):
						if (j == 0) 	 ch = '/';
						else if (j == 1) ch = '*';
						else if (j == 2) ch = '-';
						else if (j == 3) ch = '+';
						break;
					default:
						ch = 'N';
						break;
				}
			}
		}
	}
	}
	return ch;
}
