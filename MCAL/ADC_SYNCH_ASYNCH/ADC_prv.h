#ifndef ADC_PRV_H
#define ADC_PRV_H

#define DIVISION_BY_2			1u
#define DIVISION_BY_4			2u
#define DIVISION_BY_8			3u
#define DIVISION_BY_16			4u
#define DIVISION_BY_32			5u
#define DIVISION_BY_64			6u
#define DIVISION_BY_128			7u

#define PRESCALER_BIT_MASK		0b11111000
#define PRESCALER_BIT_POS		0u
#define CHANNEL_BIT_MASK		0b11100000

#define EIGHT_BITS				1u
#define TEN_BITS				2u

#define IDLE					0u
#define BUSY					1u

#define FALSE					0u
#define TRUE					1u

static void voidHandleChainConvAsynch(void);

static void voidHandleSingleConvAsynch(void);

#endif
