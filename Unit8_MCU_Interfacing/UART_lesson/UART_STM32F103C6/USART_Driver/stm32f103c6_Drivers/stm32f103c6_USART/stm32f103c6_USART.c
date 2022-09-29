/*
 * stm32f103c6_USART.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Ahmed Nasser
 */

//======================================================
// Includes
//======================================================

#include "../Inc/stm32f103c6_USART.h"


//======================================================
// Global Variables
//======================================================

USART_PinConfig_t* GPtr_USART_PinConfig[3] = {NULL};


//======================================================
// APIs Impelmentaion
//======================================================


/**================================================================
 * @Function Name              :- MCAL_USART_Init
 * @brief           		   :- Initialize USART according to given configuration structure
 * @parameter[in]			   :- USARTx :  USART Module Number (USART[1:3])
 *@parameter[in]			   :- USART_PinConfig: configuration structure
 * @return value 			   :- none
 * Note                        :- Support only asyncrounos mode
 *================================================================ */
void MCAL_USART_Init(USART_t*	USARTx , USART_PinConfig_t* USART_PinConfig){

	uint32_t u32PCLK ;




	// enable Clock for USARTx
	if(USARTx == USART1){

		GPtr_USART_PinConfig[0] = USART_PinConfig;
		RCC_USART1_CLK_EN();

	}else if(USARTx == USART2){

		GPtr_USART_PinConfig[1] = USART_PinConfig;
		RCC_USART2_CLK_EN();

	}else if(USARTx == USART3){
		GPtr_USART_PinConfig[2] = USART_PinConfig;
		RCC_USART3_CLK_EN();
	}

	// Enable USART Module

	USARTx->USART_CR1 |= (1<<13); //Bit 13 UE: USART enable

	// Enable TX & RX
	USARTx->USART_CR1 |= USART_PinConfig->USART_Mode;

	// Config Fram

	// Payload_Length
	USARTx->USART_CR1 |= USART_PinConfig->USART_Payload_Length;
	// Parity
	USARTx->USART_CR1 |= USART_PinConfig->USART_Parity;
	// StopBits
	USARTx->USART_CR2 |= USART_PinConfig->USART_StopBits;

	// USART HW Flow Control

	USARTx->USART_CR3 |= USART_PinConfig->USART_HWFlowCtrl;

	// Configure Baudrate (PCLK1>>USART2,3  & PCLK2 >> USART1)

	// Select which PCLK between 1 & 2
	if(USARTx == USART1){
		u32PCLK = MCAL_RCC_GetAPB2_ClkFreq();
	}else{
		u32PCLK = MCAL_RCC_GetAPB1_ClkFreq();
	}

	// Calculate BRR Value "Baudrate= (Fclk/16*USARTDIV)" (Different than lec)

	USARTx->USART_BRR |= (uint32_t)((u32PCLK/(USART_PinConfig->USART_Baudrate)) % 16);
	USARTx->USART_BRR |= ((uint32_t)((u32PCLK/(USART_PinConfig->USART_Baudrate)) / 16)) << 4;

	// Enable and Disable Interrupt

	if(USART_PinConfig->IRQ_EN != USART_IRQ_Enable_None){
		USARTx->USART_CR1 |= USART_PinConfig->IRQ_EN;

		// Enable NVIC IRQ

		if(USARTx == USART1){

			NVIC_IRQ37_USART1_Enable();

		}else if(USARTx == USART2){

			NVIC_IRQ38_USART2_Enable();

		}else if(USARTx == USART3){

			NVIC_IRQ39_USART3_Enable();
		}

	}

}

/**================================================================
 * @Function Name              :- MCAL_USART_DeInit
 * @brief           		   :- Deinitialize USART
 * @parameter[in]			   :- USARTx :  USART Module Number (USART[1:3])
 * @return value 			   :- none
 * Note                        :- Support only asyncrounos mode
 *================================================================ */
void MCAL_USART_DeInit(USART_t*	USARTx ){

	// Disable Clock
	// Disable NVIC
	if(USARTx == USART1){

		RCC_USART1_CLK_Reset();
		NVIC_IRQ37_USART1_Disable();

	}else if(USARTx == USART2){

		RCC_USART2_CLK_Reset();
		NVIC_IRQ38_USART2_Disable();

	}else if(USARTx == USART3){

		RCC_USART3_CLK_Reset();
		NVIC_IRQ39_USART3_Disable();
	}

}


/**================================================================
 * @Function Name              :- MCAL_USART_GPIO_Set_Pins
 * @brief           		   :- config GPIO pins of required USART Module
 * @parameter[in]			   :- USARTx :  USART Module Number (USART[1:3])
 * @return value 			   :- none
 * Note                        :- Support only asyncrounos mode
 *================================================================ */
void MCAL_USART_GPIO_Set_Pins(USART_t*	USARTx ){
	/*
	 * Recommandation settening
	USARTx_TX: Full duplex >>> Alternate function push-pull or open-drain

	USARTx_RX: Full duplex >>> Input floating / Input pull-up

	USARTx_RTS: Alternate function push-pull

    USARTx_CTS: Input floating/ Input pull-up

	*/

	GPIO_PinConfig_t GPIO_PinCof;

	// USART1 (Tx>>PA9 Rx>>PA10 RTS>>PA12 CTS>>PA11)
	if(USARTx == USART1){
		// TX >>>>> PA9  Alternate function push-pull
		GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_9;
		GPIO_PinCof.GPIO_Mode  = GPIO_MODE_OUTPUT_AF_PP;
		GPIO_PinCof.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);

		// RX >>>>> PA10 Input floating

		GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_10;
		GPIO_PinCof.GPIO_Mode  = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);

		// CTS >>>>>> PA11 Input floating
		if(GPtr_USART_PinConfig[0]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS || GPtr_USART_PinConfig[0]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS_RTS)
		{
			GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_11;
			GPIO_PinCof.GPIO_Mode  = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);
		}

		// RTS >>>>>> PA12 Alternate function push-pull
		if(GPtr_USART_PinConfig[0]->USART_HWFlowCtrl == USART_HWFlowCtrl_RTS || GPtr_USART_PinConfig[0]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS_RTS)
		{
			GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_12;
			GPIO_PinCof.GPIO_Mode  = GPIO_MODE_OUTPUT_AF_PP;
			GPIO_PinCof.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);
		}


		// USART2 (Tx>>PA2 Rx>>PA3 RTS>>PA1 CTS>>PA0)

	}else if(USARTx == USART2){



		// TX >>>>> PA2  Alternate function push-pull
		GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_2;
		GPIO_PinCof.GPIO_Mode  = GPIO_MODE_OUTPUT_AF_PP;
		GPIO_PinCof.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);

		// RX >>>>> PA3 Input floating

		GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_3;
		GPIO_PinCof.GPIO_Mode  = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);

		// CTS >>>>>> PA0 Input floating
		if(GPtr_USART_PinConfig[1]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS || GPtr_USART_PinConfig[1]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS_RTS)
		{
			GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_0;
			GPIO_PinCof.GPIO_Mode  = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);
		}

		// RTS >>>>>> PA1 Alternate function push-pull
		if(GPtr_USART_PinConfig[1]->USART_HWFlowCtrl == USART_HWFlowCtrl_RTS || GPtr_USART_PinConfig[1]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS_RTS)
		{
			GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_1;
			GPIO_PinCof.GPIO_Mode  = GPIO_MODE_OUTPUT_AF_PP;
			GPIO_PinCof.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinCof);
		}


	// USART3 (Tx>>PB10 Rx>>PB11 RTS>>PB14 CTS>>PB13)

	}else if(USARTx == USART2){



		// TX >>>>> PB10  Alternate function push-pull
		GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_10;
		GPIO_PinCof.GPIO_Mode  = GPIO_MODE_OUTPUT_AF_PP;
		GPIO_PinCof.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &GPIO_PinCof);

		// RX >>>>> PB11 Input floating

		GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_11;
		GPIO_PinCof.GPIO_Mode  = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOB, &GPIO_PinCof);

		// CTS >>>>>> PB13 Input floating
		if(GPtr_USART_PinConfig[2]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS || GPtr_USART_PinConfig[2]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS_RTS)
		{
			GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_13;
			GPIO_PinCof.GPIO_Mode  = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &GPIO_PinCof);
		}

		// RTS >>>>>> PB14 Alternate function push-pull
		if(GPtr_USART_PinConfig[2]->USART_HWFlowCtrl == USART_HWFlowCtrl_RTS || GPtr_USART_PinConfig[2]->USART_HWFlowCtrl == USART_HWFlowCtrl_CTS_RTS)
		{
			GPIO_PinCof.GPIO_PinNumber = GPIO_PIN_14;
			GPIO_PinCof.GPIO_Mode  = GPIO_MODE_OUTPUT_AF_PP;
			GPIO_PinCof.GPIO_OUTPUT_Speed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &GPIO_PinCof);
		}

	}
}

/**================================================================
 * @Function Name              :- MCAL_USART_Send
 * @brief           		   :- Send Data USART Module
 * @parameter[in]			   :- USARTx :  USART Module Number (USART[1:3])
 * @parameter[in]			   :- u16Data_Buffer :  pointer to send Data
 * @parameter[in]			   :- Polling_EN :  Enable or Disable Polling mechanism
 * @return value 			   :- none
 * Note                        :- Support only asyncrounos mode
 *================================================================ */
void MCAL_USART_Send(USART_t*	USARTx , uint16_t* u16Data_Buffer ,enum Polling_Mechanism	Polling_EN){
	// Data register (USART_DR) : Bits 8:0 DR[8:0]: Data value Contains the Received or Transmitted data character

	// wait untill data is transmitted to shift data register in polling mechanism only
		//Bit 7 TXE: Transmit data register empty
	if(Polling_EN == Enable)
		while( !( USARTx->USART_SR &(1<<7) ) );


	if(USARTx == USART1){
		// adjuct data to fit with 9bits and 8bits
		if(GPtr_USART_PinConfig[0]->USART_Payload_Length == USART_Payload_Length_9bits){

			USARTx->USART_DR = (*u16Data_Buffer & (uint16_t) 0x01FF);

		}else{
			USARTx->USART_DR = (*u16Data_Buffer & (uint16_t) 0x00FF);
		}



	}else if(USARTx == USART2){


		// adjuct data to fit with 9bits and 8bits
		if(GPtr_USART_PinConfig[1]->USART_Payload_Length == USART_Payload_Length_9bits){

			USARTx->USART_DR = (*u16Data_Buffer & (uint16_t) 0x01FF);

		}else{
			USARTx->USART_DR = (*u16Data_Buffer & (uint16_t) 0x00FF);
		}




	}else if(USARTx == USART3){


		// adjuct data to fit with 9bits and 8bits
		if(GPtr_USART_PinConfig[2]->USART_Payload_Length == USART_Payload_Length_9bits){

			USARTx->USART_DR = (*u16Data_Buffer & (uint16_t) 0x01FF);

		}else{
			USARTx->USART_DR = (*u16Data_Buffer & (uint16_t) 0x00FF);
		}

	}

}

/**================================================================
 * @Function Name              :- MCAL_USART_Receive
 * @brief           		   :- Receive Data USART Module
 * @parameter[in]			   :- USARTx :  USART Module Number (USART[1:3])
 * @parameter[in]			   :- u16Data_Buffer :  pointer to Receive Data on it
 * @parameter[in]			   :- Polling_EN :  Enable or Disable Polling mechanism
 * @return value 			   :- none
 * Note                        :- Support only asyncrounos mode
 *================================================================ */
void MCAL_USART_Receive(USART_t*	USARTx , uint16_t* u16Data_Buffer ,enum Polling_Mechanism	Polling_EN){


	// Data register (USART_DR) : Bits 8:0 DR[8:0]: Data value Contains the Received or Transmitted data character

	 // wait untill data is received to shift data register in polling mechanism only
	 // Bit 5 RXNE: Read data register not empty This bit is set by hardware when the content
	 // of the RDR shift register has been transferred to the USART_DR register
		if(Polling_EN == Enable)
			while( !( USARTx->USART_SR &(1<<5) ) );


		if(USARTx == USART1){


			// adjuct data to fit with 9bits and 8bits
				if(GPtr_USART_PinConfig[0]->USART_Payload_Length == USART_Payload_Length_9bits){

					if(GPtr_USART_PinConfig[0]->USART_Parity == USART_Parity_None){

						 // take all 9bits
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x01FF);

					}else{

						// take only 8bits and leave parity bit
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x00FF);
					}


				}else{
					// 8bit payload mode

					if(GPtr_USART_PinConfig[0]->USART_Parity == USART_Parity_None){

						// take all 8bits
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x00FF);

					}else{

						// take only 7bits and leave parity bit
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x007F);
					}
				}


		}else if(USARTx == USART2){


			// adjuct data to fit with 9bits and 8bits
				if(GPtr_USART_PinConfig[1]->USART_Payload_Length == USART_Payload_Length_9bits){

					if(GPtr_USART_PinConfig[1]->USART_Parity == USART_Parity_None){

						 // take all 9bits
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x01FF);

					}else{

						// take only 8bits and leave parity bit
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x00FF);
					}


				}else{
					// 8bit payload mode

					if(GPtr_USART_PinConfig[1]->USART_Parity == USART_Parity_None){

						// take all 8bits
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x00FF);

					}else{

						// take only 7bits and leave parity bit
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x007F);
					}
				}


		}else if(USARTx == USART3){


			// adjuct data to fit with 9bits and 8bits
				if(GPtr_USART_PinConfig[2]->USART_Payload_Length == USART_Payload_Length_9bits){

					if(GPtr_USART_PinConfig[2]->USART_Parity == USART_Parity_None){

						 // take all 9bits
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x01FF);

					}else{

						// take only 8bits and leave parity bit
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x00FF);
					}


				}else{
					// 8bit payload mode

					if(GPtr_USART_PinConfig[2]->USART_Parity == USART_Parity_None){

						// take all 8bits
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x00FF);

					}else{

						// take only 7bits and leave parity bit
						*((uint16_t*)u16Data_Buffer) = (USARTx->USART_DR & (uint16_t) 0x007F);
					}
				}



		}


}

/**================================================================
 * @Function Name              :- MCAL_USART_Wait_TC
 * @brief           		   :- check USART Module Compelete Transmission or not
 * @parameter[in]			   :- USARTx :  USART Module Number (USART[1:3])
 * @return value 			   :- none
 * Note                        :- Support only asyncrounos mode
 *================================================================ */
void MCAL_USART_Wait_TC(USART_t*	USARTx){

	//bit6 TC : This bit is set by hardware if the transmission of a frame
	//containing data is complete and if TXE is set.

	while( !( USARTx->USART_SR &(1<<6) ) );

}



/**================================================================
								ISR
 *================================================================ */

void USART1_IRQHandler(void){

	GPtr_USART_PinConfig[0]->Ptr_IRQ_CallBack();
}

void USART2_IRQHandler(void){

	GPtr_USART_PinConfig[1]->Ptr_IRQ_CallBack();
}

void USART3_IRQHandler(void){

	GPtr_USART_PinConfig[2]->Ptr_IRQ_CallBack();
}

