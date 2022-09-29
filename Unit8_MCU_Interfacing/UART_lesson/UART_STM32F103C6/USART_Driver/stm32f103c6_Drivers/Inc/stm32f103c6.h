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

#define NVIC_BASE  											0xE000E100UL
#define NVIC_ISER0											*(volatile uint32_t *)(NVIC_BASE+0x00)
#define NVIC_ISER1											*(volatile uint32_t *)(NVIC_BASE+0x04)
#define NVIC_ISER2											*(volatile uint32_t *)(NVIC_BASE+0x08)

#define NVIC_ICER0											*(volatile uint32_t *)(NVIC_BASE+0x80)
#define NVIC_ICER1											*(volatile uint32_t *)(NVIC_BASE+0x84)
#define NVIC_ICER2											*(volatile uint32_t *)(NVIC_BASE+0x88)
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

// USART1
#define USART1_BASE							      			0x40013800UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

// USART2
#define USART2_BASE							      			0x40004400UL

// USART3
#define USART3_BASE							      			0x40004800UL





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
	volatile uint32_t  EXTICR[4];
//	volatile uint32_t  EXTICR2;
//	volatile uint32_t  EXTICR3;
//	volatile uint32_t  EXTICR4;
	volatile uint32_t  RESERVED; // RESERVED @0x14 OFFSET
	volatile uint32_t  MAPR2;
}AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t  IMR;
	volatile uint32_t  EMR;
	volatile uint32_t  RTSR;
	volatile uint32_t  FTSR;
	volatile uint32_t  SWIER;
	volatile uint32_t  PR;
}EXTI_t;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t  USART_SR;
	volatile uint32_t  USART_DR;
	volatile uint32_t  USART_BRR;
	volatile uint32_t  USART_CR1;
	volatile uint32_t  USART_CR2;
	volatile uint32_t  USART_CR3;
	volatile uint32_t  USART_GTPR;
}USART_t;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define	RCC   				((RCC_t *) RCC_BASE)

#define	GPIOA   			((GPIO_t *) GPIOA_BASE)
#define	GPIOB   			((GPIO_t *) GPIOB_BASE)
#define	GPIOC   			((GPIO_t *) GPIOC_BASE)
#define	GPIOD  		 		((GPIO_t *) GPIOD_BASE)
#define	GPIOE   			((GPIO_t *) GPIOE_BASE)

#define	AFIO   				((AFIO_t *) AFIO_BASE)

#define	EXTI   				((EXTI_t *) EXTI_BASE)

//USART

#define	USART1   			((USART_t *) USART1_BASE)
#define	USART2   			((USART_t *) USART2_BASE)
#define	USART3   			((USART_t *) USART3_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

// GPIO

#define RCC_GPIOA_CLK_EN()			(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()			(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()			(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()			(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()			(RCC->APB2ENR |= (1<<6))

// AFIO
#define RCC_AFIO_CLK_EN()			(RCC->APB2ENR |= (1<<0))

// USART ENable
// USART1
#define RCC_USART1_CLK_EN()			(RCC->APB2ENR |= (1<<14))
// USART2
#define RCC_USART2_CLK_EN()			(RCC->APB1ENR |= (1<<17))
// USART3
#define RCC_USART3_CLK_EN()			(RCC->APB1ENR |= (1<<18))

// USART Reset Mechanism

// USART1
#define RCC_USART1_CLK_Reset()		(RCC->APB2RSTR |= (1<<14))
// USART2
#define RCC_USART2_CLK_Reset()		(RCC->APB1RSTR |= (1<<17))
// USART3
#define RCC_USART3_CLK_Reset()		(RCC->APB1RSTR |= (1<<18))


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ  enable and disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
/**************ENABLE**************************/

// EXTI
#define NVIC_IRQ6_EXTI0_Enable()             		(NVIC_ISER0 |= (1<<EXTI0_IRQ))
#define NVIC_IRQ7_EXTI1_Enable()             		(NVIC_ISER0 |= (1<<EXTI1_IRQ))
#define NVIC_IRQ8_EXTI2_Enable()            		(NVIC_ISER0 |= (1<<EXTI2_IRQ))
#define NVIC_IRQ9_EXTI3_Enable()             		(NVIC_ISER0 |= (1<<EXTI3_IRQ))
#define NVIC_IRQ10_EXTI4_Enable()             		(NVIC_ISER0 |= (1<<EXTI4_IRQ))
#define NVIC_IRQ23_EXTI5_9_Enable()             	(NVIC_ISER0 |= (1<<EXTI5_IRQ))
#define NVIC_IRQ40_EXTI10_15_Enable()           	(NVIC_ISER1 |= (1<<(EXTI10_IRQ-32)))

// USART
#define NVIC_IRQ37_USART1_Enable()          	 	(NVIC_ISER1 |= (1<<(USART1_IRQ-32)))
#define NVIC_IRQ38_USART2_Enable()      	     	(NVIC_ISER1 |= (1<<(USART2_IRQ-32)))
#define NVIC_IRQ39_USART3_Enable()   	        	(NVIC_ISER1 |= (1<<(USART3_IRQ-32)))



/**************DISABLE**************************/


#define NVIC_IRQ6_EXTI0_Disable()            	 	(NVIC_ICER0 |= (1<<EXTI0_IRQ))
#define NVIC_IRQ7_EXTI1_Disable()             		(NVIC_ICER0 |= (1<<EXTI1_IRQ))
#define NVIC_IRQ8_EXTI2_Disable()             		(NVIC_ICER0 |= (1<<EXTI2_IRQ))
#define NVIC_IRQ9_EXTI3_Disable()             		(NVIC_ICER0 |= (1<<EXTI3_IRQ))
#define NVIC_IRQ10_EXTI4_Disable()          	   	(NVIC_ICER0 |= (1<<EXTI4_IRQ))
#define NVIC_IRQ23_EXTI5_9_Disable()             	(NVIC_ICER0 |= (1<<EXTI5_IRQ))
#define NVIC_IRQ40_EXTI10_15_Disable()    	        (NVIC_ICER1 |= (1<<(EXTI10_IRQ-32)))


// USART
#define NVIC_IRQ37_USART1_Disable()           		(NVIC_ICER1 |= (1<<(USART1_IRQ-32)))
#define NVIC_IRQ38_USART2_Disable()           		(NVIC_ICER1 |= (1<<(USART2_IRQ-32)))
#define NVIC_IRQ39_USART3_Disable()           		(NVIC_ICER1 |= (1<<(USART3_IRQ-32)))


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

// GPIO

#define GPIO_Maping_Position(GPIOx)			( (GPIOx == GPIOA)?0:\
											  (GPIOx == GPIOB)?1:\
											  (GPIOx == GPIOC)?2:\
											  (GPIOx == GPIOD)?3:0\
												)


//-----------------------------
//IVT
//-----------------------------

// EXTI

#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40

// USART

#define USART1_IRQ			37
#define USART2_IRQ			38
#define USART3_IRQ			39






#define EXTI0			0
#define EXTI1			1
#define EXTI2			2
#define EXTI3			3
#define EXTI4			4
#define EXTI5			5
#define EXTI6			6
#define EXTI7			7
#define EXTI8			8
#define EXTI9			9
#define EXTI10			10
#define EXTI11			11
#define EXTI12			12
#define EXTI13			13
#define EXTI14			14
#define EXTI15			15



typedef enum{
	 NOK=0 ,
	 OK=1
}status_t;

// define states of pin
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0


#endif /* INC_STM32F103C6_H_ */



