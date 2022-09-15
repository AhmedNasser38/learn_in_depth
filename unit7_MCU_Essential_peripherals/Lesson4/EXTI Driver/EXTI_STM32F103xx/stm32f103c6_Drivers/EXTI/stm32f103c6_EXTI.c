/*
 * stm32f103c6_EXTI.c
 *
 *  Created on: Sep 12, 2022
 *      Author: Ahmed Nasser
 */


//======================================================
// Includes
//======================================================

#include "../Inc/stm32f103c6_EXTI.h"


//======================================================
// Generic pointers
//======================================================

void (*GPtr_IRQ_CallBack[15] )(void);

//======================================================



//======================================================
// Generic Functions
//======================================================




/**================================================================
 * @Function Name              :- Enable_NVIC
 * @brief           		   :- Enable IRQ for selected IRQ line in NVIC
 * @parameter[in]			   :- take number of Selected IRQ
 * @return value 			   :- none
 * Note                        :- none
 *================================================================ */

void Enable_NVIC(uint16_t u16IRQ){
	switch(u16IRQ)
	{
		case EXTI0:
				NVIC_IRQ6_EXTI0_Enable();
				break;

		case EXTI1:
				NVIC_IRQ7_EXTI1_Enable();
				break;
		case EXTI2:
				NVIC_IRQ8_EXTI2_Enable();
				break;
		case EXTI3:
				NVIC_IRQ9_EXTI3_Enable();
				break;
		case EXTI4:
				NVIC_IRQ10_EXTI4_Enable();
				break;
		case EXTI5:
		case EXTI6:
		case EXTI7:
		case EXTI8:
		case EXTI9:
				NVIC_IRQ23_EXTI5_9_Enable();
				break;
		case EXTI10:
		case EXTI11:
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:
				NVIC_IRQ40_EXTI10_15_Enable();
				break;
	}

}

/**================================================================
 * @Function Name              :- Disable_NVIC
 * @brief           		   :- Disable IRQ for selected IRQ line in NVIC
 * @parameter[in]			   :- take number of Selected IRQ
 * @return value 			   :- none
 * Note                        :- none
 *================================================================ */

void Disable_NVIC(uint16_t u16IRQ){

	switch(u16IRQ)
	{
		case EXTI0:
				NVIC_IRQ6_EXTI0_Disable();
				break;

		case EXTI1:
				NVIC_IRQ7_EXTI1_Disable();
				break;
		case EXTI2:
				NVIC_IRQ8_EXTI2_Disable();
				break;
		case EXTI3:
				NVIC_IRQ9_EXTI3_Disable();
				break;
		case EXTI4:
				NVIC_IRQ10_EXTI4_Disable();
				break;
		case EXTI5:
		case EXTI6:
		case EXTI7:
		case EXTI8:
		case EXTI9:
				NVIC_IRQ23_EXTI5_9_Disable();
				break;
		case EXTI10:
		case EXTI11:
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:
				NVIC_IRQ40_EXTI10_15_Disable();
				break;
	}
}


/**================================================================
 * @Function Name              :- Update_EXTI
 * @brief           		   :- Update  External Interrupt GPIOx PINy according to specified parameters
 * 									in Exit_Config_t
 * @parameter[in]			   :- pointer to structure from type (EXTI_PinConfig_t)
 * @return value 			   :- none
 * Note                        :- none
 *================================================================ */


void Update_EXTI(EXTI_PinConfig_t *EXTI_Config){

	uint8_t u8AFIO_EXTICR_Index , u8AFIO_EXTICR_Position ,u8Value=0;

	// Configure Pin as Floating input

		// declare config structure
	GPIO_PinConfig_t PinConfig;

	PinConfig.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_Pin;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;

		// pass config structure to MCAL_GPIO_Init
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinConfig);


	/********************************************************************/


	// Update PIN on AFIO as EXTI (using EXTICR[1:4] )
	u8AFIO_EXTICR_Index = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber)/4; // to get selected register  EXTICR[1:4]
	u8AFIO_EXTICR_Position =  ((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber)%4)*4;
	u8Value = (GPIO_Maping_Position(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xF);

		//clear AFIO 4Bits (specified for pin which we need to update)

	AFIO->EXTICR[u8AFIO_EXTICR_Index] &= ~(0xF << u8AFIO_EXTICR_Position);
		// Set Value to AFIO_EXTIXR[1:4] registers
	AFIO->EXTICR[u8AFIO_EXTICR_Index] |=(u8Value << u8AFIO_EXTICR_Position);


	/********************************************************************/


	// Configure the Trigger Selection bits of the Interrupt lines (EXTI_RTSR and EXTI_FTSR)
	// Clear the Two bits of registers
	EXTI->RTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	switch(EXTI_Config->Trigger_Case){
		case (EXTI_Trigger_RISING):
						EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
						break;
		case(EXTI_Trigger_FALLING):
						EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
						break;
		case(EXTI_Trigger_RISINGAndFALLING):
						EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
						EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
						break;
		default:
						break;
	}

	/********************************************************************/

	// Update Function CallBack
	GPtr_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->Ptr_IRQ_CallBack;

	/********************************************************************/

	// Enable IRQ

	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable){
		//Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		//Configure the enable and mask bits that control the NVIC IRQ channel

		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}else{
		//Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		//Configure the enable and mask bits that control the NVIC IRQ channel
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


}




//======================================================
// EXTI APIs Implementation
//======================================================



/**================================================================
 * @Function Name              :- MCAL_EXTI_GPIO_Init
 * @brief           		   :- initialize  External Interrupt GPIOx PINy according to specified parameters
 * 									in Exit_Config_t
 * @parameter[in]			   :- pointer to structure from type (EXTI_PinConfig_t)
 * @return value 			   :- none
 * Note                        :- none
 *================================================================ */


void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t  *EXTI_Config){
	Update_EXTI(EXTI_Config);
}

/**================================================================
 * @Function Name              :- MCAL_EXTI_GPIO_Denit
 * @brief           		   :- reset  External Interrupt
 * @parameter[in]			   :- none
 * @return value 			   :- none
 * Note                        :- none
 *================================================================ */

void MCAL_EXTI_GPIO_Denit(void){

	EXTI->IMR    = 0x00000000;
	EXTI->EMR    = 0x00000000;
	EXTI->RTSR   = 0x00000000;
	EXTI->FTSR   = 0x00000000;
	EXTI->SWIER  = 0x00000000;
	// This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//cleared by writing a ‘1’ into the bit.
	EXTI->PR     = 0xFFFFFFFF;

	// disable all interrupts of NVIC
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();
}

/**================================================================
 * @Function Name              :- MCAL_EXTI_GPIO_Update
 * @brief           		   :- update  External Interrupt GPIOx PINy according to specified parameters
 * 									in Exit_Config_t
 * @parameter[in]			   :- pointer to structure from type (EXTI_PinConfig_t)
 * @return value 			   :- none
 * Note                        :- none
 *================================================================ */

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t  *EXTI_Config){

	Update_EXTI(EXTI_Config);
}







//======================================================
// EXTI IRQ Handlers Implementation
//======================================================

void EXTI0_IRQHandler(void){
	// Clear register to avoid infinite loop in INT
	EXTI->PR |= (1<<EXTI0);
	// Call Function of callback
	GPtr_IRQ_CallBack[EXTI0]();



}
void EXTI1_IRQHandler(void){
	// Clear register to avoid infinite loop in INT
	EXTI->PR |= (1<<EXTI1);

	// Call Function of callback
	GPtr_IRQ_CallBack[EXTI1]();

}
void EXTI2_IRQHandler(void){
	// Clear register to avoid infinite loop in INT
	EXTI->PR |= (1<<EXTI2);

	// Call Function of callback
	GPtr_IRQ_CallBack[EXTI2]();
}

void EXTI3_IRQHandler(void){
	// Clear register to avoid infinite loop in INT
	EXTI->PR |= (1<<EXTI3);

	// Call Function of callback
	GPtr_IRQ_CallBack[EXTI3]();
}
void EXTI4_IRQHandler(void){
	// Clear register to avoid infinite loop in INT
	EXTI->PR |= (1<<EXTI4);

	// Call Function of callback
	GPtr_IRQ_CallBack[EXTI4]();
}

void EXTI9_5_IRQHandler(void){
	// determine the ISR Number from 9 to 5
	if(EXTI->PR & (1<<EXTI5)){EXTI->PR |= (1<<EXTI5);	GPtr_IRQ_CallBack[EXTI5]();}
	if(EXTI->PR & (1<<EXTI6)){EXTI->PR |= (1<<EXTI6);	GPtr_IRQ_CallBack[EXTI6]();}
	if(EXTI->PR & (1<<EXTI7)){EXTI->PR |= (1<<EXTI7);	GPtr_IRQ_CallBack[EXTI7]();}
	if(EXTI->PR & (1<<EXTI8)){EXTI->PR |= (1<<EXTI8);	GPtr_IRQ_CallBack[EXTI8]();}
	if(EXTI->PR & (1<<EXTI9)){EXTI->PR |= (1<<EXTI9);	GPtr_IRQ_CallBack[EXTI9]();}
}
void EXTI15_10_IRQHandler(void){
	// determine the ISR Number from 15 to 10
	if(EXTI->PR & (1<<EXTI10)){EXTI->PR |= (1<<EXTI10);	GPtr_IRQ_CallBack[EXTI10]();}
	if(EXTI->PR & (1<<EXTI11)){EXTI->PR |= (1<<EXTI11);	GPtr_IRQ_CallBack[EXTI11]();}
	if(EXTI->PR & (1<<EXTI12)){EXTI->PR |= (1<<EXTI12);	GPtr_IRQ_CallBack[EXTI12]();}
	if(EXTI->PR & (1<<EXTI13)){EXTI->PR |= (1<<EXTI13);	GPtr_IRQ_CallBack[EXTI13]();}
	if(EXTI->PR & (1<<EXTI14)){EXTI->PR |= (1<<EXTI14);	GPtr_IRQ_CallBack[EXTI14]();}
	if(EXTI->PR & (1<<EXTI15)){EXTI->PR |= (1<<EXTI15);	GPtr_IRQ_CallBack[EXTI15]();}
}
