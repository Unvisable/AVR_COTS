#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include"LED_INTERFACE.h"


uint8 LED_u8SET_ON(const LED_CONFIG_t * PtrCopyConfig)
{
	uint8 Local_u8ErrorState=OK;
	if(PtrCopyConfig != NULL)
	{
		if(PtrCopyConfig->ACTIVITY_TYPE == ACT_HIGH)
		{
			DIO_u8SetPinValue(PtrCopyConfig->LED_u8PORT, PtrCopyConfig->LED_u8PIN, DIO_u8PIN_HIGH);
		}
		else if(PtrCopyConfig->ACTIVITY_TYPE == ACT_LOW)
		{
			DIO_u8SetPinValue(PtrCopyConfig->LED_u8PORT, PtrCopyConfig->LED_u8PIN, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
uint8 LED_u8SET_OFF(const LED_CONFIG_t * PtrCopyConfig)
{
	uint8 Local_u8ErrorState=OK;
		if(PtrCopyConfig != NULL)
		{
			if(PtrCopyConfig->ACTIVITY_TYPE == ACT_HIGH)
			{
				DIO_u8SetPinValue(PtrCopyConfig->LED_u8PORT, PtrCopyConfig->LED_u8PIN, DIO_u8PIN_LOW);
			}
			else if(PtrCopyConfig->ACTIVITY_TYPE == ACT_LOW)
			{
				DIO_u8SetPinValue(PtrCopyConfig->LED_u8PORT, PtrCopyConfig->LED_u8PIN, DIO_u8PIN_HIGH);
			}
			else
			{
				Local_u8ErrorState=NOK;
			}
		}
		else
		{
			Local_u8ErrorState=NULL_PTR_ERR;
		}
		return Local_u8ErrorState;
}
uint8 LED_u8Toggle(const LED_CONFIG_t * PtrCopyConfig)
{
   uint8  Local_u8ErrorState=OK;
   if(PtrCopyConfig != NULL)
   {
	   DIO_u8TogglePinValue(PtrCopyConfig->LED_u8PORT,PtrCopyConfig->LED_u8PIN);
   }
   else
   {
	   Local_u8ErrorState=NULL_PTR_ERR;
   }
   return Local_u8ErrorState;
}
