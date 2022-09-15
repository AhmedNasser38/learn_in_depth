/*
 * EXT_INT.h
 *
 * Created: 7/29/2022 11:53:09 PM
 *  Author: Ahmed Nasser
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_


#include "EXT_INT_CONFIG.h"

#define ISR(VECT_NUM)         void  VECT_NUM  (void) __attribute__((signal));\
							  void  VECT_NUM  (void)


void GI_ENABLE(void);

void GI_DISABLE(void);

void EXT_INT_INIT(void);

void EXT0_ENABLE(void);

void EXT1_ENABLE(void);

void EXT2_ENABLE(void);

void INT0_SetCallBack(void (*pfunc)(void));

void INT1_SetCallBack(void (*pfunc)(void));

void INT2_SetCallBack(void (*pfunc)(void));



							

#endif /* EXT_INT_H_ */