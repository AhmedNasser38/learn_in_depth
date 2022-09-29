/*
 * stm32f103c6_RCC.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Ahmed Nasser
 */

#ifndef INC_STM32F103C6_RCC_H_
#define INC_STM32F103C6_RCC_H_


//-----------------------------
//Includes
//-----------------------------

#include "stm32f103c6.h"


/*
* ===============================================
* APIs Supported by "MCAL RCC DRIVER"
* ===============================================
*/


uint32_t MCAL_RCC_GetSys_ClkFreq(void);
uint32_t MCAL_RCC_GetHClkFreq(void);
uint32_t MCAL_RCC_GetAPB1_ClkFreq(void);
uint32_t MCAL_RCC_GetAPB2_ClkFreq(void);



#endif /* INC_STM32F103C6_RCC_H_ */
