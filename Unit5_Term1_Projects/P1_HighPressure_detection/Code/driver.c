#include "driver.h"
#include <stdint.h>
#include <stdio.h>
void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

uint32_t Get_Pressure_Val(){
	uint32_t x ;
	x = (GPIOA_IDR & 0xFF);
	return x;
}

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2); // enable GPIOA
	GPIOA_CRL &= 0xFFFFFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;//changed from 0x22222222
}
