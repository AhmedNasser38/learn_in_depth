/*
 * USART.h
 *
 * Created: 2/25/2022 1:09:40 AM
 *  Author: Ahmed Nasser
 */ 


#ifndef USART_H_
#define USART_H_
#include "../Memory_Map/ATmega32.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BitMath.h"
#include "USART_Config.h"



// UCSRA_Bits
#define RXC    7
#define TXC    6
#define UDRE   5
#define FE     4
#define DOR    3
#define PE     2
#define U2X    1
#define MPCM   0
//UCSRB_Bits

#define RXCIE    7
#define TXCIE    6
#define UDRIE    5
#define RXEN     4
#define TXEN     3
#define UCSZ2    2
#define RXB8     1
#define TXB8     0

//UCSRC_Bits


#define URSEL    7
#define UMSEL    6
#define UPM1     5
#define UPM0     4
#define USBS     3
#define UCSZ1    2
#define UCSZ0    1
#define UCPOL    0



#define  Stop_ch    '\r'   // hex of enter in Keyboard
//prototype
void USART_Init(void);

 void USART_Send_char(uint8 Data);

uint8 USART_Recieve_char(void);

void USART_Send_str(uint8* str);
void USART_Recieve_str(uint8* Buffer);
void USART_Send_Integer(uint32 Data);
uint32 USART_Recieve_Integer(void);
uint8 USART_Recieve_PeriodicCheck(uint8* Data);
void USART_Send_str_Async(uint8* str);


#endif /* USART_H_ */