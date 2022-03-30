/*
 * LCD_APP.c
 */ 

#include <avr/delay.h>
#include "../LIB/STD_types.h"
void LCD_APP ()
{
	LCD_Initialize();
	LCD_WriteString("MARIO");
	
	LCD_Initialize();
	LCD_GoToPos(1,0);
	LCD_WriteString("Mario Hany");
	LCD_GoToPos(1,0);
	LCD_WriteString("1:';-=12 ` ?");


/*	LCD_Initialize();
	LCD_GoToPos(1,0);
	uint8 pattern []={ 0x0E, 0x02, 0x0F, 0x00, 0x04, 0x04, 0x04, 0x04};
	LCD_StoreCustomChr(pattern , 0);
	LCD_DisplayCustomChr(0);
	
	LCD_GoToPos(1,0);
	uint8 pattern0 []={ 0x0E, 0x02, 0x0F, 0x00, 0x04, 0x04, 0x04, 0x04};
	LCD_StoreCustomChr(pattern0 , 1);
	LCD_DisplayCustomChr(1);*/

}