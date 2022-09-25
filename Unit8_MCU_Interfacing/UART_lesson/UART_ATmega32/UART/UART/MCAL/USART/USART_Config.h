/*
 * USART_Config.h
 *
 * Created: 2/25/2022 7:51:17 PM
 *  Author: Ahmed Nasser
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/*************** Frequency of CPU configuration *************/

#define F_CPU			8000000UL

/*************** USART Mode configuration *************/

/*
			Select USART Mode
options :
			0->asynchronous
			1->synchronous [if you choose it you don't forget conncect XCK Pin ]
			
*/
#define  USART_MODE  asynchronous


/*************** Frame configuration *************/

/*
			Select USART Data_bits Number
options :
			5->	bits_5
			6-> bits_6
			7->	bits_7
			8-> bits_8
			9->	bits_9
*/
#define  Data_bits_Num  bits_8
/*
			Select USART Parity_bits Mode
options :
			0->	Disable	(No parity bit)
			2-> Enable_even parity 
			3-> Enable_odd parity 
*/
#define  Parity_MODE  Disable

/*
			Select USART stop_bits Number
options :
			1->	bits_1
			2-> bits_2
		
*/
#define  Stop_bits_Num  bits_1



/*************** Speed & Baudrate configuration *************/
/*
	options :
				0-> normal_speed
				1-> double_speed
*/
#define  speed_mode      normal_speed

/*
	options :
				please check tables (68:71)
*/
#define  Baud_rate      9600


/*************** multi_communication configuration *************/

/*
	options :
				0-> Disable
				1-> Enable

*/
#define  multi_communication_mode      Disable



/*************** Interrupts configuration *************/

/*  Interrupts settings
	options 
			0-> Disable
			1-> Enable
*/


// ENABLE Interrupt when data is completely received
#define   RX_Complete_Interrupt			Disable

// ENABLE Interrupt when data is completely transmitted
#define   TX_Complete_Interrupt			Disable

// ENABLE Interrupt when data is completely received or transmitted (UDR is Empty)
#define   UDR_Empty_Interrupt			Disable


/*************** Clock Parity configuration *************/

/*  Clock Parity for synchronous settings
	options 
			0 ->  Rising XCK Edge on Tx and Falling XCK Edge on Rx
			1 ->  Falling XCK Edge on Tx and Rising XCK Edge on Rx
*/
#define Clock_parity   Rising_edge

/********************************************************/
/*************** End configuration  Section *************/
/********************************************************/



/***********************************************************/
/*************** Start Generic Macros  Section *************/
/***********************************************************/

/*************** This Section mustn't be changed *************/

// Mode
#define		asynchronous			0
#define		synchronous				1

// Frame
// data bits
#define		bits_5					5
#define		bits_6					6
#define		bits_7					7
#define		bits_8					8
#define		bits_9					9

// parity
#define		Disable					0
#define		Enable_even				2
#define		Enable_odd				3

// Stop bits
#define		bits_1					1
#define		bits_2					2

//Speed
#define		normal_speed			0
#define		double_speed			1

#define		Disable					0
#define		Enable					1

#define		Rising_edge				0
#define		Falling_edge			1
/*********************************************************/
/*************** End Generic Macros  Section *************/
/*********************************************************/


#endif /* USART_CONFIG_H_ */