/*
 * DIO.h
 */ 

#include "../../LIB/STD_types.h"
#include "DIO_TYPES.h"

#ifndef DIO_H_
#define DIO_H_

	void DIO_SetPortDirection	(DIO_PORT_ID PortID ,DIO_DIRECTION Direction );
	void DIO_SetPortValue		(DIO_PORT_ID PortID ,uint8 Value);							//He changed it from DIO_VALUE To unsigned char 
	
	void DIO_SetPinDirection	(DIO_PORT_ID PortID , DIO_PIN_ID PinID ,DIO_DIRECTION Direction);
	void DIO_SetPinValue		(DIO_PORT_ID PortID , DIO_PIN_ID PinID ,STD_LevelType Value);
	
	STD_LevelType DIO_GetPinValue	(DIO_PORT_ID PortID , DIO_PIN_ID PinID);    



#endif /* DIO_H_ */