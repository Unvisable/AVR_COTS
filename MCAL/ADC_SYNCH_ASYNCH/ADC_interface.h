#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


typedef struct{
	uint8 ChainSize;
	uint8* ChannelArr;
	uint16* ResultArr;
	void(*NotificationFunc)(void);
}ADC_Chain_t;

typedef struct{
       uint8 ADC_InitChainSize;
	   uint8 * ADC_InitChannelArr;
	   uint8 ADC_InitSetResolution;
}ADC_Init_Chain_t;

void ADC_voidInit(ADC_Init_Chain_t* Copy_Object);

uint8 ADC_u8StartSingleConversionSynch(uint8 Copy_u8Channel, uint16* Copy_pu16Result);

uint8 ADC_u8StartSingleConversionAsynch(uint8 Copy_u8Channel, uint16* Copy_pu16Result, void (*Copy_pvNotificationFunc)(void));

uint8 ADC_u8StartChainConversionAsynch(ADC_Chain_t* Copy_Object);

#endif
