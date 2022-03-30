/*
 * APP_SEVEN_SEGMENT.c
 */ 
#define F_CPU	16000000
#include <avr/delay.h>
#include "../LIB/STD_types.h"

void SEV_SEG(uint8 number)
{
	SEVEN_SEGMENT_INITIALIZATION();
	
	while (1)
	{
		if (number < 100)
		{
			uint8 right = number % 10 ; //EN2 Right
			uint8 left = number / 10;	//EN1 LEFT
			SEVEN_SEGMENT_DISABLE2();
			SEVEN_SEGMENT_DISABLE1();
			SEVEN_SEGMENT_WRITE_NUMBER(left);			
			SEVEN_SEGMENT_ENABLE1();
			_delay_ms(10);
			SEVEN_SEGMENT_DISABLE1();
			SEVEN_SEGMENT_WRITE_NUMBER(right);
			SEVEN_SEGMENT_ENABLE2();
			_delay_ms(10);
		}

	}
	
	
}
