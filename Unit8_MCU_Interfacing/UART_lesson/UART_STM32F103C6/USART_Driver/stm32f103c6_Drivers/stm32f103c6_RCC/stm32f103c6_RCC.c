/*
 * stm32f103c6_RCC.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Ahmed Nasser
 */

//======================================================
// Includes
//======================================================

#include "../Inc/stm32f103c6_RCC.h"


//======================================================
// Generic Variables
//======================================================

/*
	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
	*/
/*
  	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16

 * */
const uint8_t APBPrescTable[8U] = {0,0,0,0,1,2,3,4}; // shift right (divide by 2^x)

/*
 * Bits 7:4 HPRE: AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512
 */
const uint8_t AHBPrescTable[16U] = {0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9}; // shift right (divide by 2^x)

/*
	Bits 3:2 SWS: System clock switch status
	Set and cleared by hardware to indicate which clock source is used as system clock.
	00: HSI oscillator used as system clock
	01: HSE oscillator used as system clock
	10: PLL used as system clock
	11: not applicable
*/




//======================================================
// Macros
//======================================================

#define HSI_RC_Clk			(uint32_t)8000000UL

// to do need to modified
#define HSE_RC_Clk			(uint32_t)16000000UL
#define PLL_RC_Clk			(uint32_t)16000000UL


//======================================================
// APIs Implementation
//======================================================

uint32_t MCAL_RCC_GetSys_ClkFreq(void){
	switch( ((RCC->CFGR) >> 2) & 0b11 )
		{
		case 0:
			// to do need to calculate it
			return HSI_RC_Clk;
			break;
		case 1:
			// to do need to calculate it
			return HSE_RC_Clk;
			break;
		case 2:
			// to do need to calculate it
			return PLL_RC_Clk;
			break;

	}
	return 0;
}
uint32_t MCAL_RCC_GetHClkFreq(void){
	uint8_t u8Index = ((RCC->CFGR) >> 4) & 0b1111;
		return (MCAL_RCC_GetSys_ClkFreq() >> AHBPrescTable[u8Index]);
}
uint32_t MCAL_RCC_GetAPB1_ClkFreq(void){

	uint8_t u8Index = ((RCC->CFGR) >> 8) & 0b111;
	return (MCAL_RCC_GetHClkFreq() >> APBPrescTable[u8Index]);

}
uint32_t MCAL_RCC_GetAPB2_ClkFreq(void){
	uint8_t u8Index = ((RCC->CFGR) >> 11) & 0b111;
	return (MCAL_RCC_GetHClkFreq() >> APBPrescTable[u8Index]);

}
