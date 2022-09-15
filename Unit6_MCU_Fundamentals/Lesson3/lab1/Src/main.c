/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include "../platform.h"

// REG definition

#define RCC_BASE				  0x40021000
#define GPIOA_BASE	 			  0x40010800
#define RCC_APB2ENR     *((vuint32 *) (RCC_BASE + 0x18))
#define GPIOA_CRH	    *((vuint32 *) (GPIOA_BASE + 0x04))
#define GPIOA_ODR	    *((vuint32 *) (GPIOA_BASE + 0x0c))

#define RCC_IOPAEN (1<<2)  // pin2 in APB2ENR_reg in RCC (iopaen_bit)

typedef union {
	vuint32 PORTA;
	struct{
		vuint32  reserved:13;
		vuint32  A13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t*   R_ODR =  (volatile R_ODR_t*) (GPIOA_BASE + 0x0c);

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0xFE0FFFFF; // to clear bits from (20 to 24)
	GPIOA_CRH |= 0x00200000;  //(mode=2)bit(20 to 24)

	while(1){
		R_ODR->pin.A13 = 1;
		for(int i=0;i<5000;i++);
		R_ODR->pin.A13 = 0;
		for(int i=0;i<5000;i++);
	}

}

