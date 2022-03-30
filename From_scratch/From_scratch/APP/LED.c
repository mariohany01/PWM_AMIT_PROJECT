/*
 * LED.c
 */ 

#include "../MCAL/DIO/DIO_TYPES.h"  // 3shan DIO.h ele ba3do mehtag menoo hagatt ya zeft wenta msh 3amelo include feeh ya nasee7
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_REG.h"

void LED_0 ()
{

	DIO_SetPinDirection(PORTC , Pin2 , Output);
	DIO_SetPinValue(PORTC , Pin2 , HIGH);
}

void LED_1 ()
{
	//DIO_SetPortDirection( PORTC , output);
	//DIO_SetPortValue( PORTC , 0xFF);
	
	DIO_SetPinDirection(PORTC , Pin7 , Output);
	DIO_SetPinValue(PORTC , Pin7 , HIGH);
}

void LED_2 ()
{

	DIO_SetPinDirection(PORTD , Pin3 , Output);
	DIO_SetPinValue(PORTD , Pin3 , HIGH);
}