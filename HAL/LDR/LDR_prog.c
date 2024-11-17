/*
 * LDR_prog.c
 *
 *  Created on: Mar 20, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"ADC_interface.h"

void LDR_VoidInit(void)
{
	ADC_VoidInit();
}

uint16 LDR_GetValue(void)
{
	uint16 Local_u16DigitalReading = ADC_u8GetChannelReading(0);
	return Local_u16DigitalReading;
}
