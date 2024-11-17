/*
 * Calculator_prog.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include"STD_TYPES.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"Keypad_INTERFACE.h"
#include"ErrType_Cal.h"
#include"Calculator_prv.h"
#include"Calculator_interface.h"


uint8 Local_u8OpCheck(uint8 CHF)
{
	if( CHF != '+' && CHF != '-' && CHF != '*' && CHF != '/' )  //if input is not from allowed funtions then show error
	    {
		  Wrong_Func;
	        return 'e';
	    }
	    return CHF;
}


uint8 Keypad4x4()
{
	uint8 Local_u8keyPressed,Local_u8KeyPressedDismal=0;

	do
	{
		Local_u8keyPressed = KPD_u8GetPressedKey();
	}while(Local_u8keyPressed == 0xff);

	switch(Local_u8keyPressed)
	{
	case(7): Local_u8keyPressed='7';Local_u8KeyPressedDismal=7;     break;
	case(8): Local_u8keyPressed='8';Local_u8KeyPressedDismal=8;     break;
	case(9): Local_u8keyPressed='9';Local_u8KeyPressedDismal=9;     break;
	case('/'): Local_u8keyPressed='/';Local_u8KeyPressedDismal='/'; break;
	case(4): Local_u8keyPressed='4';Local_u8KeyPressedDismal=4;     break;
	case(5): Local_u8keyPressed='5';Local_u8KeyPressedDismal=5;     break;
	case(6): Local_u8keyPressed='6';Local_u8KeyPressedDismal=6;     break;
	case('*'): Local_u8keyPressed='*';Local_u8KeyPressedDismal='*'; break;
	case(1): Local_u8keyPressed='1';Local_u8KeyPressedDismal=1;     break;
	case(2): Local_u8keyPressed='2';Local_u8KeyPressedDismal=2;     break;
	case(3): Local_u8keyPressed='3';Local_u8KeyPressedDismal=3;     break;
	case('-'): Local_u8keyPressed='-';Local_u8KeyPressedDismal='-'; break;
	case('C'): Local_u8keyPressed='C';Local_u8KeyPressedDismal='C'; break;
	case(0): Local_u8keyPressed='0';Local_u8KeyPressedDismal=0;     break;
	case('='): Local_u8keyPressed='=';Local_u8KeyPressedDismal='='; break;
	case('+'): Local_u8keyPressed='+';Local_u8KeyPressedDismal='+'; break;
	default: Wrong_input; break;
	}
	return Local_u8KeyPressedDismal;
}
