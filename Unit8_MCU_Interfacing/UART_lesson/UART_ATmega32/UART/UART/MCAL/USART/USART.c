/*
 * USART.c
 *
 * Created: 2/25/2022 1:09:23 AM
 *  Author: Ahmed Nasser
 */ 
#include "USART.h"


static uint8* Tx_str;
static uint8 Send_Flag = 1;







/**======================================================================
 * @Function Name	:- USART_Init
 * @brief   		:- Initialize USART according to Configurations on "USART_Config.h" file
 * @return value	:- None
 * Note 			:- None
 */

void USART_Init(void){
	
	uint16  UBRR_value =0;
	
	
	// setting the baud rate, setting frame format and enabling the
	//Transmitter or the Receiver depending on the usage.
	
	
	
			// mode 
	
	#if USART_MODE == synchronous
	
	SetBit(UCSRC,UMSEL); // Synchronous_mode
	 UBRR_value = (F_CPU / ( (uint64) 2 * Baud_rate) )-1 ;

	#else
	ClearBit(UCSRC,UMSEL); // ASynchronous_mode "default"
	
	#endif
	
	
// Speed & Baud rate

	#if speed_mode == double_speed
	SetBit(UCSRA,U2X);
	UBRR_value =  (F_CPU / ( (uint64) 8 * Baud_rate) )-1; 
	#else
	ClearBit(UCSRA,U2X);
	UBRR_value =  (F_CPU / ( (uint64) 16 * Baud_rate) )-1; 
	#endif
	
	//set Baud_rate
	
	
	UBRRL = (uint8)UBRR_value;
	ClearBit(UCSRC,URSEL); // to enable writing to UBRRH_reg "default"
	UBRRH = (uint8)(UBRR_value >> 8);
	
	SetBit(UCSRC,URSEL); // to enable writing to UCSRC_reg "default"*/


	// frame for ASynchronous mode only
//the number of data bits
	#if	Data_bits_Num == bits_5
		ClearBit(UCSRC,UCSZ0);
		ClearBit(UCSRC,UCSZ1);
		ClearBit(UCSRB,UCSZ2);
	
	#elif  Data_bits_Num == bits_6
		SetBit(UCSRC,UCSZ0);
		ClearBit(UCSRC,UCSZ1);
		ClearBit(UCSRB,UCSZ2);
	#elif  Data_bits_Num == bits_7
		ClearBit(UCSRC,UCSZ0);
		SetBit(UCSRC,UCSZ1);
		ClearBit(UCSRB,UCSZ2);
	#elif  Data_bits_Num == bits_9
		SetBit(UCSRC,UCSZ0);
		SetBit(UCSRC,UCSZ1);
		SetBit(UCSRB,UCSZ2);
	//8bit"default"
	#else
		SetBit(UCSRC,UCSZ0);
		SetBit(UCSRC,UCSZ1);
		ClearBit(UCSRB,UCSZ2);

	#endif

//	parity bits
	#if  Parity_MODE == Enable_odd
		
		SetBit(UCSRC,UPM0);
		SetBit(UCSRC,UPM1);
	#elif Parity_MODE == Enable_even
		
		ClearBit(UCSRC,UPM0);
		SetBit(UCSRC,UPM1);
		
	#else
		ClearBit(UCSRC,UPM0);
		ClearBit(UCSRC,UPM1);

	#endif
	
// number of stop_bits
	#if Stop_bits_Num == bits_2
		SetBit(UCSRC, USBS);
	#else
		ClearBit(UCSRC, USBS);
	#endif
	
// Interrupts 
	#if RX_Complete_Interrupt == Enable
		SetBit(UCSRB,RXCIE);
	#else
		ClearBit(UCSRB,RXCIE);
	#endif

	#if TX_Complete_Interrupt == Enable
	SetBit(UCSRB,TXCIE);
	#else
	ClearBit(UCSRB,TXCIE);
	#endif

	#if UDR_Empty_Interrupt == Enable
	SetBit(UCSRB,UDRIE);
	#else
	ClearBit(UCSRB,UDRIE);
	#endif

// Multi-processor Communication Mode
	#if multi_communication_mode == Enable
		SetBit(UCSRA,MPCM);
	#else
		ClearBit(UCSRA,MPCM);
	#endif

// set clock parity for only synchronous
	#if Clock_parity == Falling_edge
	SetBit(UCSRC,UCPOL);
	#else
	ClearBit(UCSRC,UCPOL);
	#endif

// Enable transmitter and receiver
	SetBit(UCSRB,TXEN);
	SetBit(UCSRB,RXEN);	
}


/**======================================================================
 * @Function Name	:- USART_Send_char
 * @brief   		:- Send character via TX pin 
 * @parameter[in]	:- Data: represent the character bing to send
 * @return value	:- None
 * Note 			:- None
 */

void USART_Send_char(uint8 Data){
	
	// wait to end current transmission 
	while(!GetBit(UCSRA,UDRE));
	// send data 
	UDR = Data;
}

/**======================================================================
 * @Function Name	:- USART_Recieve_char
 * @brief   		:- Receive character via RX pin 
 * @return value	:- UDR register value from type ( unsigned char )
 * Note 			:- None
 */

uint8 USART_Recieve_char(void){
	
	// wait to read all data in buffer
	while(!GetBit(UCSRA,RXC));
	// return UDR (received data)
	return UDR;
}

/**======================================================================
 * @Function Name	:- USART_Send_str
 * @brief   		:- Send String via TX pin Character by character
 * @parameter[in]	:- str: Pointer to first character in the String
 * @return value	:- None.
 * Note 			:- the end of USART transmission string is stop char @"USART_Config.h" file
						it blocks CPU until it Send all String
 */

void USART_Send_str(uint8* str){
	uint8 i ;
	for (i=0 ; i<str[i];i++)
	{
		USART_Send_char(str[i]);
	}
	
	USART_Send_char(Stop_ch);
}

/**======================================================================
 * @Function Name	:- USART_Recieve_str
 * @brief   		:- Receive String via RX pin Character by character
 * @parameter[in]	:- str: Pointer to first location in the Buffer String
 * @return value	:- None.
 * Note 			:- it blocks CPU until it receive all String
 */

void USART_Recieve_str(uint8* Buffer){
	uint8 i=0;
	
	Buffer[i]=USART_Recieve_char();
	// do....while
	while (Buffer[i] != Stop_ch)
	{
		i++;
		Buffer[i]=USART_Recieve_char();
	}
	Buffer[i]='\0';	
}




void USART_Send_Integer(uint32 Data){
	
	uint8* Ptr_char = (uint8*) &Data;

	USART_Send_char(Ptr_char[0]); // Send first byte
	USART_Send_char(Ptr_char[1]); // Send 2nd byte
	USART_Send_char(Ptr_char[2]); // Send 3rd byte
	USART_Send_char(Ptr_char[3]); // Send 4th byte
}

uint32 USART_Recieve_Integer(void){
	uint32 Data = 0;
	
	uint8* Ptr_char = (uint8*) &Data;

	Ptr_char[0] = USART_Recieve_char();
	Ptr_char[1] = USART_Recieve_char();
	Ptr_char[2] = USART_Recieve_char();
	Ptr_char[3] = USART_Recieve_char();
	
	return Data;
}



/**======================================================================
 * @Function Name	:- USART_Recieve_str
 * @brief   		:- Receive String via RX pin Character by character
 * @parameter[in]	:- str: Pointer to first location in the Buffer String
 * @return value	:- None.
 * Note 			:- periodic check receive without stacking CPU
					:- **** must be delay more than 200ms to avoid over run data 
 */


uint8 USART_Recieve_PeriodicCheck(uint8* Data){
	if (GetBit(UCSRA,RXC))
	{
		*Data = UDR;
		return	1;
	}
	return	0;
	
}

void USART_SendNoblock(uint8 Data){

	UDR = Data;	
}
uint8 USART_RecieveNoblock(void){
	return UDR;
}

void USART_TX_InterruptEnable(void){
	SetBit(UCSRB,TXCIE);
}

void USART_TX_InterruptDisable(void){
	ClearBit(UCSRB,TXCIE);
}

void USART_RX_InterruptEnable(void){
	SetBit(UCSRB,RXCIE);
}

void USART_RX_InterruptDisable(void){
	ClearBit(UCSRB,RXCIE);
}

void USART_Send_str_Async(uint8* str){
	if (Send_Flag)
	{
		USART_TX_InterruptEnable();
		USART_SendNoblock(str[0]);
		Tx_str = str;
		Send_Flag = 0;
	}
	
}


ISR(UART_TX_vect){
	static uint8 i =1 ;
	if (Tx_str[i] != 0)
	{
		USART_SendNoblock(Tx_str[i]);
		i++;
	} 
	else
	{
		i=1;
		Send_Flag =1;
	}
}