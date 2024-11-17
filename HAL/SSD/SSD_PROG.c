#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ErrType.h"
#include"DIO_interface.h"
#include"SSD_INTERFACE.h"
#include"SSD_CFG.h"
#include"SSD_PRV.h"




uint8 SSD_u8ON(const SSD_CONFIG_t* PtrCopyConfig) /*FUNCTION FOR DISPLAYING*/
{
  uint8 Local_u8Errorstate= OK;
  if(PtrCopyConfig !=NULL) /*Handle Pointer Error*/
  {
	  /*If the type is anode or etakit*/
	  /* The Port will be enabled as HIGH*/
     if(PtrCopyConfig->SSD_u8TYPE == ANODE || PtrCopyConfig->SSD_u8TYPE == ETAKIT)
     {
    	 DIO_u8SetPinValue(PtrCopyConfig->SSD_u8ENABLE_PORT,PtrCopyConfig->SSD_u8ENABLE_PIN,DIO_u8PIN_HIGH);
     }

     /*If the type is Cathode*/
   	  /* The Port will be enabled as LOW*/

     else if(PtrCopyConfig->SSD_u8TYPE == CATHODE)
     {
    	 DIO_u8SetPinValue(PtrCopyConfig->SSD_u8ENABLE_PORT,PtrCopyConfig->SSD_u8ENABLE_PIN,DIO_u8PIN_LOW);
     }
  }
  else
  {
	  Local_u8Errorstate = NULL_PTR_ERR;
  }
  return Local_u8Errorstate;
}

uint8 SSD_u8OFF(const SSD_CONFIG_t* PtrCopyConfig)/*FUNCTION FOR NON_DISPLAYING*/
{
	 uint8 Local_u8Errorstate= OK;
	  if(PtrCopyConfig !=NULL)/*Handle Pointer Error*/
	  {
	     if((PtrCopyConfig->SSD_u8TYPE == ANODE) || (PtrCopyConfig->SSD_u8TYPE == ETAKIT))
	     {
	    	 DIO_u8SetPinValue(PtrCopyConfig->SSD_u8ENABLE_PORT,PtrCopyConfig->SSD_u8ENABLE_PIN,DIO_u8PIN_LOW);
	     }
	     else if(PtrCopyConfig->SSD_u8TYPE == CATHODE)
	     {
	    	 DIO_u8SetPinValue(PtrCopyConfig->SSD_u8ENABLE_PORT,PtrCopyConfig->SSD_u8ENABLE_PIN,DIO_u8PIN_HIGH);
	     }
	  }
	  else
	  {
		  Local_u8Errorstate = NULL_PTR_ERR;
	  }
	  return Local_u8Errorstate;
}
uint8 SSD_u8SetNumber(const SSD_CONFIG_t* PtrCopyConfig,uint8 Copy_Number)/*FUNCTION FOR SETTING NUM*/
{
	 uint8 Local_u8Errorstate= OK;

	if(PtrCopyConfig !=NULL)/*Handle Pointer Error*/
	{
		// Numbers array
		uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111};
		 /*If the type is anode or etakit*/
		if((PtrCopyConfig->SSD_u8TYPE == ANODE) ||(PtrCopyConfig->SSD_u8TYPE == ETAKIT))
		{
			/*Local_u8SSDDisplay is a variable that holds the value of the number that created by user in SSD_ARR*/


			uint8 Local_u8SSDDisplay = SSD_ARR[Copy_Number];

			/* if it will start from  DIO_u8PIN0 */
			/*Then we will display from DIO_u8PIN0 TO DIO_u8PIN6*/

			if(PtrCopyConfig->SSD_u8LED_PINA == DIO_u8PIN0)
			{
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN0,GET_BIT(Local_u8SSDDisplay,0u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN1,GET_BIT(Local_u8SSDDisplay,1u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN2,GET_BIT(Local_u8SSDDisplay,2u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN3,GET_BIT(Local_u8SSDDisplay,3u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN4,GET_BIT(Local_u8SSDDisplay,4u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN5,GET_BIT(Local_u8SSDDisplay,5u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN6,GET_BIT(Local_u8SSDDisplay,6u));

			}
			/* if it will start from  DIO_u8PIN1 */
			/*Then we will display from DIO_u8PIN1 TO DIO_u8PIN7*/

			else if(PtrCopyConfig->SSD_u8LED_PINA == DIO_u8PIN1)
			{
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN1,GET_BIT(Local_u8SSDDisplay,0u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN2,GET_BIT(Local_u8SSDDisplay,1u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN3,GET_BIT(Local_u8SSDDisplay,2u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN4,GET_BIT(Local_u8SSDDisplay,3u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN5,GET_BIT(Local_u8SSDDisplay,4u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN6,GET_BIT(Local_u8SSDDisplay,5u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN7,GET_BIT(Local_u8SSDDisplay,6u));
			}
			else
			{
				Local_u8Errorstate = NOK;
			}

		}
		 /*If the type is CATHODE*/
		else if(PtrCopyConfig->SSD_u8TYPE == CATHODE)
		{
			/*We will compliment the array */

			uint8 Local_u8SSDDisplay = ~SSD_ARR[Copy_Number];
			/* if it will start from  DIO_u8PIN0 */
	     	/*Then we will display from DIO_u8PIN0 TO DIO_u8PIN6*/
			if(PtrCopyConfig->SSD_u8LED_PINA == DIO_u8PIN0)
			{
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN0,GET_BIT(Local_u8SSDDisplay,0u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN1,GET_BIT(Local_u8SSDDisplay,1u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN2,GET_BIT(Local_u8SSDDisplay,2u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN3,GET_BIT(Local_u8SSDDisplay,3u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN4,GET_BIT(Local_u8SSDDisplay,4u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN5,GET_BIT(Local_u8SSDDisplay,5u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN6,GET_BIT(Local_u8SSDDisplay,6u));

			}
			/* if it will start from  DIO_u8PIN1 */
						/*Then we will display from DIO_u8PIN1 TO DIO_u8PIN7*/

			else if(PtrCopyConfig->SSD_u8LED_PINA == DIO_u8PIN1)
			{
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN1,GET_BIT(Local_u8SSDDisplay,0u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN2,GET_BIT(Local_u8SSDDisplay,1u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN3,GET_BIT(Local_u8SSDDisplay,2u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN4,GET_BIT(Local_u8SSDDisplay,3u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN5,GET_BIT(Local_u8SSDDisplay,4u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN6,GET_BIT(Local_u8SSDDisplay,5u));
				DIO_u8SetPinValue(PtrCopyConfig->SSD_u8PORT,DIO_u8PIN7,GET_BIT(Local_u8SSDDisplay,6u));
			}
			else
			{
				Local_u8Errorstate = NOK;
			}
		}
		else
		{
			Local_u8Errorstate = NOK;
		}
	}
	else
	{
		Local_u8Errorstate = NULL_PTR_ERR;
	}
	return Local_u8Errorstate;

}

