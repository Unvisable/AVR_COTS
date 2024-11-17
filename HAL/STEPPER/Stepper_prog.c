/*
 * Stepper_prog.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include "STD_TYPES.h"
#include "ErrType.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "Stepper_interface.h"








uint8 STP_u8Rotate(const STP_Config_t* STP_obj, STP_Direction STP_u8DIR,uint16 Copy_u16Angle)
{
	uint16 Steps = (uint16)(((uint32) Copy_u16Angle * (uint32) 2048 )/ (uint32) 360);
	uint8 Local_u8ErrorState=OK;

	uint16 i=0;

		if(STP_u8DIR==STP_CW)
		{
			for(i=0; i<Steps; i++)
			{
				if(i%4 == 0)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire, DIO_u8PIN_LOW);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
			        DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
			        _delay_ms(1);
			        DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
			        _delay_ms(1);


				}
				else if(i%4 == 1)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire, DIO_u8PIN_LOW);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
				    _delay_ms(1);
				    DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
				    _delay_ms(1);
				}
				else if(i%4 == 2)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire, DIO_u8PIN_LOW);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
				    DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire,DIO_u8PIN_HIGH);
				    _delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
				}
				else if(i%4 == 3)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire, DIO_u8PIN_LOW);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
					 _delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire,DIO_u8PIN_HIGH);
					 _delay_ms(1);
				}
			}

		}
		else if(STP_u8DIR == STP_CCW)
		{
			for(i=0; i<Steps; i++)
			{
				if(i%4 == 0)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
					 _delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire, DIO_u8PIN_LOW);
					_delay_ms(1);
				}
				else if(i%4 == 1)
				{

					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire, DIO_u8PIN_LOW);
					_delay_ms(1);
				}
				else if(i%4 == 2)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire, DIO_u8PIN_LOW);
					_delay_ms(1);
				}
				else if(i%4 == 3)
				{
					DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
					_delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
					 _delay_ms(1);
					 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
					 _delay_ms(1);
						DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire, DIO_u8PIN_LOW);
						_delay_ms(1);
				}
			}

		}
		else
		{
			Local_u8ErrorState =NOK;
		}
		return Local_u8ErrorState;
}
void STP_u8Stop(const STP_Config_t* STP_obj)
{
	DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_BlueWire, DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_PinkWire,DIO_u8PIN_HIGH);
	_delay_ms(1);
	 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_YellowWire,DIO_u8PIN_HIGH);
	 _delay_ms(1);
	 DIO_u8SetPinValue(STP_obj->STP_port, STP_obj->STP_OrangeWire,DIO_u8PIN_HIGH);
	 _delay_ms(1);

}
