/*
 * SPI_prog.c
 *
 *  Created on: Jun 2, 2024
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_reg.h"
#include "SPI_interface.h"

void SPI_MasterInit(void)
{
	/*Set MOSI , SCK and SS as Output , MISO as Input Floating*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_OUTPUT); /*SS*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_OUTPUT); /*MOSI*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_INPUT); /*MISO*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_OUTPUT); /*SCK*/

	/*Set Master , Enable SPI , Set Clock Rate Fosc/16*/
	SET_BIT(SPCR,SPCR_SPE);
	SET_BIT(SPCR,SPCR_MSTR);
	SET_BIT(SPCR,SPCR_SPR0);

	/*Set Pin to control SS in Slave microcontroller*/
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_OUTPUT); /*PORTC Pin 7*/
	/*Deselect the slave*/
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
}
void SPI_SlaveInit(void)
{
	/*Set MOSI , SCK and SS as INPUT , MISO as OUTPUT*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_INPUT); /*SS*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_INPUT); /*MOSI*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_OUTPUT); /*MISO*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_INPUT); /*SCK*/

	/*Set Slave , Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
	CLR_BIT(SPCR,SPCR_MSTR);
}
void SPI_MasterTransmit(uint8 Copy_u8Data)
{
    /*Set the controlled pin SS to Logic Zero*/
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
	/*Write the data inside the register SPDR*/
	SPDR = Copy_u8Data;
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	/*Deselect the slave*/
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);

}

uint8 SPI_SlaveReceive(void)
{
  /*Wait Until the data recieved*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	return SPDR;
}
