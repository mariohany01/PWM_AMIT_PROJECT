/*

		Main code
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "HAL\LCD/LCD_16x2_C_file.h"
#include "LIB\BIT_MATH.h"
#include "HAL\G_LCD\G_LCD.h"
#include "HAL\G_LCD\Image.h"

int main ( )
{
	unsigned int a,b,c,high,period;
	char frequency[14],duty_cy[7];

	int Duty_cycle = 12 ;
	
	GLCD_Init();
	DDRD = 0xBF;		/* Pin Direction */
	PORTD = 0x40;		/* Turn ON Pull-UP resistor */
	
	// TIMER_2_INIT
			SET_BIT(TCCR2, 3);
			SET_BIT(TCCR2, 6);
			SET_BIT(TCCR2, 5);			// SELECT NON-INVERTING MODE
			
	//TIMER_2_PWM_SET_DUTY_CYCLE(uint8 Duty_cycle)
				
			OCR2 = ((Duty_cycle * 256) / 100) - 1 ;
			
	// TIMER_2_START
	
			CLEAR_BIT(TCCR2, 0);
			CLEAR_BIT(TCCR2, 1);
			SET_BIT(TCCR2, 2);

	
	
	
//	while(1)
//	{
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);				/* clear ICP flag (Input Capture flag) */

		TCCR1B = 0x41;					/* rising edge, No prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;						/* take value of capture register */
		TIFR = (1<<ICF1);				/* clear ICP flag (Input Capture flag) */
		
		TCCR1B = 0x01;				   /* falling edge, No prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;						/* take value of capture register */
		TIFR = (1<<ICF1);				/* clear ICP flag (Input Capture flag) */
		
		TCCR1B = 0x41;					/* rising edge, No prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		c = ICR1;						/* take value of capture register */
		TIFR = (1<<ICF1);				/* clear ICP flag (Input Capture flag) */

		TCCR1B = 0;				        /* stop the timer */
		
		if(Duty_cycle < 101 && a<b && b<c)					/* check for valid condition, to avoide timer overflow reading */
		{
			high=b-a;
			period=c-a;
			
			/* calculate frequency */
			long freq= F_CPU/period;	
			/*calculate duty cycle */
			float duty_cycle = ((float) high/ (float) period)*100;	

			
			
			ltoa(freq,frequency,10);
			
			itoa((int)duty_cycle,duty_cy,10);
						
			if (Duty_cycle == 0 )
			{
				GLCD_String_IMG(Zero);
			}
			
			else if (Duty_cycle <= 10)
			{
				GLCD_String_IMG(One);
				
			}
			
			else if (Duty_cycle <= 20)
			{
				GLCD_String_IMG(Eleven);
			}
			
			else if (Duty_cycle <= 30)
			{
				GLCD_String_IMG(Twenty_One);
			}
			
			else if (Duty_cycle <= 40)
			{
				GLCD_String_IMG(Thirty_One);
			}
			
			else if (Duty_cycle <= 50)
			{
				GLCD_String_IMG(Forty_One);
			}
			
			else if (Duty_cycle <= 60)
			{
				GLCD_String_IMG(Fifty_One);
				
			}
			
			else if (Duty_cycle <= 70)
			{
				GLCD_String_IMG(Sixty_One);
			}

			else if (Duty_cycle <= 80)
			{
				GLCD_String_IMG(Seventy_One);
			}
			
			else if (Duty_cycle <= 90)
			{
				GLCD_String_IMG(Eighty_One);
			}
			
			else if (Duty_cycle <= 100)
			{
				GLCD_String_IMG(Ninty_One);
			}
			else
			{
				GLCD_String_Letter(5,"ERROR LOADING GRAPH");
			}

			GLCD_Command(0x80);	
			GLCD_String_Letter(2,"     HZ ---- > Freq");
			GLCD_String_Letter(2,frequency);


			
			GLCD_Command(0xC0);
			GLCD_String_Letter(3,"  % ---- > Duty Cycle");
			GLCD_String_Letter(3,duty_cy);
			
			
		}
		
		else
		{
			GLCD_ClearAll();
			GLCD_String_Letter(2,"OUT OF RANGE!!");
		}
		_delay_ms(50);
	//}
}
