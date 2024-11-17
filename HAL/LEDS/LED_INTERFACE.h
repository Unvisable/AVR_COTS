/*
 * LED_INTERFACE.h
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef enum{
	ACT_LOW =0u,
	ACT_HIGH = 1u
}LED_ACTIVITY_t;

typedef struct{
	uint8 LED_u8PORT;
	uint8 LED_u8PIN;
	LED_ACTIVITY_t ACTIVITY_TYPE;
}LED_CONFIG_t;
#endif /* LED_INTERFACE_H_ */



uint8 LED_u8SET_ON(const LED_CONFIG_t * PtrCopyConfig);
uint8 LED_u8SET_OFF(const LED_CONFIG_t * PtrCopyConfig);
uint8 LED_u8Toggle(const LED_CONFIG_t * PtrCopyConfig);
