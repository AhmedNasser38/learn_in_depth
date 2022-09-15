/*
 * EXT_INT_CONFIG.h
 *
 * Created: 7/30/2022 12:43:33 AM
 *  Author: Ahmed Nasser
 */ 


#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_

#include "EXT_INT_REGs.h"

// enable Section

//available choices for Modes
#define Enable  1
#define Disable 0


// Config INTs Status
#define INT0_Status Enable
#define INT1_Status Enable
#define INT2_Status Enable

// Modes Section

//available choices for Modes
#define Low_Level		00
#define Logical_change	01
#define Falling_edge	10
#define Rising_edge		11

/*********************************************************************
 * notes															 *
 * 1) IF INTx is disabled don't care about it's mode				 *
 * 2) for INT2 : it has only two modes (Falling_edge or Rising_edge).*
 *********************************************************************/ 

// Config INTs Modes

#define INT0_Mode Logical_change
#define INT1_Mode Rising_edge
#define INT2_Mode Falling_edge

#endif /* EXT_INT_CONFIG_H_ */