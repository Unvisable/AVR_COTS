/*
 * NEMA23_Cfg.h
 *
 *  Created on: May 16, 2024
 *      Author: user
 */

#ifndef NEMA23_CFG_H_
#define NEMA23_CFG_H_
#define STP_PORT        DIO_u8PORTC
#define STEP_PIN        DIO_u8PIN0
#define DIR_PIN         DIO_u8PIN1
#define ENABLE_PIN      DIO_u8PIN2
#define RESET_PIN       DIO_u8PIN3
#define SLEEP_PIN       DIO_u8PIN4



#define STEPS_PER_REV 200 // Adjust this according to your stepper motor's specifications
#define STEP_DELAY    1000 // Adjust this to control motor speed
#endif /* NEMA23_CFG_H_ */
