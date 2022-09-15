/*
 * KEYPAD.c
 *
 * Created: 11/3/2021 8:29:00 PM
 *  Author: Ahmed Nasser
 */ 

#include "KEYPAD.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns

void Keypad_Init(){
	KEYPAD_PORT_DDR &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3)); // Row Inputs 
	
	KEYPAD_PORT_DDR |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3)); // column Output
	KEYPAD_PORT = 0xFF;
}

char Keypad_Getkey(){
	int i,j;
	char ch = '\0';
	while(ch == '\0'){
	for (i = 0; i < 4; i++){
		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
		KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		for(j = 0; j < 4; j++){
			if (!(keypadPIN & (1 << Key_padRow[j])))
			{
				while(!(keypadPIN & (1 << Key_padRow[j])));
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