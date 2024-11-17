/*
 * Servo_Interface.h
 *
 *  Created on: May 7, 2024
 *      Author: Omar khaled
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_
#include"STD_TYPES.h"
#include"ErrType.h"
#include"util/delay.h"
#include"BIT_MATH.h"
#include "Servo_prv.h"
#include"Timers_reg.h"
void Servo_voidInit(void);

uint16 Calculate_u16PWM(sint8 Copy_su8Angle);
/* Function to move the servo smoothly to the desired angle using channel A portd pin 5*/
void Servo_A_GO(sint8 Copy_su8Angle);
/* Function to move the servo smoothly to the desired angle using channel B portd pin 4*/
void Servo_B_GO(sint8 Copy_su8Angle);


#endif /* SERVO_INTERFACE_H_ */
