/*
 * DIO_REG.h
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_

#define PORTA_REG	*((volatile uint8*)0x3B)
#define DDRA_REG	*((volatile uint8*)0x3A)
#define PINA_REG	*((volatile uint8*)0x39)

#define PORTB_REG	*((volatile uint8*)0x38)
#define DDRB_REG	*((volatile uint8*)0x37)
#define PINB_REG	*((volatile uint8*)0x36)

#define PORTC_REG	*((volatile uint8*)0x35)
#define DDRC_REG	*((volatile uint8*)0x34)
#define PINC_REG	*((volatile uint8*)0x33)

#define PORTD_REG	*((volatile uint8*)0x32)
#define DDRD_REG	*((volatile uint8*)0x31)
#define PIND_REG	*((volatile uint8*)0x30)

/*******************************	External Intrrupt Regs		*******************************/

#define SREG		(*(volatile uint8*)(0x5F))
#define GICR		(*(volatile uint8*)(0x5B))
#define GIFR		(*(volatile uint8*)(0x5A))
#define MCUCR		(*(volatile uint8*)(0x55))
#define MCUCSR		(*(volatile uint8*)(0x54))

/*******************************		ADC Regs				*******************************/

#define ADMUX		(*(volatile uint8*)(0x27))
#define ADCSRA		(*(volatile uint8*)(0x26))
#define ADCH		(*(volatile uint8*)(0x25))
#define ADCl		(*(volatile uint8*)(0x24))
#define ADC_ADJUST	(*(volatile uint16*)(0x24))
#define	SFIOR		(*(volatile uint8*)(0x50))

/*******************************		TIMER_00				*******************************/
 
#define TCNT0		(*(volatile uint8*)(0x52))
#define TCCR0		(*(volatile uint8*)(0x53))
#define OCR0		(*(volatile uint8*)(0x5C))
#define TIMSK		(*(volatile uint8*)(0x59))

/*******************************		TIMER_01				*******************************/

#define TCCR1A		(*(volatile uint8*)(0x4F))
#define TCCR1B		(*(volatile uint8*)(0x4E))
#define OCR1A		(*(volatile uint8*)(0x4A))
#define ICR1		(*(volatile uint8*)(0x46))

/*******************************		TIMER_02				*******************************/




#endif /* DIO_REG_H_ */