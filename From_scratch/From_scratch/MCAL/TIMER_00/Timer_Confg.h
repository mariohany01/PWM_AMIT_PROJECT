/*
 * Timer_Confg.h
 *
 * Created: 3/16/2022 5:32:22 AM
 *  Author: manni
 */ 


#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_

/*******************TIMER00***********************/



/*******************TIMER01***********************/



/*******************TIMER02***********************/

typedef enum{
	NORMAL_MODE,
	PWM_PHASE_CORRECT,
	CTC_MODE,
	FAST_PWM
}TIMER_2_MODE;

typedef enum{
	DISABLE,
	ENABLE
}INT_FLAG_2;




#endif /* TIMER_CONFG_H_ */