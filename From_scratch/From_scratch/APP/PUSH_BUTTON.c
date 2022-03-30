/*
 * PUSH_BUTTON.c
 */ 

#include "../MCAL/DIO/DIO_TYPES.h"  // 3shan DIO.h ele ba3do mehtag menoo hagatt ya zeft wenta msh 3amelo include feeh ya nasee7
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_REG.h"

STD_LevelType PIN_Value =0;
void PUSH_BUTTON () //Msh metdas 3alehh ==> Low (Pull down Resistance)
{
	DIO_SetPinDirection(PORTD , Pin2 , input);
	DIO_SetPinDirection(PORTD , Pin3 , Output);

while (1)
	{
	    PIN_Value = DIO_GetPinValue(PORTD , Pin2);
		if (PIN_Value == HIGH)
		{
			DIO_SetPinValue(PORTD , Pin3 , HIGH);
			PIN_Value =0;
		}
		
		else if (PIN_Value == LOW)
	    {
			DIO_SetPinValue(PORTD , Pin3 , LOW);
			
		}
		PIN_Value =0;
	}
	
}