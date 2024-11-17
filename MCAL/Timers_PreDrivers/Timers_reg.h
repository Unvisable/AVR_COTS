/*
 * Timers_reg.h
 *
 *  Created on: Apr 20, 2024
 *      Author: user
 */

#ifndef TIMERS_REG_H_
#define TIMERS_REG_H_

#define TCNT0 *((volatile uint8*)0x52)  /*Timer/Counter Register*/
#define TCCR0 *((volatile uint8*)0x53) /*Timer/Counter Control Register*/
#define TCCR0_CS00        0u   /* Clock Select*/
#define TCCR0_CS01        1u   /* Clock Select*/
#define TCCR0_CS02        2u   /* Clock Select*/
#define TCCR0_WGM01       3u   /*Waveform Generation Mode*/
#define TCCR0_COM00       4u   /*Compare Match Output Mode*/
#define TCCR0_COM01       5u   /*Compare Match Output Mode*/
#define TCCR0_WGM00       6u   /*Waveform Generation Mode*/
#define TCCR0_FOC0        7u   /*Force Output Compare*/
#define TIMSK *((volatile uint8*)0x59)/*Timer/Counter Interrupt Mask Register*/
#define TIMSK_TOIEO       0u  /*Timer/Counter0 Overflow Interrupt Enable*/
#define TIMSK_OCIE0       1u  /*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define OCR0  *((volatile uint8 *)0x5C) /*Timer/Counter0 Output Compare Register*/
#define TIFR  *((volatile uint8 *)0x58)/*Timer/Counter Interrupt Flag Register*/
#define TOV0              0u /*Timer/Counter0 Overflow Flag*/
#define OCF0              1u /*Output Compare Flag 0*/

#endif /* TIMERS_REG_H_ */
