/*
 * stm32f103c6.h
 *
 *  Created on: Nov 5, 2021
 *      Author: Ahmed Nasser
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include "stdint.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define Flash_Memory_BASE     								0x08000000UL
#define System_Memory_BASE    								0x1FFFF000UL
#define SRAM_Memory_BASE      								0x20000000UL

#define Peripherals_BASE    							    0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE      			0xE0000000UL



//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE							      			0x40021000UL



//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------


// GPIOx PORTs
/*[!Note]for Package LQFP48
 * GPIOA and GPIOB are fully included
 * GPIOC and GPIOD are partially included
 * GPIOE and GPIOG are not included
 * */
#define GPIOG_BASE							      			0x40012000UL
#define GPIOF_BASE							      			0x40011C00UL
#define GPIOE_BASE							      			0x40011800UL
#define GPIOD_BASE							      			0x40011400UL
#define GPIOC_BASE							      			0x40011000UL
#define GPIOB_BASE							      			0x40010C00UL
#define GPIOA_BASE							      			0x40010800UL

// External interrupt (EXTI)
#define EXTI_BASE							      			0x40010400UL
// alternative function input/output (AFIO)
#define AFIO_BASE							      			0x40010000UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------





//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t  CRL;
	volatile uint32_t  CRH;
	volatile uint32_t  IDR;
	volatile uint32_t  ODR;
	volatile uint32_t  BSRR;
	volatile uint32_t  BRR;
	volatile uint32_t  LCKR;
}GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t  ECVR;
	volatile uint32_t  MAPR;
	volatile uint32_t  EXTICR1;
	volatile uint32_t  EXTICR2;
	volatile uint32_t  EXTICR3;
	volatile uint32_t  EXTICR4;
	volatile uint32_t  RESERVED; // RESERVED @0x14 OFFSET
	volatile uint32_t  MAPR2;
}AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t  IMR;
	volatile uint32_t  EMR;
	volatile uint32_t  ETSR;
	volatile uint32_t  FTSR;
	volatile uint32_t  SWIER;
	volatile uint32_t  PR;
}EXTI_t;





//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define	RCC   			((RCC_t *) RCC_BASE)

#define	GPIOA   		((GPIO_t *) GPIOA_BASE)
#define	GPIOB   		((GPIO_t *) GPIOB_BASE)
#define	GPIOC   		((GPIO_t *) GPIOC_BASE)
#define	GPIOD   		((GPIO_t *) GPIOD_BASE)
#define	GPIOE   		((GPIO_t *) GPIOE_BASE)

#define	AFIO   			((AFIO_t *) AFIO_BASE)

#define	EXTI   			((EXTI_t *) EXTI_BASE)



//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= (1<<6))


#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= (1<<0))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


typedef enum{
	 NOK=0 ,
	 OK=1
}status_t;

// define states of pin
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0


#endif /* INC_STM32F103C6_H_ */



