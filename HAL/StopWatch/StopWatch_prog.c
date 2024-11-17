/*
 * StopWatch_prog.c
 *
 *  Created on: ???/???/????
 *      Author: eng omar
 */

#ifndef STOPWATCH_PROG_C_
#define STOPWATCH_PROG_C_
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"util/delay.h"
#include"Port_interface.h"
#include"CLCD_interface.h"
#include"DIO_interface.h"
#include"DIO_reg.h"
#include"ErrTypeSW.h"
#include"StopWatch_interface.h"


uint8 i;
uint8 Local_u8Pattern[8] = {0b00000100, 0b00000000,0b00001010,0b00000000,0b00011011,0b00001010,0b00001010,0};
uint8 Local_u8HT=0u,Local_u8HU=0u,Local_u8MT=0u,Local_u8MU=0u,Local_u8ST=0u,Local_u8SU=0u;
void StopWatch_Init(void)
{
	CLCD_voidInit();
	CLCD_voidSendCmd(1);
	PORT_voidInit();
}

void StopWatch_Reset(void)
{
  Local_u8HT=0u;
  Local_u8HU=0u;
  Local_u8MT=0u;
  Local_u8MU=0u;
  Local_u8ST=0u;
  Local_u8SU=0u;

}
void StopWatch_Display(void)
{
	 CLCD_voidSendCmd(1);
	 CLCD_voidGoToXY(0,0);
	 CLCD_voidSendNumber(Local_u8HT);
	 CLCD_voidGoToXY(1,0);
	 CLCD_voidSendNumber(Local_u8HU);
	 CLCD_voidGoToXY(2,0);
	 CLCD_voidSendData(':');
	 CLCD_voidGoToXY(3,0);
	 CLCD_voidSendNumber(Local_u8MT);
	 CLCD_voidGoToXY(4,0);
	 CLCD_voidSendNumber(Local_u8MU);
	 CLCD_voidGoToXY(5,0);
	 CLCD_voidSendData(':');
	 CLCD_voidGoToXY(6,0);
	 CLCD_voidSendNumber(Local_u8ST);
	 CLCD_voidGoToXY(7,0);
	 CLCD_voidSendNumber(Local_u8SU);


}
void StopWatch_SetHoursT(void)
{
	uint8 Local_u8Break_Point=1;
	CLCD_u8SendSpecialCharacter(0, Local_u8Pattern,0,1);
		do{
			 if(GET_BIT(PIND,2)==0)
			   {
				   _delay_ms(50);

			     CLCD_voidGoToXY(0,0);
			     Local_u8HT++;
			     if(Local_u8HT==3)
			       {
			    	 Local_u8HT=0;
			        }
			     CLCD_voidSendNumber(Local_u8HT);


			   }
			   else if(GET_BIT(PIND,3)==0)
			   {
				   _delay_ms(50);
				   CLCD_voidGoToXY(0,0);
				   Local_u8HT--;
				    if(Local_u8HT<=0)
				    {
				    	Local_u8HT=1;
				    }

				    CLCD_voidSendNumber(Local_u8HT);
			   }
			   else if(GET_BIT(PIND,4)==0)
			   {
				   _delay_ms(50);
				   Local_u8Break_Point++;

			   }
			   else if(GET_BIT(PIND,5)==0)
			   {
				   /*Do Nothing*/
			   }
		}while(Local_u8Break_Point != 2);

		Local_u8Break_Point=1;
}
void StopWatch_SetHoursU(void)
{
	uint8 Local_u8Break_Point2=1;
	        CLCD_voidGoToXY(0,1);
			CLCD_u8SendString(" ");
			CLCD_u8SendSpecialCharacter(0, Local_u8Pattern,1,1);

			do
			{
				if(GET_BIT(PIND,2)==0)
				{
					  _delay_ms(50);

				   CLCD_voidGoToXY(1,0);

				   Local_u8HU++;

				 if(Local_u8HU==10)
				   {
					 Local_u8HU=1;
				    }
				 CLCD_voidSendNumber(Local_u8HU);
				}
				else if(GET_BIT(PIND,3)==0)
				{
					  _delay_ms(50);
					CLCD_voidGoToXY(1,0);
					Local_u8HU--;
					 if(Local_u8HU<=0)
					 {
					 	Local_u8HU=9;
					 }

					 CLCD_voidSendNumber(Local_u8HU);
				}
				else if(GET_BIT(PIND,4)==0)
				{
					  _delay_ms(50);
	                 Local_u8Break_Point2++;

				}
				else if(GET_BIT(PIND,5)==0)
				{
					Local_u8Break_Point2=1;
					CLCD_voidGoToXY(1,1);
					CLCD_u8SendString(" ");
					StopWatch_SetHoursT();
				}
			}while(Local_u8Break_Point2 !=2);
			Local_u8Break_Point2=1;
}
void StopWatch_SetMinutesT(void)
{
	uint8 Local_u8Break_Point3=1;
	CLCD_voidGoToXY(1,1);
	CLCD_u8SendString(" ");
	CLCD_u8SendSpecialCharacter(0, Local_u8Pattern,3,1); /*Display After :*/

			do{
				 if(GET_BIT(PIND,2)==0)
				   {
					   _delay_ms(50);

				     CLCD_voidGoToXY(3,0);
				     Local_u8MT++;
				     if(Local_u8MT==6)
				       {
				    	 Local_u8MT=0;
				        }
				     CLCD_voidSendNumber(Local_u8MT);


				   }
				   else if(GET_BIT(PIND,3)==0)
				   {
					   _delay_ms(50);
					   CLCD_voidGoToXY(3,0);
					   Local_u8MT--;
					    if(Local_u8MT<=0)
					    {
					    	Local_u8MT=5;
					    }

					    CLCD_voidSendNumber(Local_u8MT);
				   }
				   else if(GET_BIT(PIND,4)==0)
				   {
					   _delay_ms(50);
					   Local_u8Break_Point3++;

				   }
				   else if(GET_BIT(PIND,5)==0)
				   {
					   Local_u8Break_Point3=1;
					   CLCD_voidGoToXY(3,1);
					   CLCD_u8SendString(" ");
					   StopWatch_SetHoursU();
				   }
			}while(Local_u8Break_Point3 != 2);
			Local_u8Break_Point3=1;
}
void StopWatch_SetMinutesU(void)
{
	uint8 Local_u8Break_Point4=1;
	        CLCD_voidGoToXY(3,1);
			CLCD_u8SendString(" ");
			CLCD_u8SendSpecialCharacter(0, Local_u8Pattern,4,1);

			do
			{
				if(GET_BIT(PIND,2)==0)
				{
					  _delay_ms(50);

				   CLCD_voidGoToXY(4,0);

				   Local_u8MU++;

				 if(Local_u8MU==10)
				   {
					 Local_u8MU=0;
				    }
				 CLCD_voidSendNumber(Local_u8MU);
				}
				else if(GET_BIT(PIND,3)==0)
				{
					  _delay_ms(50);
					CLCD_voidGoToXY(4,0);
					Local_u8MU--;
					 if(Local_u8MU<=0)
					 {
					 	Local_u8MU=9;
					 }

					 CLCD_voidSendNumber(Local_u8MU);
				}
				else if(GET_BIT(PIND,4)==0)
				{
					  _delay_ms(50);
	                 Local_u8Break_Point4++;

				}
				else if(GET_BIT(PIND,5)==0)
				{
					Local_u8Break_Point4=1;
					CLCD_voidGoToXY(4,1);
					CLCD_u8SendString(" ");
					StopWatch_SetMinutesT();
				}


			}while(Local_u8Break_Point4 !=2);
			Local_u8Break_Point4=1;

}
void StopWatch_SetSecondsT(void)
{
	uint8 Local_u8Break_Point5=1;
	CLCD_voidGoToXY(4,1);
	CLCD_u8SendString(" ");
	CLCD_u8SendSpecialCharacter(0, Local_u8Pattern,6,1); /*Display After :*/

				do{
					 if(GET_BIT(PIND,2)==0)
					   {
						   _delay_ms(50);

					     CLCD_voidGoToXY(6,0);
					     Local_u8ST++;
					     if(Local_u8ST==6)
					       {
					    	 Local_u8ST=0;
					        }
					     CLCD_voidSendNumber(Local_u8ST);


					   }
					   else if(GET_BIT(PIND,3)==0)
					   {
						   _delay_ms(50);
						   CLCD_voidGoToXY(6,0);
						   Local_u8ST--;
						    if(Local_u8ST<=0)
						    {
						    	Local_u8ST=5;
						    }

						    CLCD_voidSendNumber(Local_u8ST);
					   }
					   else if(GET_BIT(PIND,4)==0)
					   {
						   _delay_ms(50);
						   Local_u8Break_Point5++;

					   }
					   else if(GET_BIT(PIND,5)==0)
					   {
						   Local_u8Break_Point5=1;
						   CLCD_voidGoToXY(6,1);
						   CLCD_u8SendString(" ");
						   StopWatch_SetMinutesU();
					   }
				}while(Local_u8Break_Point5 != 2);
				Local_u8Break_Point5=1;
}
void StopWatch_SetSecondsU(void)
{
	uint8 Local_u8Break_Point6=1;
	            CLCD_voidGoToXY(6,1);
				CLCD_u8SendString(" ");
				CLCD_u8SendSpecialCharacter(0, Local_u8Pattern,7,1);

				do
				{
					if(GET_BIT(PIND,2)==0)
					{
						  _delay_ms(50);

					   CLCD_voidGoToXY(7,0);

					   Local_u8SU++;

					 if(Local_u8SU==10)
					   {
						 Local_u8SU=1;
					    }
					 CLCD_voidSendNumber(Local_u8SU);
					}
					else if(GET_BIT(PIND,3)==0)
					{
						  _delay_ms(50);
						CLCD_voidGoToXY(7,0);
						Local_u8SU--;
						 if(Local_u8SU<=0)
						 {
						 	Local_u8SU=9;
						 }

						 CLCD_voidSendNumber(Local_u8SU);
					}
					else if(GET_BIT(PIND,4)==0)
					{
						  _delay_ms(50);
		                 Local_u8Break_Point6++;

					}
					else if(GET_BIT(PIND,5)==0)
					{
						Local_u8Break_Point6=1;
						CLCD_voidGoToXY(7,1);
						CLCD_u8SendString(" ");
						StopWatch_SetSecondsT();
					}


				}while(Local_u8Break_Point6 !=2);
				Local_u8Break_Point6=1;
				_delay_ms(200);
				CLCD_voidSendCmd(1);

				do
				{
					if(GET_BIT(PIND,5)==0)
					{

						break;
					}
					CLCD_voidSendCmd(1);
					CLCD_u8SendString("Enter to start");
					_delay_ms(250);
					CLCD_voidSendCmd(1);
					CLCD_u8SendString("Enter to start");
					_delay_ms(250);
				}while(GET_BIT(PIND,5)!=0);


				/*Turn on Stop Watch*/

}
void StopWatch_TurnOn(void)
{
	uint8 Hours = (Local_u8HT*10)+Local_u8HU;
	uint8 Minutes = (Local_u8MT*10)+Local_u8MU;
	uint8 Seconds = (Local_u8ST*10)+Local_u8SU;
     CLCD_voidSendCmd(1);

     if(Local_u8HT == 0)
     {
    	 CLCD_voidGoToXY(0,0);
    	 CLCD_voidSendNumber(0);
    	 CLCD_voidGoToXY(1,0);
    	 CLCD_voidSendNumber(Hours);
     }
     else
     {
    	 CLCD_voidGoToXY(0,0);
    	 CLCD_voidSendNumber(Hours);
     }

     CLCD_voidGoToXY(2,0);
     CLCD_voidSendData(':');

     if(Local_u8MT == 0)
     {
    	  CLCD_voidGoToXY(3,0);
    	  CLCD_voidSendNumber(0);
    	  CLCD_voidGoToXY(4,0);
    	  CLCD_voidSendNumber(Minutes);
     }
     else
     {
    	  CLCD_voidGoToXY(3,0);
    	  CLCD_voidSendNumber(Minutes);
     }

     CLCD_voidGoToXY(5,0);
     CLCD_voidSendData(':');
     CLCD_voidGoToXY(6,0);
     if(Local_u8ST == 0)
     {
    	 CLCD_voidGoToXY(6,0);
    	 CLCD_voidSendNumber(0);
    	 CLCD_voidGoToXY(7,0);
    	 CLCD_voidSendNumber(Seconds);
     }
     else
     {
    	 CLCD_voidGoToXY(6,0);
    	  CLCD_voidSendNumber(Seconds);
     }

    for(uint8 i=Seconds; i>=0; i--)
    {
    	Seconds--;
    	_delay_ms(650);
         if(Seconds<10)
         {
        	   CLCD_voidGoToXY(6,0);
        	   CLCD_voidSendNumber(0);
        	   CLCD_voidGoToXY(7,0);
        	   CLCD_voidSendNumber(Seconds);
         }
         else
         {
        	 CLCD_voidGoToXY(6,0);
        	 CLCD_voidSendNumber(Seconds);
         }

         if(Seconds == 0)
         {

        	 if(Minutes == 0)
        	 {
        		 if(Hours == 0)
        		  {

        		  }
        		  else
        		  {
        		 	 Hours--;
        		 	  CLCD_voidGoToXY(0,0);
        		 	  CLCD_voidSendNumber(Hours);
        		  }

        	 }
        	 else
        	 {
        		 Minutes--;
        		 if(Minutes<10)
        		    {
        		   	 CLCD_voidGoToXY(3,0);
        		   	 CLCD_voidSendNumber(0);
        		   	 CLCD_voidGoToXY(4,0);
        		   	 CLCD_voidSendNumber(Minutes);
        		    }
        		    else
        		    {
        		   	 CLCD_voidGoToXY(3,0);
        		   	 CLCD_voidSendNumber(Minutes);
        		    }
        		 Seconds=59;
        		  CLCD_voidGoToXY(6,0);
        		  CLCD_voidSendNumber(Seconds);
        	 }


         }
         else
         {

         }

         if((Minutes == 0) && (Hours == 0)&& (Seconds==0))
         {
        	 CLCD_voidSendCmd(1);
        	 CLCD_voidGoToXY(0,0);
        	 CLCD_u8SendString("Time is out");
        	 SET_BIT(PORTC,DIO_u8PIN5);
        	 _delay_ms(1000);
         }

    }





}
void StopWatch_Set(void)
{
  StopWatch_SetHoursT();
  StopWatch_SetHoursU();
  StopWatch_SetMinutesT();
  StopWatch_SetMinutesU();
  StopWatch_SetSecondsT();
  StopWatch_SetSecondsU();
}



#endif /* STOPWATCH_PROG_C_ */
