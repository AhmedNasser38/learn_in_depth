/*
 * EXT_INT.c
 *
 * Created: 7/29/2022 11:54:10 PM
 *  Author: Ahmed Nasser
 */ 
#include "EXT_INT.h"
#include "../../LIB/BitMath.h"

#define NULL  0
/**GLOBAL POINTER TO FUNCTION**/
static void (*Gpfunc0)(void)=NULL;
static void (*Gpfunc1)(void)=NULL;
static void (*Gpfunc2)(void)=NULL;


void GI_ENABLE(void){
	
	SetBit(SREG,GI_ENABLE_Pin);
}

void GI_DISABLE(void){
	
	ClearBit(SREG,GI_ENABLE_Pin);
}

void EXT0_ENABLE(void){
	// enable General Interrupt
	GI_ENABLE();
	// enable INT0
	SetBit(GICR,GICR_INT0);
	
	// Set Mode 
	#if (INT0_Mode == Low_Level)
		ClearBit(MCUCR,MCUCR_ISC00);
		ClearBit(MCUCR,MCUCR_ISC01);
	#elif (INT0_Mode == Logical_change)
		SetBit(MCUCR,MCUCR_ISC00);
		ClearBit(MCUCR,MCUCR_ISC01);
	#elif (INT0_Mode == Falling_edge)
		ClearBit(MCUCR,MCUCR_ISC00);
		SetBit(MCUCR,MCUCR_ISC01);
	#elif (INT0_Mode == Rising_edge)
		SetBit(MCUCR,MCUCR_ISC00);
		SetBit(MCUCR,MCUCR_ISC01);
	#endif
}

void EXT1_ENABLE(void){
	// enable General Interrupt
	GI_ENABLE();
	// enable INT1
	SetBit(GICR,GICR_INT1);
	
	// Set Mode
	#if (INT1_Mode == Low_Level)
	ClearBit(MCUCR,MCUCR_ISC10);
	ClearBit(MCUCR,MCUCR_ISC11);
	#elif (INT1_Mode == Logical_change)
	SetBit(MCUCR,MCUCR_ISC10);
	ClearBit(MCUCR,MCUCR_ISC11);
	#elif (INT1_Mode == Falling_edge)
	ClearBit(MCUCR,MCUCR_ISC10);
	SetBit(MCUCR,MCUCR_ISC11);
	#elif (INT1_Mode == Rising_edge)
	SetBit(MCUCR,MCUCR_ISC10);
	SetBit(MCUCR,MCUCR_ISC11);
	#endif
}

void EXT2_ENABLE(void){
	// enable General Interrupt
	GI_ENABLE();
	// enable INT1
	SetBit(GICR,GICR_INT2);
	
	// Set Mode
	#if (INT2_Mode == Falling_edge)
	ClearBit(MCUCSR,MCUCSR_ISC2);
	#elif (INT2_Mode == Rising_edge)
	SetBit(MCUCSR,MCUCSR_ISC2);
	#endif
}

void EXT_INT_INIT(void){
	GI_ENABLE();
	if (INT0_Status == Enable)
	{
		EXT0_ENABLE();
	}
	if (INT1_Status == Enable)
	{
		EXT1_ENABLE();
	}
	if (INT2_Status == Enable)
	{
		EXT2_ENABLE();
	}
	
}

void INT0_SetCallBack(void (*pfunc)(void)){
	Gpfunc0 = pfunc;
}

void INT1_SetCallBack(void (*pfunc)(void)){
	Gpfunc1 = pfunc;
}

void INT2_SetCallBack(void (*pfunc)(void)){
	Gpfunc2 = pfunc;
}

ISR(SRC_INT0){
	if (Gpfunc0 != NULL)
	{
		Gpfunc0();
	}
}

ISR(SRC_INT1){
	if (Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}
ISR(SRC_INT2){
	if (Gpfunc2 != NULL)
	{
		Gpfunc2();
	}
}