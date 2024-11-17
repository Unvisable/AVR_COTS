#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H
/*Configurations*/
/* 1) SSD_u8Type options:          1- ANODE
 *                                 2- CATHODE
 *                                 3- ETAKIT
 * 2) SSD_u8LED_PINA options:      1-DIO_u8PIN0
 *                                 2- DIO_u8PIN1
 */

/*Initialize  SSD_u8Type options*/

typedef enum{
	ANODE= 1u,
	CATHODE = 2u,
	ETAKIT =3u
}SSD_TYPE_t;

/*Initialize  SSD_CONFIG_t*/
typedef struct{
	SSD_TYPE_t SSD_u8TYPE; /*SSD_u8TYPE object holds SSD_TYPE_t Configurations*/
	uint8 SSD_u8PORT;     /* For SSD PORT*/
	uint8 SSD_u8LED_PINA; /* For choosing between DIO_u8PIN0 and DIO_u8PIN1*/
	uint8 SSD_u8ENABLE_PORT; /* The Port that Comman anode or cathode or etakit connected for*/
	uint8 SSD_u8ENABLE_PIN;  /*To Enable This Pin*/
}SSD_CONFIG_t;
/*Declare SSD Functions*/


uint8 SSD_u8ON(const SSD_CONFIG_t* PtrCopyConfig); /*FUNCTION FOR DISPLAYING*/

uint8 SSD_u8OFF(const SSD_CONFIG_t* PtrCopyConfig);/*FUNCTION FOR NON_DISPLAYING*/

uint8 SSD_u8SetNumber(const SSD_CONFIG_t* PtrCopyConfig,uint8 Copy_Number);/*FUNCTION FOR SETTING NUM*/


#endif
