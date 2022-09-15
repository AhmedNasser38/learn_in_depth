/*
 * ATmega32_DIO.h
 *
 *  Created on: Nov 11, 2021
 *      Author: Ahmed Nasser
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

/******************************************************************************
*									INCLUDES				                  *
*******************************************************************************/
#include "../Memory_Map/ATmega32.h"
#include "../../LIB/BitMath.h"
#include "DIO_Types.h"

/******************************************************************************
*									APIS				                      *
*******************************************************************************/

				/*****************************************
				 *				   PORTS				 *
				 *****************************************/

/**======================================================================
 * @Function 	 :	-DIO_Set_DDR_PORT
 * @brief   	 :	-Write a data direction to the given port  may be OUTPUT 1 OR INPUT 0
 * @parameter[in]:  -PORT: PORT may be (PORTB_REG, PORTC_REG , PORTD_REG) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -DDR: the direction we want to make the whole port( may be OUTPUT 1 or INPUT 0)
 * @return value :	-None
 * Note 		 :	- We can use PORT direct to do this function job
 * 							example : PORTB = 0xFF; >> whole Port is out put
 * 									: PORTB = 0x0F; >> make first 4bits output and last 4-bits input
 */
void DIO_Set_DDR_PORT(DIO_PORT_ID PORT , DIO_Direction DDR);

/**======================================================================
 * @Function 	 :	-DIO_Set_PORT
 * @brief   	 :	-Write a value at the given port  in range (0x00 : 0xFF)
 * @parameter[in]:  -PORT: PORT may be (PORTB_REG, PORTC_REG , PORTD_REG) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -value: the value we want to write to the port [0x00 : 0xFF]
 * @return value :	-None
 * Note 		 :	-We can use PORT direct to do this function job
 * 							example : PORTB = 0xFF;
 * 									: PORTB = value;
 */
void DIO_Set_PORT(DIO_PORT_ID PORT , unsigned char value);

				/*****************************************
				 *				   PINS					 *
				 *****************************************/
/**======================================================================
 * @Function 	 :	-DIO_Set_DDR_PIN
 * @brief   	 :	-Write a data direction to the given pin  may be OUTPUT 1 OR INPUT 0
 * @parameter[in]:  -PORT: PORT may be (PORTB_REG, PORTC_REG , PORTD_REG) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -PIN:  PIN Which we want to Read may be between (0:7) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -DDR: the direction we want to make the pin may be OUTPUT 1 or INPUT 0
 * @return value :	-None
 * Note 		 :	-
 */
void DIO_Set_DDR_PIN(DIO_PORT_ID PORT , DIO_PIN_ID PIN , DIO_Direction DDR);

/**======================================================================
 * @Function 	 :	-DIO_Set_PIN
 * @brief   	 :	-Write a value at the given pin  may be HIGH 1 OR LOW 0
 * @parameter[in]:  -PORT: PORT may be (PORTB_REG, PORTC_REG , PORTD_REG) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -PIN:  PIN Which we want to Read may be between (0:7) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -value: the value we want to write to the pin may be 1 or 0
 * @return value :	-None
 * Note 		 :	-
 */
void DIO_Set_PIN(DIO_PORT_ID PORT , DIO_PIN_ID PIN , unsigned char value);

/**======================================================================
 * @Function 	 :	-DIO_Get_PIN
 * @brief   	 :	-Read the value at the given pin (Out may be HIGH 1 OR LOW 0)
 * @parameter[in]:  -PORT: PORT may be (PORTB_REG, PORTC_REG , PORTD_REG) or any equivalent macro from DIO_Types.h file
 * @parameter[in]:  -PIN:  PIN Which we want to Read may be between (0:7) or any equivalent macro from DIO_Types.h file
 * @return value :	-Value of the pin (1 or 0)
 * Note 		 :	-
 */
DIO_Value DIO_Get_PIN(DIO_PORT_ID PORT , DIO_PIN_ID PIN);

#endif /* MCAL_DIO_DIO_H_ */
