/*
 * DIO.c
 */ 

#include "DIO_REG.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "DIO_TYPES.h"
#include "DIO.h"


void DIO_SetPortDirection	(DIO_PORT_ID PortID ,DIO_DIRECTION Direction )
{
	if (Output == Direction)
	{
		switch (PortID)
		{
			case PORTA: DDRA_REG = 0xff ; break;
			case PORTB: DDRB_REG = 0xff ; break; 
			case PORTC: DDRC_REG = 0xff ; break; 
			case PORTD: DDRD_REG = 0xff ; break; 
		}
	}
	else if (input == Direction)
	{
		switch (PortID)
		{
			case PORTA: DDRA_REG = 0x00 ; break;
			case PORTB: DDRB_REG = 0x00 ; break;
			case PORTC: DDRC_REG = 0x00 ; break;
			case PORTD: DDRD_REG = 0x00 ; break;
		}
	}
}

void DIO_SetPortValue		(DIO_PORT_ID PortID ,unsigned char Value)
{
	switch (PortID )
	{
		case PORTA : PORTA_REG = Value ; break ;
		case PORTB : PORTB_REG = Value ; break ;
		case PORTC : PORTC_REG = Value ; break ;
		case PORTD : PORTD_REG = Value ; break ;
	}
}

void DIO_SetPinDirection	(DIO_PORT_ID PortID , DIO_PIN_ID PinID ,DIO_DIRECTION Direction)
{
	if (PortID <= PORTD && PinID <= Pin7)
	{
		if(Output == Direction)
		{
			switch(PortID)
			{
				case PORTA : DDRA_REG |= (1<<PinID); break;
				case PORTB : DDRB_REG |= (1<<PinID); break;
				case PORTC : DDRC_REG |= (1<<PinID); break;
				case PORTD : DDRD_REG |= (1<<PinID); break;
				
				//case PORTA : SET_BIT(DDRA_REG , PinID) ; break;		
				//case PORTB : SET_BIT(DDRB_REG , PinID) ; break;
				//case PORTC : SET_BIT(DDRC_REG , PinID) ; break;
				//case PORTD : SET_BIT(DDRD_REG , PinID) ; break;
				
			}
		}
		else if (input == Direction)
		{
			switch(PortID)
			{

				case PORTA : DDRA_REG &- (1<<PinID); break;
				case PORTB : DDRB_REG &- (1<<PinID); break;
				case PORTC : DDRC_REG &- (1<<PinID); break;
				case PORTD : DDRD_REG &- (1<<PinID); break;
				
				//case PORTA : CLEAR_BIT(DDRA_REG , PinID) ; break;		
				//case PORTB : CLEAR_BIT(DDRB_REG , PinID) ; break;		
				//case PORTC : CLEAR_BIT(DDRC_REG , PinID) ; break;		
				//case PORTD : CLEAR_BIT(DDRD_REG , PinID) ; break;		
			}	
		}
	}
}

void DIO_SetPinValue		(DIO_PORT_ID PortID , DIO_PIN_ID PinID ,STD_LevelType Value)
{
	if (PortID <= PORTD && PinID <= Pin7)
	{
		if ( Value == HIGH)
		{
			switch (PortID)
			{
				
				case PORTA : PORTA_REG |= (1<<PinID); break;
				case PORTB : PORTB_REG |= (1<<PinID); break;
				case PORTC : PORTC_REG |= (1<<PinID); break;
				case PORTD : PORTD_REG |= (1<<PinID); break;
				
				//case PORTA : SET_BIT(PORTA_REG , PinID) ; break ;
				//case PORTB : SET_BIT(PORTB_REG , PinID) ; break ;
				//case PORTC : SET_BIT(PORTC_REG , PinID) ; break ;
				//case PORTD : SET_BIT(PORTD_REG , PinID) ; break ;
			}
		}
		else if (Value == LOW)
		{
			switch (PortID)
			{
				
				case PORTA : PORTA_REG &=~(1<<PinID); break;
				case PORTB : PORTB_REG &= ~(1<<PinID); break;
				case PORTC : PORTC_REG &= ~(1<<PinID); break;
				case PORTD : PORTD_REG &= ~(1<<PinID); break;
				
				//case PORTA : CLEAR_BIT(PORTA_REG , PinID) ; break ;
				//case PORTB : CLEAR_BIT(PORTB_REG , PinID) ; break ;
				//case PORTD : CLEAR_BIT(PORTC_REG , PinID) ; break ;
				//case PORTC : CLEAR_BIT(PORTD_REG , PinID) ; break ;
			}
		}
	}
}

STD_LevelType DIO_GetPinValue	(DIO_PORT_ID PortID , DIO_PIN_ID PinID)
{
	STD_LevelType PinValue;
	if (PortID <= PORTD && PinID <= Pin7)
	{
		
		switch (PortID)
		{

			
		case PORTA : PinValue = GET_BIT(PINA_REG , PinID) ; break ;	
		case PORTB : PinValue = GET_BIT(PINB_REG , PinID) ; break ;
		case PORTC : PinValue = GET_BIT(PINC_REG , PinID) ; break ;
		case PORTD : PinValue = GET_BIT(PIND_REG , PinID) ; break ;
		}
	}
	
	return PinValue ;
}

																			