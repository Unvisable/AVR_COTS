/*
 * Timers_prog.c
 *
 *  Created on: Apr 20, 2024
 *      Author: user
 */
#include"STD_TYPES.h"
#include"ErrType.h"
#include"BIT_MATH.h"
#include"Timers_interface.h"
#include"Timers_cfg.h"
#include"Timers_prv.h"
#include"Timers_reg.h"


//static void (*Timer0_CallBackFunc)(void)=NULL;
static void (*Timer_CallBackFunc[9])(void)={NULL};
void Timer0_voidInit(void)
{
#if(MODE == Normal_Mode)/*Set to the normal mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/*Set preload value*/
	TCNT0 = TCNTO_Init_val;
	/*Enable interrupt overflow*/
	 SET_BIT(TIMSK,TIMSK_TOIEO);
#elif(MODE == CTC)     /*Set the CTC mode*/
        CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		/*Set Compare match value*/
		OCR0=OCR0_Init_val;
		/*Enable cmopare match interrupt*/
		SET_BIT(TIMSK,TIMSK_OCIE0);

#elif(MODE == PWM_Phase_Correct)/*Set PWM, phase correct*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#elif(MODE == Fast_PWM)/*Set Fast PWM*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#endif


	/*Clear prescaler bits*/
	TCCR0 &= Clear_Prescaler_Bits;
	/*Set prescaler to divided by 256  8_bit*/
#if(Clock_Source_Val == No_clock_source)
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif(Clock_Source_Val == Prescaler_0)
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif(Clock_Source_Val == Prescaler_8)
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif(Clock_Source_Val == Prescaler_64)
    SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif(Clock_Source_Val == Prescaler_256)
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif(Clock_Source_Val == Prescaler_1024)
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#endif
	//TCCR0 |= 0b100;

}

uint8 Timer_u8SetCallBack(uint8 Copy_u8InitState,void(*Copy_pvCallBack)(void))
{
	uint8 Local_u8ErrorState=OK;
	if(Copy_pvCallBack != NULL)
	{
		/*Set Localy Function globally*/
		Timer_CallBackFunc[Copy_u8InitState] = Copy_pvCallBack;
	}
	else
	{
		Local_u8ErrorState= NULL_PTR_ERR;
	}
	return Local_u8ErrorState;

}

void Timer0_voidSetPreloadValue(uint8 Copy_u8PreloadValue)
{
  TCNT0 = Copy_u8PreloadValue;
}

void Timer0_voidSetCompareMatchValue(uint8 Copy_u8CompareValue)
{
  OCR0 = Copy_u8CompareValue;
}


/*Timer0 overflow ISR*/
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	if(Timer_CallBackFunc[Timer0_OVF_INT]!= NULL)
	{
		Timer_CallBackFunc[Timer0_OVF_INT]();
	}
	else
	{

	}
}
/*Timer0 Compare match interrupt*/
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(Timer_CallBackFunc[Timer0_OC_INT]!= NULL)
	{
		Timer_CallBackFunc[Timer0_OC_INT]();
	}
	else
	{

	}
}
