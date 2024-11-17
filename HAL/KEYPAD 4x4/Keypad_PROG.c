/*
 * Keypad_PROG.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */
#include"STD_TYPES.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include"Keypad_INTERFACE.h"
#include"Keypad_PRV.h"
#include"Keypad_CFG.h"

uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8ColIdx, Local_u8RowIdx, Local_u8PinState, Local_u8PressedKey = KPD_u8NO_PRESSED_KEY_VAL;

	uint8 Local_au8ColArr[COL_NUM] = {KPD_u8COL0_PIN,KPD_u8COL1_PIN,KPD_u8COL2_PIN,KPD_u8COL3_PIN};

	uint8 Local_au8RowArr[ROW_NUM] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};

	uint8 Local_au8KPDArr[ROW_NUM][COL_NUM] = KPD_au8_BUTTON_ARR;

	/*Activate the column pins*/
	for(Local_u8ColIdx=0u; Local_u8ColIdx < COL_NUM ; Local_u8ColIdx++)
	{
		/*Activate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_PORT,Local_au8ColArr[Local_u8ColIdx], DIO_u8PIN_LOW);

		/*Read the row pins*/
		for(Local_u8RowIdx = 0u; Local_u8RowIdx < ROW_NUM; Local_u8RowIdx++)
		{
			/*Read the current row*/
			DIO_u8ReadPinValue(KPD_u8ROW_PORT, Local_au8RowArr[Local_u8RowIdx], &Local_u8PinState);

			if(Local_u8PinState == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey = Local_au8KPDArr[Local_u8RowIdx][Local_u8ColIdx];

				/*Polling with blocking(waiting) until the key is released*/
				while(Local_u8PinState == DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KPD_u8ROW_PORT, Local_au8RowArr[Local_u8RowIdx], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}

		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_PORT,Local_au8ColArr[Local_u8ColIdx], DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}

uint8 Keypad4x4()
{
	uint8 Local_u8keyPressed,Local_u8KeyPressedDismal=0,Local_u8ErrorState=OK;

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
	default: Local_u8ErrorState=NOK; break;
	}
	return Local_u8KeyPressedDismal;
}

