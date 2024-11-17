/*
 * SWITCH_PROG.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include"SWITCH_INTERFACE.h"

uint8 SWITCH_u8GET_STATUE(const SWITCH_CONFIG_t * Ptr_u8CopyConfig,uint8 * Copy_u8PState)
{
	uint8 Local_u8ErrorState=OK;
	uint8 Local_u8PinRead=0u;
	if(Ptr_u8CopyConfig !=NULL &&  Copy_u8PState !=NULL)
	{
		if(Ptr_u8CopyConfig->SWITCH_u8TYPE == PULL_UP)
		{
			DIO_u8SetPinValue(Ptr_u8CopyConfig->SWITCH_u8PORT,Ptr_u8CopyConfig->SWITCH_u8PIN,DIO_u8PIN_HIGH);
			DIO_u8ReadPinValue(Ptr_u8CopyConfig->SWITCH_u8PORT,Ptr_u8CopyConfig->SWITCH_u8PIN,&Local_u8PinRead);
			if(Local_u8PinRead == DIO_u8PIN_LOW)
			{
				* Copy_u8PState= PRESSED;
			}
			else if(Local_u8PinRead == DIO_u8PIN_HIGH)
			{
				* Copy_u8PState= RELEASED;
			}
			else
			{
				Local_u8ErrorState=NOK;
			}
		}
		else if(Ptr_u8CopyConfig->SWITCH_u8TYPE == PULL_DOWN)
		{
			DIO_u8SetPinValue(Ptr_u8CopyConfig->SWITCH_u8PORT,Ptr_u8CopyConfig->SWITCH_u8PIN,DIO_u8PIN_LOW);
			DIO_u8ReadPinValue(Ptr_u8CopyConfig->SWITCH_u8PORT,Ptr_u8CopyConfig->SWITCH_u8PIN,&Local_u8PinRead);
			if(Local_u8PinRead == DIO_u8PIN_HIGH)
			{
				* Copy_u8PState= PRESSED;
			}
			else if(Local_u8PinRead == DIO_u8PIN_LOW)
			{
				* Copy_u8PState= RELEASED;
			}
			else
			{
				Local_u8ErrorState=NOK;
			}
		}

	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
	return Copy_u8PState;
}
