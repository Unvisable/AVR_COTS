/*
 * TPD_prog.c
 *
 *  Created on: May 11, 2024
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TPD_interface.h"
#include "TPD_reg.h"
#include "TPD_prv.h"
#include "ErrType.h"
static void (*Timer_CallBackFunc[9])(void)={NULL};
uint8 Timer0_u8Init(const Timer0_2Cfg_t *Timer0_Cfg)
{
 uint8 Local_u8ErroState=OK;
  switch(Timer0_Cfg ->WGM)
  {
  case(T0_2Normal): CLR_BIT(TCCR0,TCCR0_WGM00); CLR_BIT(TCCR0,TCCR0_WGM01); break;
  case(T0_2Phase_Correct):SET_BIT(TCCR0,TCCR0_WGM00); CLR_BIT(TCCR0,TCCR0_WGM01);break;
  case(T0_2CTC):CLR_BIT(TCCR0,TCCR0_WGM00); SET_BIT(TCCR0,TCCR0_WGM01);break;
  case(T0_2Fast_PWM):SET_BIT(TCCR0,TCCR0_WGM00); SET_BIT(TCCR0,TCCR0_WGM01);break;
  default: Local_u8ErroState = NOK; break;
  }

  switch(Timer0_Cfg ->CNPWM)
  {
    case(T0_2Disconnected_Non):break;
  	case(T0_2Toggle): SET_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
  	case(T0_2Clear): CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
  	case(T0_2Set): SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
  	default: Local_u8ErroState = NOK; break;
  }

  switch(Timer0_Cfg -> CFPWM)
  {
  case(T0_2Disconnected_Fast):break;
  case(T0_2ClearOnCom_SetAtTop):CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
  case(T0_2SetOnCom_ClearAtTop):SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
  default: Local_u8ErroState =NOK; break;
  }

  switch(Timer0_Cfg -> CPC)
  {
   case(T0_2Disconnected_Phase):break;
   case(T0_2ClearUpCounting_SetDownCounting):CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
   case(T0_2SetUpCounting_ClearDownCounting):SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
   default: Local_u8ErroState =NOK; break;
  }

  switch(Timer0_Cfg ->CLK)
  {
  case(No_CLK_Source):CLR_BIT(TCCR0,TCCR0_CS00);CLR_BIT(TCCR0,TCCR0_CS01);CLR_BIT(TCCR0,TCCR0_CS02);break;
  case(No_Prescaling):TCCR0 &= Clear_Prescaler_Bits;SET_BIT(TCCR0,TCCR0_CS00);CLR_BIT(TCCR0,TCCR0_CS01);CLR_BIT(TCCR0,TCCR0_CS02);break;
  case(CLK_8):TCCR0 &= Clear_Prescaler_Bits;CLR_BIT(TCCR0,TCCR0_CS00);SET_BIT(TCCR0,TCCR0_CS01);CLR_BIT(TCCR0,TCCR0_CS02);break;
  case(CLK_64):TCCR0 &= Clear_Prescaler_Bits;SET_BIT(TCCR0,TCCR0_CS00);SET_BIT(TCCR0,TCCR0_CS01);CLR_BIT(TCCR0,TCCR0_CS02);break;
  case(CLK_256):TCCR0 &= Clear_Prescaler_Bits;CLR_BIT(TCCR0,TCCR0_CS00);CLR_BIT(TCCR0,TCCR0_CS01);SET_BIT(TCCR0,TCCR0_CS02);break;
  case(CLK_1024):TCCR0 &= Clear_Prescaler_Bits;SET_BIT(TCCR0,TCCR0_CS00);CLR_BIT(TCCR0,TCCR0_CS01);SET_BIT(TCCR0,TCCR0_CS02);break;
  case(Ext_ClkSource_Falling_Edge):TCCR0 &= Clear_Prescaler_Bits;CLR_BIT(TCCR0,TCCR0_CS00);SET_BIT(TCCR0,TCCR0_CS01);SET_BIT(TCCR0,TCCR0_CS02);break;
  case(Ext_ClkSource_Rising_Edge):TCCR0 &= Clear_Prescaler_Bits;SET_BIT(TCCR0,TCCR0_CS00);SET_BIT(TCCR0,TCCR0_CS01);SET_BIT(TCCR0,TCCR0_CS02);break;
  default:Local_u8ErroState = NOK; break;
  }

 return Local_u8ErroState;
}
uint8 Timer1_u8Init(const Timer1_Cfg_t  *Timer1_Cfg)
{
 uint8 Local_u8ErroState=OK;
 switch(Timer1_Cfg->WGM){
	case (T1_Normal): CLR_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_PhaseCorrect_8Bit): SET_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_PhaseCorrect_9Bit): CLR_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_PhaseCorrect_10Bit): SET_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_CTC1): CLR_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_FastPwm_8bit): SET_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_FastPwm_9bit): CLR_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_FastPwm_10bit): SET_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_PhaseAndFrequency_Correct1): CLR_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_PhaseAndFrequency_Correct2): SET_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_Phase_Correct1): CLR_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_Pwm_Phase_Correct2): SET_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);CLR_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_CTC2): CLR_BIT(TCCR1A,TCCR1A_WGM10);CLR_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_FastPwm1): CLR_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case (T1_FastPwm2): SET_BIT(TCCR1A,TCCR1A_WGM10);SET_BIT(TCCR1A,TCCR1A_WGM11);SET_BIT(TCCR1B,TCCR1B_WGM12);SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	default: Local_u8ErroState = NOK; break;
	}

	switch(Timer1_Cfg->CNP)
	{

	case (T1_CHA_Disconnected_Non):break;
	case (T1_CHB_Disconnected_Non):break;
	case (T1_CHA_Toggle):SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case (T1_CHB_Toggle):SET_BIT(TCCR1A,TCCR1A_COM1B0);CLR_BIT(TCCR1A,TCCR1A_COM1B1);break;
	case (T1_CHA_Clear):CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case (T1_CHB_Clear):CLR_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	case (T1_CHA_Set): SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case (T1_CHB_Set): SET_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	default: Local_u8ErroState = NOK;break;
	}

	switch(Timer1_Cfg->CFP)
	{
	case T1_CHA_Disconnected_Fast:break;
	case T1_CHB_Disconnected_Fast:break;
	case T1_CHA_NormalPort_Fast: SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case T1_CHB_NormalPort_Fast: SET_BIT(TCCR1A,TCCR1A_COM1B0);CLR_BIT(TCCR1A,TCCR1A_COM1B1);break;
	case T1_CHA_ClearOnCom_SetOnTop: CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case T1_CHB_ClearOnCom_SetOnTop: CLR_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	case T1_CHA_SetOnCom_ClearOnTop: SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case T1_CHB_SetOnCom_ClearOnTop: SET_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	default: Local_u8ErroState = NOK;break;
	}

	switch(Timer1_Cfg->CPC)
	{

	case T1_CHA_Disconnected_Phase:break;
	case T1_CHB_Disconnected_Phase:break;
	case T1_CHA_NormalPort_Phase: SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case T1_CHB_NormalPort_Phase: SET_BIT(TCCR1A,TCCR1A_COM1B0);CLR_BIT(TCCR1A,TCCR1A_COM1B1);break;
	case T1_CHA_ClearUpCounting_SetDownCounting: CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case T1_CHB_ClearUpCounting_SetDownCounting: CLR_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	case T1_CHA_SetUpCounting_ClearDownCounting: SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	case T1_CHB_SetUpCounting_ClearDownCounting: SET_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	default: Local_u8ErroState = NOK;break;
	}

	switch(Timer1_Cfg->CLK){
	case No_CLK_Source:TCCR1B &=Clear_Prescaler_Bits; CLR_BIT(TCCR1B,TCCR1B_CS10);CLR_BIT(TCCR1B,TCCR1B_CS11);CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case No_Prescaling: TCCR1B &=Clear_Prescaler_Bits;SET_BIT(TCCR1B,TCCR1B_CS10);CLR_BIT(TCCR1B,TCCR1B_CS11);CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case CLK_8: TCCR1B &=Clear_Prescaler_Bits;CLR_BIT(TCCR1B,TCCR1B_CS10);SET_BIT(TCCR1B,TCCR1B_CS11);CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case CLK_64: TCCR1B &=Clear_Prescaler_Bits;SET_BIT(TCCR1B,TCCR1B_CS10);SET_BIT(TCCR1B,TCCR1B_CS11);CLR_BIT(TCCR1B,TCCR1B_CS12);break;
	case CLK_256: TCCR1B &=Clear_Prescaler_Bits;CLR_BIT(TCCR1B,TCCR1B_CS10);CLR_BIT(TCCR1B,TCCR1B_CS11);SET_BIT(TCCR1B,TCCR1B_CS12);break;
	case CLK_1024: TCCR1B &=Clear_Prescaler_Bits;SET_BIT(TCCR1B,TCCR1B_CS10);CLR_BIT(TCCR1B,TCCR1B_CS11);SET_BIT(TCCR1B,TCCR1B_CS12);break;
	case Ext_ClkSource_Falling_Edge: TCCR1B &=Clear_Prescaler_Bits;CLR_BIT(TCCR1B,TCCR1B_CS10);SET_BIT(TCCR1B,TCCR1B_CS11);SET_BIT(TCCR1B,TCCR1B_CS12);break;
	case Ext_ClkSource_Rising_Edge: TCCR1B &=Clear_Prescaler_Bits;SET_BIT(TCCR1B,TCCR1B_CS10);SET_BIT(TCCR1B,TCCR1B_CS11);SET_BIT(TCCR1B,TCCR1B_CS12);break;
	default: Local_u8ErroState = NOK;break;
	}




 return Local_u8ErroState;
}
uint8 Timer2_u8Init(const Timer0_2Cfg_t *Timer2_Cfg)
{
  uint8 Local_u8ErroState=OK;
	switch(Timer2_Cfg->WGM)
	{
	case (T0_2Normal): CLR_BIT(TCCR2,TCCR2_WGM20);CLR_BIT(TCCR2,TCCR2_WGM21);break;
	case (T0_2Phase_Correct): SET_BIT(TCCR2,TCCR2_WGM20);CLR_BIT(TCCR2,TCCR2_WGM21);break;
	case (T0_2CTC): CLR_BIT(TCCR2,TCCR2_WGM20);SET_BIT(TCCR2,TCCR2_WGM21);break;
	case (T0_2Fast_PWM): SET_BIT(TCCR2,TCCR2_WGM20);SET_BIT(TCCR2,TCCR2_WGM21);break;
	default:Local_u8ErroState = NOK;break;
	}

	switch(Timer2_Cfg->CNPWM)
	{
	case (T0_2Disconnected_Non):break;
	case (T0_2Toggle): SET_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
	case (T0_2Clear): CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	case (T0_2Set): SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	default: Local_u8ErroState = NOK;break;
	}

	switch(Timer2_Cfg->CFPWM){
	case (T0_2Disconnected_Fast):break;
	case (T0_2ClearOnCom_SetAtTop): CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	case (T0_2SetOnCom_ClearAtTop): SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	default: Local_u8ErroState = NOK;break;
	}

	switch(Timer2_Cfg->CPC){
	case (T0_2Disconnected_Phase):break;
	case (T0_2ClearUpCounting_SetDownCounting): CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	case (T0_2SetUpCounting_ClearDownCounting): SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	default: Local_u8ErroState = NOK;break;
	}

	switch(Timer2_Cfg->CLK){
	case (No_CLK_Source): CLR_BIT(TCCR2,TCCR2_CS20);CLR_BIT(TCCR2,TCCR2_CS21);CLR_BIT(TCCR2,TCCR2_CS22);break;
	case (No_Prescaling): TCCR2 &= Clear_Prescaler_Bits;SET_BIT(TCCR2,TCCR2_CS20);CLR_BIT(TCCR2,TCCR2_CS21);CLR_BIT(TCCR2,TCCR2_CS22);break;
	case (CLK_8): TCCR2 &= Clear_Prescaler_Bits;CLR_BIT(TCCR2,TCCR2_CS20);SET_BIT(TCCR2,TCCR2_CS21);CLR_BIT(TCCR2,TCCR2_CS22);break;
	case (CLK_32):TCCR2 &= Clear_Prescaler_Bits;SET_BIT(TCCR2,TCCR2_CS20);SET_BIT(TCCR2,TCCR2_CS21);CLR_BIT(TCCR2,TCCR2_CS22);break;
	case (CLK_64): TCCR2 &= Clear_Prescaler_Bits;CLR_BIT(TCCR2,TCCR2_CS20);CLR_BIT(TCCR2,TCCR2_CS21);SET_BIT(TCCR2,TCCR2_CS22);break;
	case (CLK_128): TCCR2 &= Clear_Prescaler_Bits;SET_BIT(TCCR2,TCCR2_CS20);CLR_BIT(TCCR2,TCCR2_CS21);SET_BIT(TCCR2,TCCR2_CS22);break;
	case (CLK_256): TCCR2 &= Clear_Prescaler_Bits;CLR_BIT(TCCR2,TCCR2_CS20);SET_BIT(TCCR2,TCCR2_CS21);SET_BIT(TCCR2,TCCR2_CS22);break;
	case (CLK_1024):TCCR2 &= Clear_Prescaler_Bits;SET_BIT(TCCR2,TCCR2_CS20);SET_BIT(TCCR2,TCCR2_CS21);SET_BIT(TCCR2,TCCR2_CS22);break;
	default: Local_u8ErroState = NOK;break;
	}


  return Local_u8ErroState;
}
void Timer0_VoidSetPreloadVal(uint8 Copy_u8Val)
{
   TCNT0 = Copy_u8Val;
}
void Timer0_VoidSetCompareMatchVal(uint8 Copy_u8Val)
{
  OCR0 = Copy_u8Val;
}

uint8 Timer0_SetCallBack(Timer0_2_Interrupts_t Copy_StrInt, void(*Copy_PvCallBackFunc)(void))
{
  uint8 Local_u8ErroState=OK;

  if(Copy_PvCallBackFunc !=NULL)
  {
	  Timer_CallBackFunc[Copy_StrInt]=Copy_PvCallBackFunc;
  }
  else
  {
	  Local_u8ErroState =NULL_PTR_ERR;
  }

 return Local_u8ErroState;
}
void Timer1_VoidSetTopVal(uint16 Copy_u16Val)
{
  ICR1 = Copy_u16Val;
}
void Timer1_VoidSetComAVal(uint16 Copy_u16Val)
{
  OCR1A = Copy_u16Val;
}
void Timer1_VoidSetComBVal(uint16 Copy_u16Val)
{
  OCR1B = Copy_u16Val;
}
uint8 TIMER0_u8SetComNonPWM_Mode(Timer0_2Com_NonPwm_t Mode)
{
  uint8 Local_u8ErroState=OK;
  switch(Mode)
  {
    case(T0_2Disconnected_Non):break;
   	case(T0_2Toggle): SET_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
   	case(T0_2Clear): CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
   	case(T0_2Set): SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
   	default: Local_u8ErroState = NOK; break;
  }


  return Local_u8ErroState;
}
uint8 TIMER0_u8SetComFastPWM_Mode(Timer0_2Com_FastPwm_t Mode)
{
	 uint8 Local_u8ErroState=OK;
     switch(Mode)
     {
       case(T0_2Disconnected_Fast):break;
       case(T0_2ClearOnCom_SetAtTop):CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
       case(T0_2SetOnCom_ClearAtTop):SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
       default: Local_u8ErroState =NOK; break;
     }

		return Local_u8ErroState;
}
uint8 TIMER0_u8SetComPhaseCorPWM_Mode(Timer0_2Com_PhaseCorrect_t Mode)
{
	 uint8 Local_u8ErroState=OK;
     switch(Mode)
     {
        case(T0_2Disconnected_Phase):break;
        case(T0_2ClearUpCounting_SetDownCounting):CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
        case(T0_2SetUpCounting_ClearDownCounting):SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
        default: Local_u8ErroState =NOK; break;
     }

		return Local_u8ErroState;
}

uint8 TIMER1_u8SetComNonPWM_Mode(Timer1_Com_NonPWM_t Mode)
{
	 uint8 Local_u8ErroState=OK;
     switch(Mode)
     {
        case (T1_CHA_Disconnected_Non):break;
     	case (T1_CHB_Disconnected_Non):break;
     	case (T1_CHA_Toggle):SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
     	case (T1_CHB_Toggle):SET_BIT(TCCR1A,TCCR1A_COM1B0);CLR_BIT(TCCR1A,TCCR1A_COM1B1);break;
     	case (T1_CHA_Clear):CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
     	case (T1_CHB_Clear):CLR_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
     	case (T1_CHA_Set): SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
     	case (T1_CHB_Set): SET_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
     	default: Local_u8ErroState = NOK;break;
     }

		return Local_u8ErroState;
}
uint8 TIMER1_u8SetComFastPWM_Mode(Timer1_Com_FastPWM_t Mode)
{
	 uint8 Local_u8ErroState=OK;
     switch(Mode)
     {
        case T1_CHA_Disconnected_Fast:break;
     	case T1_CHB_Disconnected_Fast:break;
     	case T1_CHA_NormalPort_Fast: SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
     	case T1_CHB_NormalPort_Fast: SET_BIT(TCCR1A,TCCR1A_COM1B0);CLR_BIT(TCCR1A,TCCR1A_COM1B1);break;
     	case T1_CHA_ClearOnCom_SetOnTop: CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
     	case T1_CHB_ClearOnCom_SetOnTop: CLR_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
     	case T1_CHA_SetOnCom_ClearOnTop: SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
     	case T1_CHB_SetOnCom_ClearOnTop: SET_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
     	default: Local_u8ErroState = NOK;break;
     }

		return Local_u8ErroState;
}

uint8 TIMER1_u8SetComPhaseCorPWM_Mode(Timer1_Com_PhaseCorrrectPWM_t Mode)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Mode)
	     {
	    case T1_CHA_Disconnected_Phase:break;
	 	case T1_CHB_Disconnected_Phase:break;
	 	case T1_CHA_NormalPort_Phase: SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
	 	case T1_CHB_NormalPort_Phase: SET_BIT(TCCR1A,TCCR1A_COM1B0);CLR_BIT(TCCR1A,TCCR1A_COM1B1);break;
	 	case T1_CHA_ClearUpCounting_SetDownCounting: CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	 	case T1_CHB_ClearUpCounting_SetDownCounting: CLR_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	 	case T1_CHA_SetUpCounting_ClearDownCounting: SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
	 	case T1_CHB_SetUpCounting_ClearDownCounting: SET_BIT(TCCR1A,TCCR1A_COM1B0);SET_BIT(TCCR1A,TCCR1A_COM1B1);break;
	 	default: Local_u8ErroState = NOK;break;
	     }

		return Local_u8ErroState;
}


uint8 TIMER2_u8SetComNonPWM_Mode(Timer0_2Com_NonPwm_t Mode)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Mode)
	     {
	    case(T0_2Disconnected_Non):break;
	 	case(T0_2Toggle): SET_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
	 	case(T0_2Clear): CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	 	case(T0_2Set): SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	 	default: Local_u8ErroState = NOK;break;
	     }

		return Local_u8ErroState;
}
uint8 TIMER2_u8SetComFastPWM_Mode(Timer0_2Com_FastPwm_t Mode)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Mode)
	     {
	    case (T0_2Disconnected_Fast): break;
	 	case (T0_2ClearOnCom_SetAtTop): CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	 	case (T0_2SetOnCom_ClearAtTop): SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	 	default: Local_u8ErroState = NOK;break;
	     }

		return Local_u8ErroState;
}
uint8 TIMER2_u8SetComPhaseCorPWM_Mode(Timer0_2Com_PhaseCorrect_t Mode)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Mode)
	     {
	    case (T0_2Disconnected_Phase):break;
	 	case (T0_2ClearUpCounting_SetDownCounting): CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	 	case (T0_2SetUpCounting_ClearDownCounting): SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
	 	default: Local_u8ErroState = NOK;break;
	     }

		return Local_u8ErroState;
}
uint8 TIMER0_u8IntEnable(Timer0_2_Interrupts_t Int_Type)
{
	uint8 Local_u8ErroState=OK;
	switch(Int_Type)
	    {
	    case(T0_2Ovf_Int):SET_BIT(TIMSK,TIMSK_TOIEO);break;
	    case(T0_2Com_Int):SET_BIT(TIMSK,TIMSK_OCIE0);break;
	    default: Local_u8ErroState=NOK;break;
	    }

		return Local_u8ErroState;
}
uint8 TIMER1_u8IntEnable(Timer1_Interrupts_t Int_Type)
{
	 uint8 Local_u8ErroState=OK;
    switch(Int_Type)
    {
    case(T1_Ovf_Int):SET_BIT(TIMSK,TIMSK_TOIE1);break;
    case(T1_ComA_Int):SET_BIT(TIMSK,TIMSK_OCIE1A);break;
    case(T1_ComB_Int):SET_BIT(TIMSK,TIMSK_OCIE1B);break;
    case(T1InpCapT_Int):SET_BIT(TIMSK,TIMSK_TICIE1);break;
    default: Local_u8ErroState=NOK;break;
    }

		return Local_u8ErroState;
}
uint8 TIMER2_u8IntEnable(Timer0_2_Interrupts_t Int_Type)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Int_Type)
	 {
	 case(T0_2Ovf_Int):SET_BIT(TIMSK,TIMSK_TOIE2);break;
	 case(T0_2Com_Int):SET_BIT(TIMSK,TIMSK_OCIE2);break;
	 default:Local_u8ErroState=NOK;break;
	 }


		return Local_u8ErroState;
}
uint8 TIMER0_u8IntDisable(Timer0_2_Interrupts_t Int_Type)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Int_Type)
	 	    {
	 	    case(T0_2Ovf_Int):CLR_BIT(TIMSK,TIMSK_TOIEO);break;
	 	    case(T0_2Com_Int):CLR_BIT(TIMSK,TIMSK_OCIE0);break;
	 	    default: Local_u8ErroState=NOK;break;
	 	    }

		return Local_u8ErroState;
}
uint8 TIMER1_u8IntDisable(Timer1_Interrupts_t Int_Type)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Int_Type)
	    {
	    case(T1_Ovf_Int):   CLR_BIT(TIMSK,TIMSK_TOIE1);break;
	    case(T1_ComA_Int):  CLR_BIT(TIMSK,TIMSK_OCIE1A);break;
	    case(T1_ComB_Int):  CLR_BIT(TIMSK,TIMSK_OCIE1B);break;
	    case(T1InpCapT_Int):CLR_BIT(TIMSK,TIMSK_TICIE1);break;
	    default: Local_u8ErroState=NOK;break;
	    }

		return Local_u8ErroState;
}
uint8 TIMER2_u8IntDisable(Timer0_2_Interrupts_t Int_Type)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Int_Type)
		 {
		 case(T0_2Ovf_Int):CLR_BIT(TIMSK,TIMSK_TOIE2);break;
		 case(T0_2Com_Int):CLR_BIT(TIMSK,TIMSK_OCIE2);break;
		 default:Local_u8ErroState=NOK;break;
		 }

		return Local_u8ErroState;
}
uint8 WDT_voidSet_Time(WDT_Time_t Time)
{
	 uint8 Local_u8ErroState=OK;
	 switch(Time){
	 	case WDT_16_3: 	WDTCR &= 0b1111000 ; break;
	 	case WDT_32_5: WDTCR &= 0b1111000 ; WDTCR |= 1 ; break;
	 	case WDT_65: WDTCR &= 0b1111000 ; WDTCR |= 2 ; break;
	 	case WDT_0_13: WDTCR &= 0b1111000 ; WDTCR |= 3 ; break;
	 	case WDT_0_26: WDTCR &= 0b1111000 ; WDTCR |= 4 ; break;
	 	case WDT_0_52: WDTCR &= 0b1111000 ; WDTCR |= 5 ; break;
	 	case WDT_1_0: WDTCR &= 0b1111000 ; WDTCR |= 6 ; break;
	 	case WDT_2_1: WDTCR &= 0b1111000 ; WDTCR |= 7 ; break;
	 	default: Local_u8ErroState = NOK; break;
	 	}

		return Local_u8ErroState;
}
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_voidDisable(void)
{
	WDTCR = (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);
		/* Turn off WDT */
		WDTCR = 0x00;
}
void WDT_Reset(void)
{
	__asm volatile("WDR");
}
/*Timer0 overflow ISR*/
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	if(Timer_CallBackFunc[T1_Ovf_Int]!= NULL)
	{
		Timer_CallBackFunc[T1_Ovf_Int]();
	}
	else
	{

	}
}
/*Timer0 Compare match interrupt*/
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(Timer_CallBackFunc[T1InpCapT_Int]!= NULL)
	{
		Timer_CallBackFunc[T1InpCapT_Int]();
	}
	else
	{

	}
}
