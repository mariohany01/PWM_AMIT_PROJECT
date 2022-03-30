/*
 Timer.c
 */ 

#include "Timer.h"
#include "Timer_Confg.h"

uint32 NUM_OVF = 0;
uint32 Init_value = 0;

uint32 timer01_NUM_Compare = 0 ;

uint32 NUM_OVF_2 = 0;
uint32 Init_value_2 = 0;

TIMER_2_MODE MODE_2 = NORMAL_MODE;
INT_FLAG_2 INT_TIMER_2 = ENABLE;


/*************************************************/
/******************	TIMER 00	******************/
/*************************************************/

void Timer0_Init(void)
{
	/*Select Normal Mode*/
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
	
	/*Enable Interrupts*/
	SET_BIT (SREG  , 7);	//enable global interrupt
	SET_BIT	(TIMSK , 0);	//enable Timer0 overflow interrupts 
}

void Timer0_Start(void)																						//000-Efsel el clock		100-/256 Prescaller
{																											//001-No Prescaller			101-/1024 Prescaller
	SET_BIT		(TCCR0 ,0);		//Awel 3 bits men TCCR0 Houma el beykararoo enta 3ayez prescaller kam		//010-/8 Prescaller			110-/external CLock sourse T0 Fallig Edge
	CLEAR_BIT	(TCCR0 ,1);																					//011-/64 Prescaller		111-/external CLock sourse T0 Rising Edge
	SET_BIT		(TCCR0 ,2);
}

void Timer0_Stop(void)
{
	CLEAR_BIT	(TCCR0 ,0);		
	CLEAR_BIT	(TCCR0 ,1);															
	CLEAR_BIT	(TCCR0 ,2);
}

void Timer0_SetDelay(uint32 Delay_ms)
{
	uint8 Tick_Time		= (1024/16) ; 
	
	uint32 Total_Ticks	= (Delay_ms * 1000)/ Tick_Time ;			//1000 da 3ashan el delay ms yeb2a bel micro
	
	NUM_OVF = Total_Ticks / 256 ;
	
	Init_value = 256 - (Total_Ticks % 256);
	
	TCNT0 = Init_value;
	
	NUM_OVF++;
	
}

void (*CALLBACK_PTTR_TIMER_0) (void) = 0;

void TIMER_0_INIT_SET_CALLBACK( void (*COPY_FUNCTION) (void))
{
	CALLBACK_PTTR_TIMER_0 = COPY_FUNCTION;
}


void PWM0_Init(void)
{
	SET_BIT(DDRB_REG ,3 );
	
	///Fast PWM
	SET_BIT(TCCR0 , 3);
	SET_BIT(TCCR0 , 6);
	//Select Non Inverted mode
	SET_BIT(TCCR0 , 5);

}

void PWM0_SetDutyCycle(uint8 Duty_Cycle )
{
	OCR0 = ((Duty_Cycle * 256)/100) -1;
}

void PWM0_Start(void)
{
	/*select prescaller 256*/
	SET_BIT (TCCR0 , 2);
}

/*************************************************/
/******************	TIMER 01	******************/
/*************************************************/

void Timer01_Init(void)
{
	/*04 CTC_1 Mode*/
	SET_BIT(TCCR1B , 3);
	
	/*General interrupt enable*/
	SET_BIT(SREG ,7);
	/*Prephral interrupt enable	- interrupt 3 timer*/
	SET_BIT(TIMSK , 4);
	
}

void Timer01_Start(void)
{
	/*set Prescaller 1024*/
	SET_BIT		(TCCR1B , 0);
	CLEAR_BIT	(TCCR1B , 1);
	SET_BIT		(TCCR1B , 2);
}

void Timer01_Stop(void)
{
	CLEAR_BIT	(TCCR1B , 0);
	CLEAR_BIT	(TCCR1B , 1);
	CLEAR_BIT	(TCCR1B , 2);
}

void Timer01_SetDelay(uint32 Delay_ms)
{
	if (Delay_ms <= 4000)
	{
		uint8 tick_time = 1024 / 16;
		
		uint32 num_ticks = (Delay_ms * 1000)/tick_time;
		
		OCR1A = num_ticks -1;
		
		timer01_NUM_Compare ++ ;
	}
}

/*FunctionISR LE TIMER01 
volatile uint8 Comp_Counter = 0;		//For ISR volatile Tesba2 el global variable 3ashan ama2 el optemizer eno yghayar el kema bta3etha 
********** ISR Timer 1 compare A match *******************

ISR(Timer01_COMA_vect)
{
	Comp_Counter ++ ;
	
	if(Comp_Counter == timer01_NUM_Cop)
	{
		Comp_Counter = 0;
		
		led_toggle();
	}
	
}

*/

/*************************************************/
/****************** Timer 02	******************/
/*************************************************/

void TIMER_2_SELECT_MODE(uint8 MODE, uint8 INT_ACTIVATE)
{
	MODE_2 = MODE;
	INT_TIMER_2 = INT_ACTIVATE;
}

void TIMER_2_INIT(void)
{
	switch(MODE_2)
	{
		case NORMAL_MODE:
		CLEAR_BIT(TCCR2, 3);
		CLEAR_BIT(TCCR2, 6);
		break;
		
		case CTC_MODE:
		SET_BIT(TCCR2, 3);
		CLEAR_BIT(TCCR2, 6);
		break;
		
		case FAST_PWM:
		SET_BIT(TCCR2, 3);
		SET_BIT(TCCR2, 6);
		
		SET_BIT(TCCR2, 5);			// SELECT NON-INVERTING MODE
		break;
		
		default:
		break;
	}
	
	TIMER_2_INT_STATE();
}

void TIMER_2_INT_STATE(void)
{
	if(INT_TIMER_2)
	{
		switch(MODE_2)
		{
			case NORMAL_MODE:
			SET_BIT(SREG, 7);
			SET_BIT(TIMSK, 6);
			break;
			
			case CTC_MODE:
			SET_BIT(SREG, 7);
			SET_BIT(TIMSK, 4);
			break;
			
			default:
			break;
			
		}
	}
}

void TIMER_2_START(void)
{
	switch (MODE_2)
	{
		case NORMAL_MODE:
		SET_BIT(TCCR2, 0);
		SET_BIT(TCCR2, 1);
		SET_BIT(TCCR2, 2);
		break;
		
		case CTC_MODE:
		SET_BIT(TCCR2, 0);
		CLEAR_BIT(TCCR2, 1);
		SET_BIT(TCCR2, 2);
		break;
		
		case FAST_PWM:
		CLEAR_BIT(TCCR2, 0);
		CLEAR_BIT(TCCR2, 1);
		SET_BIT(TCCR2, 2);
		break;
		
		default:
		break;
	}
}

void TIMER_2_STOP(void)
{
	CLEAR_BIT(TCCR2, 0);
	CLEAR_BIT(TCCR2, 1);
	CLEAR_BIT(TCCR2, 2);
}



void TIMER_2_SET_DELAY(uint32 Delay_ms)
{
	if (MODE_2 == NORMAL_MODE)
	{
		uint8 Tick_Time = (1024/16) ;
		uint32 Tot_Ticks = (Delay_ms * 1000) / Tick_Time ;
		NUM_OVF_2 = Tot_Ticks / 256 ;
		Init_value_2 = 256 - (Tot_Ticks % 256) ;
		TCNT2 = Init_value_2 ;
		NUM_OVF_2++;
	}
	else if (MODE_2 == CTC_MODE)
	{
		//case (CTC_MODE):
		// FNDING TICK_TIME
		uint8 TICK_TIME = ( 1024 / 16 );
		// FINDINH TOTAL_TICKS
		uint32 TOTAL_TICKS = ( Delay_ms * 1000 ) / TICK_TIME;
		OCR2 = TOTAL_TICKS - 1;
		NUM_OVF_2++ ;

	}
}

void TIMER_2_PWM_SET_DUTY_CYCLE(uint8 Duty_cycle)
{
	if (MODE_2 == FAST_PWM)
	OCR2 = ((Duty_cycle * 256) / 100) - 1 ;
}


void (*CALLBACK_PTTR) (void) = 0;

void TIMER_2_INIT_SET_CALLBACK( void (*COPY_FUNCTION) (void))
{
	CALLBACK_PTTR = COPY_FUNCTION;
}
