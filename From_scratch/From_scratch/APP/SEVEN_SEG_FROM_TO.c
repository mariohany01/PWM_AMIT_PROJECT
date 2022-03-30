/*
 * APP_SEVEN_SEGMENT.c
 */ 
#include <avr/delay.h>
#include "../LIB/STD_types.h"
void SEV_SEG_FROM_TO(uint8 number , uint16 time_sec)		//garab float walaa uint16 (int)
{
	SEVEN_SEGMENT_INITIALIZATION();
	uint16 time_ms = time_sec*1000;
	
		if (number < 100)
		{
			uint8 right = number % 10 ; //EN2 Right
			uint8 left = number / 10;	//EN1 LEFT
			for(uint16 i = 0 ; i < time_ms / 20 ; i ++)
			{
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
