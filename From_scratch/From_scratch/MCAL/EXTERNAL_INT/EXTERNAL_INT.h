/*
 * EXTERNAL_INT.h
 *
 * Created: 3/16/2022 5:40:00 AM
 *  Author: manni
 */ 


#ifndef EXTERNAL_INT_H_
#define EXTERNAL_INT_H_


#include "EXTERNAL_INT_CONFG.h"
#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_Math.h"
#include <avr/interrupt.h>



void EXT_INT_SELECT_TRIGGER_MODE(uint8 INT_0, uint8 INT_1, uint8 INT_2);

void SET_GLOBAL_INT(void);

void EXTERNAL_INT0_INIT(void);

void EXTERNAL_INT1_INIT(void);

void EXTERNAL_INT2_INIT(void);

void EXTERNAL_INIT0_SET_CALLBACK( void (*COPY_FUNCTION) (void));

void EXTERNAL_INIT1_SET_CALLBACK( void (*COPY_FUNCTION) (void));



#endif /* EXTERNAL_INT_H_ */