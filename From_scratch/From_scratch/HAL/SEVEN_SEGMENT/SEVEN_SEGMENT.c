/*
 * SEVEN_SEGMENT.c
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO_TYPES.h"
#include "../../MCAL/DIO/DIO.h"



void SEVEN_SEGMENT_INITIALIZATION()
{
	 DIO_SetPinDirection(PORTA , Pin4 , Output); // A
	 DIO_SetPinDirection(PORTA , Pin5 , Output); // b
	 DIO_SetPinDirection(PORTA , Pin6 , Output); // c
	 DIO_SetPinDirection(PORTA , Pin7 , Output); // d
	 
	 DIO_SetPinDirection(PORTB , Pin2 , Output); // EN1
	 DIO_SetPinDirection(PORTB , Pin1 , Output); // EN2
}

void SEVEN_SEGMENT_ENABLE1()
{
	 DIO_SetPinValue(PORTB , Pin2 , HIGH); // EN1
}

void SEVEN_SEGMENT_DISABLE1()
{
	DIO_SetPinValue(PORTB , Pin2 , LOW); // DIS1
}

void SEVEN_SEGMENT_ENABLE2()
{
	DIO_SetPinValue(PORTB , Pin1 , HIGH); // EN2
}

void SEVEN_SEGMENT_DISABLE2()
{
	DIO_SetPinValue(PORTB , Pin1 , LOW); // DIS2
}

void SEVEN_SEGMENT_WRITE_NUMBER(unsigned char number)
{
	if (number < 10)
	{
		
		DIO_SetPinValue(PORTA , Pin4 , GET_BIT(number , 0)); // A
		DIO_SetPinValue(PORTA , Pin5 , GET_BIT(number , 1)); // B
		DIO_SetPinValue(PORTA , Pin6 , GET_BIT(number , 2)); // C
		DIO_SetPinValue(PORTA , Pin7 , GET_BIT(number , 3)); // D
	}
}