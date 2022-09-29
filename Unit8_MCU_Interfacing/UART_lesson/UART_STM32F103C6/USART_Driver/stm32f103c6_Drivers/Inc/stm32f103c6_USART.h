/*
 * stm32f103c6_USART.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Ahmed Nasser
 */

#ifndef INC_STM32F103C6_USART_H_
#define INC_STM32F103C6_USART_H_

/*
* ===============================================
* 	Includes
* ===============================================
*/
#include "stm32f103c6.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103c6_RCC.h"


/*
* ===============================================
* Configuration Structure
* ===============================================
*/
typedef struct {

	uint8_t  		USART_Mode; 			// Specifies Tx , Rx Enable or Disable
											// Values Must be set according to @ref USART_Mode_Define

	uint32_t 		USART_Baudrate;			// Specifies the USART_Baudrate
											// Values Must be set according to @ref EUSART_Baudrate_Define

	uint8_t			USART_Payload_Length;	// Specifies the length of Data in USART Frame
											// Values Must be set according to @ref USART_Payload_Length_Define

	uint8_t			USART_Parity;			// Specifies the Parity  in USART Frame
											// Values Must be set according to @ref USART_Parity_Define

	uint8_t			USART_StopBits;			// Specifies the length of Stop in USART Frame
											// Values Must be set according to @ref USART_StopBits_Define

	uint8_t			USART_HWFlowCtrl;		// Specifies the control of enabling or disabling flow control pins
											// Values Must be set according to @ref USART_HWFlowCtrl_Define

	uint8_t			IRQ_EN;					// Specifies enable or disable USART INT (that enable the IRQ Mask in USART and also on NVIC Interrupt)
											// Values Must be set according to @ref USART_IRQ_Define

	void (*Ptr_IRQ_CallBack)(void);			// Set the c Function which will be called by IRQ Handler

}USART_PinConfig_t;

/*
* ===============================================
* Reference Macros
* ===============================================
*/
 //@ref USART_Mode_Define

#define 		USART_Mode_RX						(uint32_t)(1<<2)//Bit 2 RE: Receiver enable
#define 		USART_Mode_TX						(uint32_t)(1<<3)//Bit 3 TE: Transmitter enable
#define 		USART_Mode_TX_RX					(uint32_t)(1<<2  | 1<<3)


//@ref EUSART_Baudrate_Define

#define			USART_Baudrate_2400					2400
#define			USART_Baudrate_9600					9600
#define			USART_Baudrate_19200				19200
#define			USART_Baudrate_57600				57600
#define			USART_Baudrate_115200				115200
#define			USART_Baudrate_230400				230400
#define			USART_Baudrate_460800				460800
#define			USART_Baudrate_921600				921600
#define			USART_Baudrate_2250000				2250000
#define			USART_Baudrate_4500000				4500000

//@ref USART_Payload_Length_Define

/*Bit 12 M: Word length
This bit determines the word length. It is set or cleared by software.
0: 1 Start bit, 8 Data bits, n Stop bit
1: 1 Start bit, 9 Data bits, n Stop bit*/

#define 		USART_Payload_Length_9bits				(uint32_t)(1<<12)
#define 		USART_Payload_Length_8bits				(uint32_t)(0)

//@ref USART_Parity_Define
/*
 * 	Bit 10 PCE: Parity control enable
	This bit selects the hardware parity control (generation and detection). When the parity
	control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
	if M=0).

	Once it is set, PCE is active after the current byte (in reception and in transmission).
	0: Parity control disabled
	1: Parity control enabled

	Bit 9 PS: Parity selection
	This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
	bit set).

	0: Even parity
	1: Odd parity
 */

#define 		USART_Parity_None						(uint32_t)(0)
#define 		USART_Parity_Even						(uint32_t)(1<<10)
#define 		USART_Parity_Odd						(uint32_t)(1<<10 | 1<<9)


//@ref USART_StopBits_Define
/*
 * Bits 13:12 STOP: STOP bits
	These bits are used for programming the stop bits.
	00: 1 Stop bit
	01: 0.5 Stop bit
	10: 2 Stop bits
	11: 1.5 Stop bit
 */
#define 		USART_StopBits_half						(uint32_t)(1<<12)
#define 		USART_StopBits_1							(uint32_t)(0)
#define 		USART_StopBits_1_half						(uint32_t)(1<<12 | 1<<13)
#define 		USART_StopBits_2							(uint32_t)(1<<13)

// @ref USART_HWFlowCtrl_Define

/*
	Bit 9 CTSE: CTS enable
	0: CTS hardware flow control disabled
	1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0).

	Bit 8 RTSE: RTS enable
	0: RTS hardware flow control disabled
	1: RTS interrupt enabled
*/

#define			USART_HWFlowCtrl_None					(uint32_t)(0)
#define 		USART_HWFlowCtrl_CTS					(uint32_t)(1<<9)
#define 		USART_HWFlowCtrl_RTS					(uint32_t)(1<<8)
#define 		USART_HWFlowCtrl_CTS_RTS				(uint32_t)(1<<9 | 1<<8)


// @ref USART_IRQ_Define


#define 		USART_IRQ_Enable_None					(uint32_t)(0)
#define 		USART_IRQ_Enable_TXE					(uint32_t)(1<<7)//Bit 7 TXEIE: TXE interrupt enable
#define 		USART_IRQ_Enable_TC						(uint32_t)(1<<6)//Bit 6 TCIE: Transmission complete interrupt enable
#define 		USART_IRQ_Enable_RXNEIE					(uint32_t)(1<<5)//Bit 5 RXNEIE: RXNE interrupt enable
#define 		USART_IRQ_Enable_PE						(uint32_t)(1<<8)//Bit 8 PEIE: PE interrupt enable



enum Polling_Mechanism{
	Enable,
	Disable

};



/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_USART_Init(USART_t*	USARTx , USART_PinConfig_t* USART_PinConfig);
void MCAL_USART_DeInit(USART_t*	USARTx );

void MCAL_USART_GPIO_Set_Pins(USART_t*	USARTx );


void MCAL_USART_Send(USART_t*	USARTx , uint16_t* u16Data_Buffer ,enum Polling_Mechanism	Polling_EN);
void MCAL_USART_Receive(USART_t*	USARTx , uint16_t* u16Data_Buffer ,enum Polling_Mechanism	Polling_EN);

void MCAL_USART_Wait_TC(USART_t*	USARTx);




















#endif /* INC_STM32F103C6_USART_H_ */
