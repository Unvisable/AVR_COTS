/*
 * SWITCH_INTERFACE.h
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

typedef enum{
	PULL_DOWN =0u,
	PULL_UP=1u,

}SWITCH_TYPE_t;

typedef enum{
	PRESSED=1u,
		RELEASED=0u
}SWITCH_STATUE_t;

typedef struct{
	uint8 SWITCH_u8PORT;
	uint8 SWITCH_u8PIN;
	SWITCH_TYPE_t SWITCH_u8TYPE;
	SWITCH_STATUE_t SWITCH_u8STATUE;
}SWITCH_CONFIG_t;

uint8 SWITCH_u8GET_STATUE(const SWITCH_CONFIG_t * Ptr_u8CopyConfig,uint8 * Copy_u8PState);

#endif /* SWITCH_INTERFACE_H_ */
