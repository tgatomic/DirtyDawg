/*
 * TWI_Slave.c
 *
 * Created: 2016-06-01 13:31:00
 *  Author: Atomic
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


void TWI_Slave_Init(uint8_t adress){
	
	PORTB |= (1<<PB0) | (1<<PB2);
	DDRB |= (1<<PB0) | (1<<PB2);
	
	
	// Enable start condition interrupt, disable overflof, set to TWI. 
	USICR = (1<<USISIE)|(1<<USIWM1)|(1<<USICS1);
	
	// Clear all flags
	USISR = 0xF0;
	
	
	
	sei();
}

