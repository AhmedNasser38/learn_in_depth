/*
 * stm32f103c6_GPIO_Driver.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Ahmed Nasser
 */

//-----------------------------
//Includes
//-----------------------------

#include "../Inc/stm32f103c6.h"
#include "../Inc/stm32f103c6_GPIO_Driver.h"




uint8_t GetPinPosition(uint16_t PinNumber){

	switch(PinNumber){
	case GPIO_PIN_0 :
		return 0;
		break;
	case GPIO_PIN_1 :
		return 4;
		break;
	case GPIO_PIN_2 :
		return 8;
		break;
	case GPIO_PIN_3 :
		return 12;
		break;
	case GPIO_PIN_4 :
		return 16;
		break;
	case GPIO_PIN_5 :
		return 20;
		break;
	case GPIO_PIN_6 :
		return 24;
		break;
	case GPIO_PIN_7 :
		return 28;
		break;
	case GPIO_PIN_8 :
		return 0;
		break;
	case GPIO_PIN_9 :
		return 4;
		break;
	case GPIO_PIN_10 :
		return 8;
		break;
	case GPIO_PIN_11 :
		return 12;
		break;
	case GPIO_PIN_12 :
		return 16;
		break;
	case GPIO_PIN_13 :
		return 20;
		break;
	case GPIO_PIN_14 :
		return 24;
		break;
	case GPIO_PIN_15 :
		return 28;
		break;
	default:
		return 0;
	}
}


// Initialization Function

/**================================================================
 * @Function name 	:- MCAL_GPIO_Init
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
status_t MCAL_GPIO_Init(GPIO_t *GPIOx , GPIO_PinConfig_t* PinConfig){

	//variable used
	volatile uint32_t *Ptr_ConfigRegister = NULL;
	uint8_t  u8PinPosition = 0;
	uint8_t  u8PinConfig_Value = 0;
	// determine which register will be written CRL For [0:7] and CRH for [8:15]
	Ptr_ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;
	// determine the position of the pin in the register
	u8PinPosition = GetPinPosition(PinConfig->GPIO_PinNumber);


	// clear Pin before config it again
	*Ptr_ConfigRegister &= ~(0xF << u8PinPosition);
	// check if the pin output or not
	if((PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD)|(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP)|(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD)|(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP)){

		// Set CNFy and MODEy according to Configuration structure
		u8PinConfig_Value = ((((PinConfig->GPIO_Mode - 4) << 2)|(PinConfig->GPIO_OUTPUT_Speed))&0x0F);

	}else{
		// here pin is input
		if((PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)){

			u8PinConfig_Value = (((GPIO_MODE_INPUT_PU)<<2) & 0x0F);
			//according to Table 20. Port bit configuration table in  PU ODRx must be written to one
			GPIOx->ODR |= (PinConfig->GPIO_PinNumber);


		}else if((PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PD)){
			//
			u8PinConfig_Value = (((GPIO_MODE_INPUT_PU)<<2) & 0x0F);
			//according to Table 20. Port bit configuration table in  PU ODRx must be written to zero(0)
			GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);

		}else if((PinConfig->GPIO_Mode == GPIO_MODE_INPUT_AF)){

			u8PinConfig_Value = (((GPIO_MODE_INPUT_FLO)<<2) & 0x0F);

		}else{

			u8PinConfig_Value = (((PinConfig->GPIO_Mode)<<2) & 0x0F);

		}

	}

	*Ptr_ConfigRegister |= (u8PinConfig_Value << u8PinPosition);

	return OK;


}

/**================================================================
 * @Function name 	:- MCAL_GPIO_DeInit
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
status_t MCAL_GPIO_DeInit(GPIO_t *GPIOx){

	/*
	// Reset Manually if there's no reset controller in MCU
	GPIOx->CRL  = 0x44444444;
	GPIOx->CRH  = 0x44444444;
	GPIOx->BRR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR  = 0x00000000;
	//GPIOx->IDR Read only\
	 */

	// or can be done by reset controller RCC
	if(GPIOx == GPIOA){

		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);

	}else if (GPIOx == GPIOB){

		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);

	}else if (GPIOx == GPIOC){

		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);

	}else if (GPIOx == GPIOD){

		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);

	}else if (GPIOx == GPIOE){

		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);

	}

	return OK;
}

// Read Functions
/**================================================================
 * @Function name 	:- MCAL_GPIO_ReadPin
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
uint8_t  MCAL_GPIO_ReadPin(GPIO_t *GPIOx , uint16_t PinNumber){

	uint8_t PinState = GPIO_PIN_RESET;
	if( ((GPIOx->IDR) & PinNumber) != (uint32_t) GPIO_PIN_RESET ){
		PinState = GPIO_PIN_SET;
	}

	return PinState;
}

/**================================================================
 * @Function name 	:- MCAL_GPIO_ReadPort
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx){

	return ((uint16_t)GPIOx->IDR);
}


// Write Functions
/**================================================================
 * @Function name 	:- MCAL_GPIO_WritrPin
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
status_t  MCAL_GPIO_WritePin(GPIO_t *GPIOx , uint16_t PinNumber , uint8_t u8Value){

	if(u8Value == GPIO_PIN_SET){

		// GPIOx->ODR |= (PinNumber);
		// or for less instructions

		GPIOx->BSRR = (uint32_t)PinNumber;

	}else if(u8Value == GPIO_PIN_RESET){

		// GPIOx->ODR &= ~(PinNumber);

		GPIOx->BRR = (uint32_t)PinNumber;
	}

	return OK;
}
/**================================================================
 * @Function name 	:- MCAL_GPIO_WritePort
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
status_t  MCAL_GPIO_WritePort(GPIO_t *GPIOx , uint16_t u16Value){

	GPIOx->ODR = (uint32_t) u16Value;

	return OK;
}

/**================================================================
 * @Function name 	:- MCAL_GPIO_TogglePin
 * @brief 			:-
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
status_t  MCAL_GPIO_TogglePin(GPIO_t *GPIOx , uint16_t PinNumber ){

	GPIOx->ODR ^= (uint32_t)PinNumber;
	return OK;

}

// Lock Function
/**================================================================
 * @Function name 	:- MCAL_GPIO_LockPin
 * @brief 			:- lock the configuration of the port bits when a correct write sequence
						is applied to bit 16 (LCKK).
 * @Parameter [in] 	:- GPIOx represents selected GPIO it can be [A:E]
 * @Parameter [in] 	:-
 * @return value     :- State of Function OK if run successfully or NOK if failed.
 * Note			    :-None
 */
status_t  MCAL_GPIO_LockPin(GPIO_t *GPIOx , uint16_t PinNumber ){

	volatile uint32_t temp =0;
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	//clear LCKK to can write to LCKy pins
	GPIOx->LCKR &= ~(1<<16);
	GPIOx->LCKR |= (uint32_t) PinNumber;

	//	LCKK(bit16) This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.


	//	LOCK key writing sequence:
	//	Write 1
	GPIOx->LCKR |= (1<<16);
	//	Write 0
	GPIOx->LCKR &= ~(1<<16);
	//	Write 1
	GPIOx->LCKR |= (1<<16);
	//	Read 0
	temp = GPIOx->LCKR;
	//	Read 1 (this read is optional but confirms that the lock is active)
	temp  =  GPIOx->LCKR;
	if(temp & (1<<16)) // LCKK is one so Lock is active
		return OK; // return ok when active

	return NOK;	// return NOK if not active


}
