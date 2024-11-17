/*
 * SPI_interface.h
 *
 *  Created on: Jun 2, 2024
 *      Author: user
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterTransmit(uint8 Copy_u8Data);
void SPI_SlaveInit(void);
uint8 SPI_SlaveReceive(void);

#endif /* SPI_INTERFACE_H_ */
