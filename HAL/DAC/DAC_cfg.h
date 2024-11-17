#ifndef DAC_CFG_H
#define DAC_CFG_H


/*Configure the bits  , Options:   1)Eight_Bits
                                   2)Six_Bits
                                   3)Four_Bits*/
#define Number_Of_Bits     Six_Bits
/*Configure the Resolution  , Options:   1)8u
                                         2)6u
                                         3)4u*/
#define Resolution          8u
/*Configure the Resolution  , Options:   1)5000 mV
                                         2)12000 mV
                                         3)24000  mV*/
#define Vref      5000

#define StepSize  19.6 /*Analog = Digital/step --> Digital = Analog * step
                          step = 5000mV / 2 power resolution
                           resolution = 8 bits , so 5000mv / 2 power of 8
                            2 power of 8 is 265 , and we want only 255 so, 5000mV /255 = 19.6*/

#define DAC_Port     DIO_u8PORTC


#if Number_Of_Bits == Eight_Bits
#define DAC_u8D7_PIN			DIO_u8PIN7
#define DAC_u8D6_PIN			DIO_u8PIN6
#define DAC_u8D5_PIN			DIO_u8PIN5
#define DAC_u8D4_PIN			DIO_u8PIN4
#define DAC_u8D3_PIN			DIO_u8PIN3
#define DAC_u8D2_PIN			DIO_u8PIN2
#define DAC_u8D1_PIN			DIO_u8PIN1
#define DAC_u8D0_PIN			DIO_u8PIN0
#endif

#if Number_Of_Bits == Six_Bits
#define DAC_u8D5_PIN			DIO_u8PIN5
#define DAC_u8D4_PIN			DIO_u8PIN4
#define DAC_u8D3_PIN			DIO_u8PIN3
#define DAC_u8D2_PIN			DIO_u8PIN2
#define DAC_u8D1_PIN			DIO_u8PIN1
#define DAC_u8D0_PIN			DIO_u8PIN0
#endif


#if Number_Of_Bits == Four_Bits
#define DAC_u8D4_PIN			DIO_u8PIN4
#define DAC_u8D3_PIN			DIO_u8PIN3
#define DAC_u8D2_PIN			DIO_u8PIN2
#define DAC_u8D1_PIN			DIO_u8PIN1
#endif





#endif
