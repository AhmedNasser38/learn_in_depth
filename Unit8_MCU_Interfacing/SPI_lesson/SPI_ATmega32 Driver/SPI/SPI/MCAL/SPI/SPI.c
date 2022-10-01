/*
 * SPI.c
 *
 *  Created on: Dec 17, 2021
 *      Author: Ahmed Nasser
 */

#include "SPI.h"
#include "SPI_Config.h"
#include "../../LIB/BitMath.h"
#include "../DIO/DIO.h"

/******************************************************************
 *						Implement APIs						      *
 ******************************************************************/


void SPI_Init(void){
			/********************Enable SPI Interrupt ******************/
			// Bit 7 – SPIE: SPI Interrupt Enable	
			#if (SPI_INTRRUPT == SPI_INT_ON)
				SetBit(SPCR,SPIE);
				//if interrupt enable , we must set the global interrupt enable bit(7) in SREG
				SetBit(SREG,7);
			#elif (SPI_INTRRUPT == SPI_INT_OFF)
				ClearBit(SPCR,SPIE);
			#endif
			/*******************Data Order ******************/
			//Bit 5 – DORD: Data Order
			//When the DORD bit is written to one, the LSB of the data word is transmitted first.
			//When the DORD bit is written to zero, the MSB of the data word is transmitted first.
			#if (SPI_DATA_ORDER == SPI_LSB_FISRT)
				SetBit(SPCR,DORD);
			#elif (SPI_DATA_ORDER == SPI_MSB_FISRT)
				ClearBit(SPCR,DORD);
			#endif
			/********************Master Slave Select ******************/
			// Bit 4 – MSTR: Master/Slave Select
			//This bit selects Master SPI mode when written to one, and Slave SPI mode when written logic
			//zero
			#if (SPI_MODE == MASTER)
				SetBit(SPCR,MSTR);
				// adjust DDR for PINs
				DIO_Set_DDR_PIN(SPI_PORT_ID,SS,OUTPUT);
				DIO_Set_DDR_PIN(SPI_PORT_ID,MOSI,OUTPUT);
				DIO_Set_DDR_PIN(SPI_PORT_ID,SCK,OUTPUT);
				
				DIO_Set_DDR_PIN(SPI_PORT_ID,MISO,INPUT);
				
			#elif (SPI_MODE == SLAVE)
				ClearBit(SPCR,MSTR);
				// adjust DDR for PINs
				DIO_Set_DDR_PIN(SPI_PORT_ID,SS,INPUT);
				DIO_Set_DDR_PIN(SPI_PORT_ID,MOSI,INPUT);
				DIO_Set_DDR_PIN(SPI_PORT_ID,SCK,INPUT);
				
				DIO_Set_DDR_PIN(SPI_PORT_ID,MISO,OUTPUT);
			#endif
			/********************clock polarity******************/
			//Bit 3 – CPOL: Clock Polarity
			//When this bit is written to one, SCK is high when idle. When CPOL is written to zero, SCK is low
			//when idle.
			#if (SPI_OPERATING_LEVEL == SPI_IDLE_HIGH)
					SetBit(SPCR,CPOL);
			#elif (SPI_OPERATING_LEVEL == SPI_IDLE_LOW)
					ClearBit(SPCR,CPOL);
			#endif
			/********************clock phase******************/
			// Bit 2 – CPHA: Clock Phase
			//The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading (first) or
			//trailing (last) edge of SCK.
			#if (SPI_SAMPLING_EDGE == SPI_RISING)
				SetBit(SPCR,CPHA);
			#elif (SPI_SAMPLING_EDGE == SPI_FALLING)
				ClearBit(SPCR,CPHA);
			#endif
			/********************SPI pre-scalar in case of master ******************/
			 //Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0
			SPCR = SPCR | (SPI_PRESCALAR);
			/********************Double SPI speed if master******************/
			// Bit 0 – SPI2X: Double SPI Speed Bit
			//When this bit is written logic one the SPI speed (SCK Frequency) will be doubled when the SPI
			//is in Master mode
			#if (SPI_DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_ON)
					SetBit(SPSR,SPI2X);
			#elif (SPI_DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_OFF)
					ClearBit(SPSR,SPI2X);
			#endif
			/********************Enable SPI ******************/
			#if (SPI_ENABLE == SPI_ON)
				SetBit(SPCR,SPE);
			#elif (SPI_ENABLE == SPI_OFF)
				ClearBit(SPCR,SPE);
			#endif
}


unsigned char SPI_SendReceive(unsigned char data){
	SPDR = data;
	//check all data is transfered (SPI is not busy)
		//When a serial transfer is complete, the SPIF Flag is set. 
		//SPIF is cleared by hardware
	while(!( SPSR & (1<<SPIF) ));
	return SPDR;

}


void SPI_Send(unsigned char data){
	SPDR = data;
	//check all data is transfered (SPI is not busy)
	while(!( SPSR & (1<<SPIF) ));
	return;
}

unsigned char SPI_Receive(void){
	//check all data is transfered (SPI is not busy)
	while(!( SPSR & (1<<SPIF) ));
	return SPDR;
}

unsigned char SPI_Checks_for_collision(void){
			//Bit 6 – WCOL: Write COLlision Flag
			//The WCOL bit is set if the SPI Data Register (SPDR) is written during a data transfer. The
			//WCOL bit (and the SPIF bit) are cleared by first reading the SPI Status Register with WCOL set,
			//and then accessing the SPI Data Register.
			unsigned char collision_status = GetBit(SPSR,WCOL);
			return collision_status;
}