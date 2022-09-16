/*
 * SevenSegment.c
 *
 * Created: 9/9/2022 5:14:47 PM
 *  Author: Ahmed Nasser
 */ 

#include "SevenSegment.h"

uint8 SevenSegment_num[] ={0b11100111,0b10000100,0b11010011,0b11010110,0b10110100,01110110,0b01110111,0b11000100,0b11110111,0b11110110};


void SevenSegment_init(){
	
	
	
	#if (SevenSegment_MODE == Four_bits)
		SetBit(SevenSegment_DDR,SevenSegment_PIN0);
		SetBit(SevenSegment_DDR,SevenSegment_PIN1);
		SetBit(SevenSegment_DDR,SevenSegment_PIN2);
		SetBit(SevenSegment_DDR,SevenSegment_PIN3);
	#elif (SevenSegment_MODE == Eight_bits)
	
	

	#endif
	
	
	return;
}

void SevenSegment_Display(uint8 num){
	uint8 temp ;
	#if (SevenSegment_MODE == Four_bits)
	SevenSegment_PORT = num;
#elif (SevenSegment_MODE == Eight_bits)

	SevenSegment_PORT = SevenSegment_num[num];

#endif
	
	
	
	
	return;
}
