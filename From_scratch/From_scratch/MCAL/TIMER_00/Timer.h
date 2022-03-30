/*
 * Timer.h
 */ 

#include "../DIO/DIO_REG.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include <avr/interrupt.h>

#ifndef TIMER_00_H_
#define TIMER_00_H_

/******************	TIMER 00	******************/
void Timer0_Init(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_SetDelay(uint32 Delay_ms);

void PWM0_Init(void);

void PWM0_SetDutyCycle(uint8 Duty_Cycle );

void PWM0_Start(void);

void TIMER_0_INIT_SET_CALLBACK( void (*COPY_FUNCTION) (void));


/******************	TIMER 01	******************/

void Timer01_Init(void);

void Timer01_Start(void);

void Timer01_Stop(void);

void Timer01_SetDelay(uint32 Delay_ms);


/******************	TIMER 02	******************/


void TIMER_2_SELECT_MODE(uint8 MODE, uint8 INT_ACTIVATE);

void TIMER_2_INIT(void);

void TIMER_2_INT_STATE(void);

void TIMER_2_START(void);

void TIMER_2_STOP(void);

void TIMER_2_SET_DELAY(uint32 Delay_ms);

void TIMER_2_PWM_SET_DUTY_CYCLE(uint8 Duty_cycle);

void TIMER_2_INIT_SET_CALLBACK( void (*COPY_FUNCTION) (void));


#endif /* TIMER_H_ */