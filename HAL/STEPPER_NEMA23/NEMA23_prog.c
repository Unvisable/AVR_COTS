/*
 * NEMA23_prog.c
 *
 *  Created on: May 16, 2024
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "Port_interface.h"
#include "DIO_interface.h"
#include "NEMA23_Cfg.h"
#include "NEMA23_interface.h"



void STP_Init(void)
{
	DIO_u8SetPinDirection(STP_PORT,STEP_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(STP_PORT,DIR_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(STP_PORT,ENABLE_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(STP_PORT,RESET_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinDirection(STP_PORT,SLEEP_PIN,DIO_u8PIN_HIGH);

	DIO_u8SetPinValue(STP_PORT,ENABLE_PIN,DIO_u8PIN_LOW);/*To Enable the driver*/
	DIO_u8SetPinValue(STP_PORT,RESET_PIN,DIO_u8PIN_HIGH);/*To Enable the driver*/
	DIO_u8SetPinValue(STP_PORT,SLEEP_PIN,DIO_u8PIN_HIGH);/*To Enable the driver*/
}

void STP_Rotate(uint16 Copy_u16Steps, uint8 Copy_u8Dir)
{

  if(Copy_u8Dir == 1)
  {
	  DIO_u8SetPinValue(STP_PORT,DIR_PIN,DIO_u8PIN_HIGH);
  }
  else if(Copy_u8Dir == 0)
  {
	  DIO_u8SetPinValue(STP_PORT,DIR_PIN,DIO_u8PIN_LOW);
  }

  //DIO_u8SetPinDirection(STP_PORT,ENABLE_PIN,DIO_u8PIN_LOW);


  // Step the motor
      for (int i = 0; i < Copy_u16Steps; i++) {
    	  DIO_u8SetPinDirection(STP_PORT,STEP_PIN,DIO_u8PIN_HIGH); /* Step Pulse*/
          _delay_us(STEP_DELAY);
          DIO_u8SetPinDirection(STP_PORT,STEP_PIN,DIO_u8PIN_LOW); /*Step Pulse*/
          _delay_us(STEP_DELAY);
      }

      //DIO_u8SetPinDirection(STP_PORT,ENABLE_PIN,DIO_u8PIN_HIGH);


}

