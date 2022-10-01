/*
 * SPI_Config.h
 *
 * Created: 12/22/2021 6:47:35 PM
 *  Author: Ahmed Nasser
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/*********************************** PORT ************************************/

#define SPI_PORT   PORTB
#define SPI_DDR    DDRB
#define SPI_PORT_ID    PORTB_REG

/*********************************** ENABLE ************************************/
/*********************				Options				***********************/
			//SPI_ON									1
			//SPI_OFF									0
#define SPI_ENABLE				SPI_ON

/*********************************** MODE ************************************/
/*********************				Options				***********************/
		  //MASTER									1
		 //SLAVE									0
#define SPI_MODE				 MASTER
/*********************************** SPI_PRESCALAR ************************************/
/*********************				Options				***********************/
			  //SPI_PRESCALAR_4						0
			 //SPI_PRESCALAR_16						1
			//SPI_PRESCALAR_64						2
		   //SPI_PRESCALAR_128						3
#define SPI_PRESCALAR			SPI_PRESCALAR_128
/*********************************** SPI_DOUBLE_SPEED ************************************/
/*********************				Options				***********************/
			//SPI_DOUBLE_SPEED_MODE_OFF				0
		   //SPI_DOUBLE_SPEED_MODE_ON	 			1
#define  SPI_DOUBLE_SPEED		SPI_DOUBLE_SPEED_MODE_OFF
/*********************************** SPI_DATA_ORDER ************************************/
/*********************				Options				***********************/
			//SPI_MSB_FISRT							0
			//SPI_LSB_FISRT	 						1
#define SPI_DATA_ORDER			SPI_MSB_FISRT
/*********************************** ENABLE_SPI_INTRRUPT ************************************/
/*********************				Options				***********************/
			//SPI_INT_ON								1
			//SPI_INT_OFF								0
#define  SPI_INTRRUPT			SPI_INT_OFF
/*********************************** SPI_OPERATING_LEVEL ************************************/
/*********************				Options				***********************/
			//SPI_IDLE_HIGH							1
			//SPI_IDLE_LOW							0
#define  SPI_OPERATING_LEVEL	SPI_IDLE_LOW
/*********************************** SPI_SAMPLING_EDGE ************************************/
/*********************				Options				***********************/
			//SPI_RISING 								1
			//SPI_FALLING 								0

#define SPI_SAMPLING_EDGE		SPI_FALLING






/******************************************************************************
 *									Macros					                  *
 ******************************************************************************/

/*********************************** ENABLE ************************************/

#define SPI_ON									1
#define SPI_OFF									0

/*********************************** MODE ************************************/

#define MASTER									1
#define SLAVE									0

/*********************************** SPI_PRESCALAR ************************************/

#define  SPI_PRESCALAR_4						0x00
#define  SPI_PRESCALAR_16						0x01
#define  SPI_PRESCALAR_64						0x02
#define  SPI_PRESCALAR_128						0x03

/*********************************** SPI_DOUBLE_SPEED ************************************/

#define  SPI_DOUBLE_SPEED_MODE_OFF				0
#define  SPI_DOUBLE_SPEED_MODE_ON	 			1

/*********************************** SPI_DATA_ORDER ************************************/

#define  SPI_MSB_FISRT							0
#define  SPI_LSB_FISRT	 						1

/*********************************** ENABLE_SPI_INTRRUPT ************************************/

#define SPI_INT_ON								1
#define SPI_INT_OFF								0

/*********************************** SPI_OPERATING_LEVEL ************************************/

#define SPI_IDLE_HIGH							1
#define SPI_IDLE_LOW							0

/*********************************** SPI_SAMPLING_EDGE ************************************/

#define SPI_RISING 								1
#define SPI_FALLING 							0

#endif /* SPI_CONFIG_H_ */