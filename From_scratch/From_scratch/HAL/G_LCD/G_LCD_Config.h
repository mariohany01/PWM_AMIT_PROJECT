/*
 * G_LCD_Config.h
 */ 


#ifndef G_LCD_CONFIG_H_
#define G_LCD_CONFIG_H_

#define F_CPU 16000000UL		/* Define CPU clock Freq 8MHz */
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */
#include <avr/pgmspace.h>
#include <stdio.h>			/* Include std i/o library file */
#include "../../LIB/Font_Header.h"


#define Data_Port			PORTA		/* Define data port for GLCD */
#define Command_Port		PORTC		/* Define command port for GLCD */
#define Data_Port_Dir		DDRA		/* Define data port for GLCD */
#define Command_Port_Dir	DDRC		/* Define command port for GLCD */

#define RS		 PC0		/* Define control pins */
#define RW		 PC1
#define EN		 PC2
#define CS1		 PC3
#define CS2		 PC4
#define RST		 PC5

#define TotalPage	 8



#endif /* G_LCD_CONFIG_H_ */