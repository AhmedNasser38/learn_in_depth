/*
 * SPI.h
 *
 *  Created on: Dec 17, 2021
 *      Author: Ahmed Nasser
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

/******************************************************************************
 *									INCLUDES				                  *
 ******************************************************************************/
#include "../Memory_Map/ATmega32.h"
#include "SPI_Config.h"






/******************************************************************************
 *									APIS				                      *
 ******************************************************************************/

/**======================================================================
 * @Function 	 :	-SPI_Init
 * @brief   	 :	-Initializes MCU according to SPI_Config.h
 * @parameter[in]:  -None
 * @return value :	-None
 * Note 		 :	-
 */
void SPI_Init(void);

/**======================================================================
 * @Function 	 :	-SPI_SendReceive
 * @brief   	 :	-Transmitting and receiving data between Master to Slave
 * @parameter[in]:  -unsigned char data
 * @return value :	-unsigned char "Content of SPDR which contains data(input) "
 * Note 		 :	-
 */
unsigned char SPI_SendReceive(unsigned char data);

/**======================================================================
 * @Function 	 :	-SPI_Send
 * @brief   	 :	-Transmitting data 
 * @parameter[in]:  -unsigned char data
 * @return value :	-void
 * Note 		 :	-
 */
void SPI_Send(unsigned char data);

/**======================================================================
 * @Function 	 :	-SPI_Receive
 * @brief   	 :	-Receiving data from Master to Slave
 * @parameter[in]:  -void
 * @return value :	-unsigned char "Content of SPDR which contains data(input) "
 * Note 		 :	-
 */
unsigned char SPI_Receive(void);

/**======================================================================
 * @Function 	 :	-SPI_Checks_for_collision
 * @brief   	 :	-check if collision occur (written on the SPDR while transmitting)
 * @parameter[in]:  -void
 * @return value :	-unsigned char "status of WCOL pin in SPSR register "
 * Note 		 :	-
 */
unsigned char SPI_Checks_for_collision(void);

#endif /* MCAL_SPI_SPI_H_ */