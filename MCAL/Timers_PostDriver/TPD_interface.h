/*
 * TPD_interface.h
 *
 *  Created on: May 11, 2024
 *      Author: user
 */

#ifndef TPD_INTERFACE_H_
#define TPD_INTERFACE_H_
/*-----------------------------TIMER0-TIMER2------------------------------------------*/
#include "STD_TYPES.h"
typedef enum{
	T0_2Normal,
	T0_2Phase_Correct,
	T0_2CTC,
	T0_2Fast_PWM
}Timer0_2WGM_t;


typedef enum{
	T0_2Disconnected_Non,
	T0_2Toggle,
	T0_2Clear,
	T0_2Set
}Timer0_2Com_NonPwm_t;


typedef enum{
	T0_2Disconnected_Fast,
	T0_2ClearOnCom_SetAtTop,
	T0_2SetOnCom_ClearAtTop
}Timer0_2Com_FastPwm_t;

typedef enum{
	T0_2Disconnected_Phase,
	T0_2ClearUpCounting_SetDownCounting,
	T0_2SetUpCounting_ClearDownCounting
}Timer0_2Com_PhaseCorrect_t;

typedef enum
{
	No_CLK_Source,
	No_Prescaling,
	CLK_8,
	CLK_32,
	CLK_64,
	CLK_128,
	CLK_256,
	CLK_1024,
	Ext_ClkSource_Falling_Edge,
	Ext_ClkSource_Rising_Edge

}Timers_CLK_Select_t;

typedef enum{
	T0_2Com_Int,
	T0_2Ovf_Int,
}Timer0_2_Interrupts_t;


typedef struct{
	Timer0_2WGM_t WGM;
	Timer0_2Com_NonPwm_t CNPWM;
	Timer0_2Com_FastPwm_t CFPWM;
	Timer0_2Com_PhaseCorrect_t CPC;
	Timers_CLK_Select_t CLK;
}Timer0_2Cfg_t;


/*---------------------------------------------TIMER1------------------------------------------*/



typedef enum{
	T1_Normal,
	T1_Pwm_PhaseCorrect_8Bit,
	T1_Pwm_PhaseCorrect_9Bit,
	T1_Pwm_PhaseCorrect_10Bit,
	T1_CTC1,
	T1_FastPwm_8bit,
	T1_FastPwm_9bit,
	T1_FastPwm_10bit,
	T1_Pwm_PhaseAndFrequency_Correct1,
	T1_Pwm_PhaseAndFrequency_Correct2,
	T1_Pwm_Phase_Correct1,
	T1_Pwm_Phase_Correct2,
	T1_CTC2,
	T1_FastPwm1,
	T1_FastPwm2
}Timer1_WGM_t;

typedef enum{
	T1_CHA_Disconnected_Non,
	T1_CHA_Toggle,
	T1_CHA_Clear,
	T1_CHA_Set,
	T1_CHB_Disconnected_Non,
	T1_CHB_Toggle,
	T1_CHB_Clear,
	T1_CHB_Set
}Timer1_Com_NonPWM_t;


typedef enum{
	T1_CHA_Disconnected_Fast,
	T1_CHA_NormalPort_Fast,
	T1_CHA_ClearOnCom_SetOnTop,
	T1_CHA_SetOnCom_ClearOnTop,
	T1_CHB_Disconnected_Fast,
	T1_CHB_NormalPort_Fast,
	T1_CHB_ClearOnCom_SetOnTop,
	T1_CHB_SetOnCom_ClearOnTop

}Timer1_Com_FastPWM_t;

typedef enum{
	T1_CHA_Disconnected_Phase,
	T1_CHA_NormalPort_Phase,
	T1_CHA_ClearUpCounting_SetDownCounting,
	T1_CHA_SetUpCounting_ClearDownCounting,
	T1_CHB_Disconnected_Phase,
	T1_CHB_NormalPort_Phase,
	T1_CHB_ClearUpCounting_SetDownCounting,
	T1_CHB_SetUpCounting_ClearDownCounting
}Timer1_Com_PhaseCorrrectPWM_t;


typedef struct
{
	Timer1_WGM_t WGM;
	Timer1_Com_NonPWM_t CNP;
	Timer1_Com_FastPWM_t CFP;
	Timer1_Com_PhaseCorrrectPWM_t CPC;
	Timers_CLK_Select_t CLK;
}Timer1_Cfg_t;

typedef enum{
	T1InpCapT_Int,
	T1_ComA_Int,
	T1_ComB_Int,
	T1_Ovf_Int
}Timer1_Interrupts_t;

/*______________________________WatchDogTimer_______________________________________________*/


typedef enum{
	WDT_16_3,
	WDT_32_5,
	WDT_65,
	WDT_0_13,
	WDT_0_26,
	WDT_0_52,
	WDT_1_0,
	WDT_2_1

}WDT_Time_t;

/*________________________________________Function_Decleration________________________________________*/



uint8 Timer0_u8Init(const Timer0_2Cfg_t *Timer0_Cfg);
uint8 Timer1_u8Init(const Timer1_Cfg_t  *Timer1_Cfg);
uint8 Timer2_u8Init(const Timer0_2Cfg_t *Timer2_Cfg);
void Timer0_VoidSetPreloadVal(uint8 Copy_u8Val);
void Timer0_VoidSetCompareMatchVal(uint8 Copy_u8Val);
uint8 Timer0_SetCallBack(Timer0_2_Interrupts_t Copy_StrInt,void(*Copy_PvCallBackFunc)(void));

void Timer1_VoidSetTopVal(uint16 Copy_u16Val);
void Timer1_VoidSetComAVal(uint16 Copy_u16Val);
void Timer1_VoidSetComBVal(uint16 Copy_u16Val);

uint8 TIMER0_u8SetComNonPWM_Mode(Timer0_2Com_NonPwm_t Mode);
uint8 TIMER0_u8SetComFastPWM_Mode(Timer0_2Com_FastPwm_t Mode);
uint8 TIMER0_u8SetComPhaseCorPWM_Mode(Timer0_2Com_PhaseCorrect_t Mode);

uint8 TIMER1_u8SetComNonPWM_Mode(Timer1_Com_NonPWM_t Mode);
uint8 TIMER1_u8SetComFastPWM_Mode(Timer1_Com_FastPWM_t Mode);
uint8 TIMER1_u8SetComPhaseCorPWM_Mode(Timer1_Com_PhaseCorrrectPWM_t Mode);

uint8 TIMER2_u8SetComNonPWM_Mode(Timer0_2Com_NonPwm_t Mode);
uint8 TIMER2_u8SetComFastPWM_Mode(Timer0_2Com_FastPwm_t Mode);
uint8 TIMER2_u8SetComPhaseCorPWM_Mode(Timer0_2Com_PhaseCorrect_t Mode);
uint8 TIMER2_u8IntEnable(Timer0_2_Interrupts_t Int_Type);
uint8 TIMER0_u8IntEnable(Timer0_2_Interrupts_t Int_Type);
uint8 TIMER1_u8IntEnable(Timer1_Interrupts_t Int_Type);

uint8 TIMER0_u8IntDisable(Timer0_2_Interrupts_t Int_Type);
uint8 TIMER2_u8IntDisable(Timer0_2_Interrupts_t Int_Type);
uint8 TIMER1_u8IntDisable(Timer1_Interrupts_t Int_Type);

uint8 WDT_voidSet_Time(WDT_Time_t Time);
void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_Reset(void);


#endif /* TPD_INTERFACE_H_ */
