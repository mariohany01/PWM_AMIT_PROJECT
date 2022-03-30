/*
 * PUSH_BUTTON_2.c
 */ 

#include <avr/delay.h>
#include "../MCAL/DIO/DIO_TYPES.h"  // 3shan DIO.h ele ba3do mehtag menoo hagatt ya zeft wenta msh 3amelo include feeh ya nasee7
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_REG.h"


void PUSH_BUTTON_2 ()
	{
		//Push Buttons
		DIO_SetPinDirection(PORTD , Pin2 , input);
		DIO_SetPinDirection(PORTB , Pin4 , input);
		DIO_SetPinDirection(PORTB , PIN0 , input);
			
		//LED
		DIO_SetPinDirection(PORTD , Pin3 , Output);
		DIO_SetPinDirection(PORTC , Pin7 , Output);
		DIO_SetPinDirection(PORTC , Pin2 , Output);
		
		while (1)
		{
			STD_LevelType BUTTON_0_VALUE = DIO_GetPinValue (PORTB , PIN0);
			STD_LevelType BUTTON_1_VALUE = DIO_GetPinValue (PORTB , Pin4);
			STD_LevelType BUTTON_2_VALUE = DIO_GetPinValue (PORTD , Pin2);
			
			if(BUTTON_0_VALUE == HIGH && BUTTON_1_VALUE == LOW && BUTTON_2_VALUE == LOW)
			{
				DIO_SetPinValue(PORTD , Pin3 , HIGH);
				DIO_SetPinValue(PORTC , Pin7 , HIGH);
				DIO_SetPinValue(PORTC , Pin2 , HIGH);
			}
			else if (BUTTON_0_VALUE == LOW && BUTTON_1_VALUE == HIGH && BUTTON_2_VALUE == LOW)
			{
				DIO_SetPinValue(PORTD , Pin3 , HIGH);
				DIO_SetPinValue(PORTC , Pin7 , LOW);
				DIO_SetPinValue(PORTC , Pin2 , LOW);
				
				_delay_ms(1000);							// 1000 = Second
				
				DIO_SetPinValue(PORTD , Pin3 , LOW);
				DIO_SetPinValue(PORTC , Pin7 , HIGH);
				DIO_SetPinValue(PORTC , Pin2 , LOW);
				
				_delay_ms(1000);							// 1000 = Second
				
				DIO_SetPinValue(PORTD , Pin3 , LOW);
				DIO_SetPinValue(PORTC , Pin7 , LOW);
				DIO_SetPinValue(PORTC , Pin2 , HIGH);
				
				_delay_ms(100);							// 1000 = Second				
			}
			else if (BUTTON_0_VALUE == LOW && BUTTON_1_VALUE == LOW && BUTTON_2_VALUE == HIGH)		//COUNT BY BINARY
			{
				DIO_SetPinValue(PORTD , Pin3 , HIGH);
				DIO_SetPinValue(PORTC , Pin7 , LOW);
				DIO_SetPinValue(PORTC , Pin2 , LOW);
				
				_delay_ms(1000);							// 001
				
				DIO_SetPinValue(PORTD , Pin3 , LOW);
				DIO_SetPinValue(PORTC , Pin7 , HIGH);
				DIO_SetPinValue(PORTC , Pin2 , LOW);
				
				_delay_ms(1000);							// 010
				
				DIO_SetPinValue(PORTD , Pin3 , HIGH);
				DIO_SetPinValue(PORTC , Pin7 , HIGH);
				DIO_SetPinValue(PORTC , Pin2 , LOW);
				
				_delay_ms(1000);							// 011
				DIO_SetPinValue(PORTD , Pin3 , LOW);
				DIO_SetPinValue(PORTC , Pin7 , LOW);
				DIO_SetPinValue(PORTC , Pin2 , HIGH);
				
				_delay_ms(1000);							// 100
				
				DIO_SetPinValue(PORTD , Pin3 , HIGH);
				DIO_SetPinValue(PORTC , Pin7 , LOW);
				DIO_SetPinValue(PORTC , Pin2 , HIGH);
				
				_delay_ms(1000);							// 101
				
				DIO_SetPinValue(PORTD , Pin3 , LOW);
				DIO_SetPinValue(PORTC , Pin7 , HIGH);
				DIO_SetPinValue(PORTC , Pin2 , HIGH);
				
				_delay_ms(1000);						// 110
				
				DIO_SetPinValue(PORTD , Pin3 , HIGH);
				DIO_SetPinValue(PORTC , Pin7 , HIGH);
				DIO_SetPinValue(PORTC , Pin2 , HIGH);
				
				_delay_ms(1000);						// 111
				
			}
	
	}
	
	}