/*
 * Utils.h
 *
 *  Created on: Nov 20, 2021
 *      Author: Ahmed Nasser
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_

#define SetBit(Reg,Bit)     	 (Reg |= (1<<Bit))
#define ClearBit(Reg,Bit)   	 (Reg &= ~(1<<Bit))
#define ToggleBit(Reg,Bit)  	 (Reg ^= (1<<Bit))
#define GetBit(Reg,Bit)	   		 ((Reg >> Bit) & 1)
#define RotateRight(Reg , Val)  (Reg = ((Reg >> Val) | (Reg << (8-Val))))
#define RotateLeft(RegG, Val)   (Reg = ((Reg << Val) | (Reg >> (8-Val))))

#endif /* LIB_BITMATH_H_ */
