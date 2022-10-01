/*
 * SPI_HW.H
 *
 *  Created on: Dec 19, 2021
 *      Author: Ahmed Nasser
 */

#ifndef MCAL_SPI_SPI_HW_H_
#define MCAL_SPI_SPI_HW_H_



//SPI Control Register – SPCR
//SPR1, SPR0: SPI Clock Rate Select 1 and 0
#define SPR0			0
#define SPR1			1
//CPHA: Clock Phase
#define CPHA			2
//CPOL: Clock Polarity
#define CPOL			3
// MSTR: Master/Slave Select
#define MSTR			4
//DORD: Data Order
#define DORD			5
//SPE: SPI Enable
#define SPE				6
//SPIE: SPI Interrupt Enable
#define SPIE			7

//SPI Status Register – SPSR
//SPI2X: Double SPI Speed Bit
#define SPI2X			0
// Bit 5..1 – Reserved Bits
//WCOL: Write Collision Flag
#define WCOL			6
//SPIF: SPI Interrupt Flag
#define SPIF			7

#endif /* MCAL_SPI_SPI_HW_H_ */
