/*
 * Servo_prog.c
 *
 *  Created on: May 7, 2024
 *      Author: Omar Khaled
 */
#include "Servo_Interface.h"
volatile static sint8 servoCurrentPosition = 0;
void Servo_voidInit(void)
{
  /*Setup Wave generation & Fast PWM & Prescaller division by 64*/
	/* Clear CS12 bits in TCCR1B*/
	TCCR1B &= ~(1 << TCCR1B_CS12);

	/* Set CS10 and CS11 bit in TCCR1B*/
	TCCR1B |= (1 << TCCR1B_CS10);
	TCCR1B |= (1 << TCCR1B_CS11);

	/* Clear WGM10 bit in TCCR1A*/
	TCCR1A &= ~(1 << TCCR1A_WGM10);

	/* Set WGM11 bit in TCCR1A*/
	TCCR1A |= (1 << TCCR1A_WGM11);

	/* Set WGM12, WGM13 bits in TCCR1B*/
	TCCR1B |= (1 << TCCR1B_WGM12) | (1 << TCCR1B_WGM13);

	/* Clear COM1A0, COM1B0 bits in TCCR1A*/
	TCCR1A &= ~(1 << TCCR1A_COM1A0);
	TCCR1A &= ~(1 << TCCR1A_COM1B0);

	/* Set COM1A1, COM1B1 bits in TCCR1A*/
	TCCR1A |= (1 << TCCR1A_COM1A1);
	TCCR1A |= (1 << TCCR1A_COM1B1);
	  /*Set Top value in ICR1  mode (14)*/
	  /* Desired Period time = 20000 microseconds , then period = Top value ticks * prescaler division by 8 / system frequency =16MHZ
	   * 20000 microseconds =  Top value * 0.5 , then Top value =40000*/

	/*I choose prescaller division by 64 , then Top value =5000*/
	  ICR1 = 5000;
}

/* Function to calculate PWM value based on desired angle*/
uint16 Calculate_u16PWM(sint8 Copy_su8Angle)
{
    /* Map the angle to the PWM range*/
	/*On Time = Compare value * prescaler / system frequency
	 * For angle -90 , we need at~0.52 miliseconds delay
	 * So, 0.52*1000 = Compare value * 4 , then compare value = 130
	 *For angle 0 , we need at~1.4 miliseconds delay
	 * So, 1.4*1000 = Compare value * 4 , then compare value = 350
	 * For angle 90 , we need at~2.4 miliseconds delay
	 * So, 2.4*1000 = Compare value * 4 , then compare value = 600*/
     /*If angle = -90 , 130+((-90+90)*2.75) = 130  -->  Angle -90
      * If angle = 0 , 130+((0+90)*2.75) = 377 --> Angle 0
      * If angle = 90 , 130((90+90)*2.75) = 625 --> Angle 90
      */
    return 130 + ((Copy_su8Angle + 90) * 2.75); /* Assuming 2.75 is the PWM increment per degree*/


}

/* Function to move the servo smoothly to the desired angle using channel A portd pin 5*/
void Servo_A_GO(sint8 Copy_su8Angle)
{
    /* Set the angle within the servo's range*/
    if (Copy_su8Angle < SERVO_MIN_ANGLE) {
    	Copy_su8Angle = SERVO_MIN_ANGLE;
    } else if (Copy_su8Angle > SERVO_MAX_ANGLE) {
    	Copy_su8Angle = SERVO_MAX_ANGLE;
    }

    /*Gradually move from the current position to the desired position*/
    for (sint8 i = servoCurrentPosition; i != Copy_su8Angle; i += (Copy_su8Angle > servoCurrentPosition) ? 1 : -1) {
        /* Calculate PWM value for the current angle*/
        uint16 pwmValue = Calculate_u16PWM(i);

        /* Update PWM duty cycle for servo control*/
        OCR1A = pwmValue;

        /* Wait for a short delay for gradual movement*/
        _delay_ms(10); /* Adjust this delay as needed for smoother movement*/

        /* Update the current position */
        servoCurrentPosition = i;
    }
}

/* Function to move the servo smoothly to the desired angle using channel B portd pin 4*/
void Servo_B_GO(sint8 Copy_su8Angle)
{

	 /* Set the angle within the servo's range*/
	    if (Copy_su8Angle < SERVO_MIN_ANGLE) {
	    	Copy_su8Angle = SERVO_MIN_ANGLE;
	    } else if (Copy_su8Angle > SERVO_MAX_ANGLE) {
	    	Copy_su8Angle = SERVO_MAX_ANGLE;
	    }

	    /*Gradually move from the current position to the desired position*/
	    for (sint8 i = servoCurrentPosition; i != Copy_su8Angle; i += (Copy_su8Angle > servoCurrentPosition) ? 1 : -1)
	    {
	        /* Calculate PWM value for the current angle*/
	        uint16 pwmValue = Calculate_u16PWM(i);

	        /* Update PWM duty cycle for servo control*/
	        OCR1B = pwmValue;

	        /* Wait for a short delay for gradual movement*/
	        _delay_ms(10); /* Adjust this delay as needed for smoother movement*/

	        /* Update the current position */
	        servoCurrentPosition = i;
	    }
}

