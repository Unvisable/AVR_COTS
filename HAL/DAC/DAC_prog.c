
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"DAC_interface.h"
#include"DAC_cfg.h"


void DAC_voidInit(void)
{
    #if((DAC_Port == DIO_u8PORTA)&&(Number_Of_Bits == Eight_Bits))
        DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTB)&&(Number_Of_Bits == Eight_Bits))
        DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTC)&&(Number_Of_Bits == Eight_Bits))
        DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTD)&&(Number_Of_Bits == Eight_Bits))
        DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
    #endif

    #if((DAC_Port == DIO_u8PORTA)&&(Number_Of_Bits == Six_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D5_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D0_PIN,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTB)&&(Number_Of_Bits == Six_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D5_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D0_PIN,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTC)&&(Number_Of_Bits == Six_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D5_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D0_PIN,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTD)&&(Number_Of_Bits == Six_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D5_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D0_PIN,DIO_u8PORT_OUTPUT);
    #endif


    #if((DAC_Port == DIO_u8PORTA)&&(Number_Of_Bits == Four_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTA,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTB)&&(Number_Of_Bits == Four_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTB,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTC)&&(Number_Of_Bits == Four_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTC,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
    #endif
     #if((DAC_Port == DIO_u8PORTD)&&(Number_Of_Bits == Four_Bits))
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D4_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D3_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D2_PIN,DIO_u8PORT_OUTPUT);
        DIO_u8SetPinDirection(DIO_u8PORTD,DAC_u8D1_PIN,DIO_u8PORT_OUTPUT);
    #endif



   
}
void DAC_voidSetAnalog(uint16 Copy_u16mVolt)
{


	 f32 AnalogValue =((Copy_u16mVolt) / (StepSize));
	  DIO_u8SetPortValue(DAC_Port,(uint16)(AnalogValue));

}
