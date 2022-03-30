/*
 * DIO_TYPES.h
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
typedef enum 
	{
	input,
	Output,
}DIO_DIRECTION;
	
typedef enum
	{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
}DIO_PORT_ID;


	
typedef enum
{
	PIN0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
}DIO_PIN_ID;



#endif /* DIO_TYPES_H_ */