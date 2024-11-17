/*
 * Stepper_interace.h
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef enum{
	STP_CW=1u,STP_CCW=2u
}STP_Direction;

typedef struct{
	STP_Direction STP_u8DIR;
	uint8 STP_port;
	uint8 STP_BlueWire;
	uint8 STP_PinkWire;
	uint8 STP_YellowWire;
	uint8 STP_OrangeWire;
}STP_Config_t;


uint8 STP_u8Rotate(const STP_Config_t* STP_obj, STP_Direction STP_u8DIR,uint16 Copy_u16Angle);
void STP_u8Stop(const STP_Config_t* STP_obj);

#endif /* STEPPER_INTERFACE_H_ */
