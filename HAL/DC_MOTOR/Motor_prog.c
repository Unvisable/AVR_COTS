/*
 * Motor_prog.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include"STD_TYPES.h"
#include"util/delay.h"
#include"ErrType.h"
#include"Motor_cfg.h"
#include"DIO_interface.h"


void Motor_init(void)
{
	DIO_u8SetPinDirection(Motor_u8Port,Motor_u8Pin1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor_u8Port,Motor_u8Pin2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor_u8Port,Motor_u8Pin3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor_u8Port,Motor_u8Pin4,DIO_u8PIN_OUTPUT);
}

void Motor_rotateCW4Pins(void)
{
	  DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin1,LOW_M);
	  _delay_ms(25);
	  DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin2,HIGH_M);
	  _delay_ms(25);
	  DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin3,LOW_M);
	  _delay_ms(25);
	  DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin4,HIGH_M);

}
void Motor_rotateCWW4Pins(void)
{
	 DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin1,HIGH_M);
	 _delay_ms(25);
	 DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin2,LOW_M);
	 _delay_ms(25);
	 DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin3,HIGH_M);
	 _delay_ms(25);
	 DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin4,LOW_M);

}

void Motor_rotateCW(void)
{
	DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin1,HIGH_M);
	_delay_ms(25);
	DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin2,LOW_M);
	_delay_ms(25);

}
void Motor_rotateCCW(void)
{
	DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin1,LOW_M);
	_delay_ms(25);
	DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin2,HIGH_M);
    _delay_ms(25);

}
void Motor_stop(void)
{
	DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin1,LOW_M);
	DIO_u8SetPinValue(Motor_u8Port,Motor_u8Pin2,LOW_M);
}
