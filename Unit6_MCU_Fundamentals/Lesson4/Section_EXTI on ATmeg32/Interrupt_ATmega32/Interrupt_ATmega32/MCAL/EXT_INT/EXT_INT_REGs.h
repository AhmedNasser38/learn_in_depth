/*
 * EXT_INT_REGs.h
 *
 * Created: 7/30/2022 12:17:19 AM
 *  Author: Ahmed Nasser
 */ 


#ifndef EXT_INT_REGS_H_
#define EXT_INT_REGS_H_

#include "../Memory_Map/ATmega32.h"
#include "../DIO/DIO.h"


// MCUCR
typedef enum {
	MCUCR_ISC00,
	MCUCR_ISC01,
	MCUCR_ISC10,
	MCUCR_ISC11,
	MCUCR_SM0,
	MCUCR_SM1,
	MCUCR_SM2,
	MCUCR_SE
} enumMCUCR_Bits_ID;

// MCUCSR
typedef enum {
	MCUCSR_PORF,
	MCUCSR_EXTREF,
	MCUCSR_BORF,
	MCUCSR_WDRF,
	MCUCSR_JTRF,
	MCUCSR_RESERVED,
	MCUCSR_ISC2,
	MCUCSR_JTD
} enumMCUCSR_Bits_ID;

// GIFR
typedef enum {
	GIFR_RESERVED0,
	GIFR_RESERVED1,
	GIFR_RESERVED2,
	GIFR_RESERVED3,
	GIFR_RESERVED4,
	GIFR_INTF2,
	GIFR_INTF0,
	GIFR_INTF1
} enumGIFR_Bits_ID;

// GICR
typedef enum {
	GICR_IVCE,
	GICR_IVSEL,
	GICR_RESERVED0,
	GICR_RESERVED1,
	GICR_RESERVED2,
	GICR_INT2,
	GICR_INT0,
	GICR_INT1
} enumGICR_Bits_ID;

//SREG

#define  GI_ENABLE_Pin    7

// Vector Table

#define SRC_Address(...) (0X000 + ((__VA_ARGS__)-1)*2)

#define	SRC_RESET				__vector_0
#define	SRC_INT0				__vector_1
#define	SRC_INT1				__vector_2
#define	SRC_INT2				__vector_3
#define	SRC_TIMER2_COMP			__vector_4
#define	SRC_TIMER2_OVF			__vector_5
#define	SRC_TIMER1_CAPT			__vector_6
#define	SRC_TIMER1_COMPA		__vector_7
#define	SRC_TIMER1_COMPB		__vector_8
#define	SRC_TIMER1_OVF			__vector_9
#define	SRC_TIMER0_COMP			__vector_10
#define	SRC_TIMER0_OVF			__vector_11
#define	SRC_STC					__vector_12
#define	SRC_RXC					__vector_13
#define	SRC_UDRE				__vector_14
#define	SRC_TXC					__vector_15
#define	SRC_ADC					__vector_16
#define	SRC_EE_RDY				__vector_17
#define	SRC_ANA_COMP			__vector_18
#define	SRC_TWI					__vector_29
#define	SRC_SPM_RDY				__vector_20



#endif /* EXT_INT_REGS_H_ */