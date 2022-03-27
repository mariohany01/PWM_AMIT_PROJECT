/*
 * G_LCD.h
 */ 


#ifndef G_LCD_H_
#define G_LCD_H_


void GLCD_Init();
void GLCD_Command(char Command)	;
void GLCD_Data(char Data);
void GLCD_ClearAll();						/* GLCD all display clear function */
void GLCD_String_Letter(char page_no, char *str);	/* GLCD string write function */
void GLCD_String_IMG(const char* image)	;


#endif /* G_LCD_H_ */