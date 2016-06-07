/*
 * SWUART.c
 *
 * Created: 2016-05-20 09:25:02
 *  Author: Atomic
 */ 


#define PRESCALE 1
#define XTAL	8000000UL
#define BAUD 19200

#include <avr/io.h>
#include <avr/interrupt.h>
#include "SWUART.h"


//#define BIT_TIME  (u8)((XTAL / BAUD) / PRESCALE) -Doesn't work at the moment
#define BIT_TIME  (u16)((XTAL + BAUD/2) / BAUD)


volatile u8 stx_count;
u8 stx_data;

volatile u8 srx_done;
u8 srx_data;
u8 srx_mask;
u8 srx_tmp;


void suart_init( void )
{
	// Enable interrupt
	sei();
	
	// Set the port HIGH
	SBIT(PORTD,STX) = 1;

	// Set the prescaler to 1
	TCCR0B = (1 << CS00);	
	
	// Enable output compare interrupt
	TIMSK0 = (1 << OCIE0A);		

	// Falling edge
	EICRA = (1 << ISC01);
	
	// Enable edge interrupt			
	EIMSK = (1 << INT0);			

	// Nothing to send
	stx_count = 0;	
	
	// Nothing to receive			
	srx_done = 0;	
	
	// Sets the output	        
	STXDDR |= 1 << STX;			
}


u8 sgetchar (void)      // Receive Byte
{
	while (!srx_done);      // wait until byte is received
	srx_done = 0;
	return srx_data;
}


ISR (INT0_vect)    // RX start
{
	// scan 1.5 bits after start (to set timing right)
	OCR0B = TCNT0 + (u8)((BIT_TIME * 3) / 2);

	// Clear bit storage
	srx_tmp = 0;  
	
	// Set bit-mask      
	srx_mask = 1;        
	if( !(SRXPIN & 1<<SRX))  {  // still low
		EIMSK &= ~(1 << INT0);			// disable edge interrupt
		TIMSK0 = 1<<OCIE0A^1<<OCIE0B;  // wait for first bit
	}
	TIFR0 = (1<<OCF0B);      // clear pending interrupt ? why does that output compare int occur?
	EIFR |= (1 << INTF0);		// clear any pending edge interrupt
}


ISR (TIMER0_COMPB_vect)
{
	u8 in = SRXPIN;      // scan RX line

	if (srx_mask) {
		if (in & 1 << SRX)
			srx_tmp |= srx_mask;
		srx_mask <<= 1; 
		OCR0B += BIT_TIME;      // next bit slice
		} else {
		srx_done = 1;      // mark RX data valid
		srx_data = srx_tmp;      // store RX data

		TIMSK0 = 1<<OCIE0A;        // enable TX and wait for start
		EIFR |= (1 << INTF0);		// clear any pending edge interrupt: This hinders the in0-vect from beeing triggerd again just now which may occur by falling edges in the serial data bits
		EIMSK = 1 << INT0;	// Re-enable edge interrupt
	}

}


void sputchar (u8 val)      // Send byte
{
	// Until last byte is finished
	while (stx_count);      
	stx_data = ~val;      // Invert data for Stop bit generation
	stx_count = 10;      // 10 bits: Start + data + Stop
}


void sputs (u8 *txt)      // Send string
{
	while (*txt)
	sputchar (*txt++);
}


ISR (TIMER0_COMPA_vect)    // TX bit
{
	u8 dout;
	u8 count;

	OCR0A += BIT_TIME;      // Next bit slice
	count = stx_count;

	if (count) {
		stx_count = --count;    // Count down

		dout = 0;
		if (count != 9) {      // No start bit
			if (!(stx_data & 1))    // Test inverted data

			dout = 1;
			stx_data >>= 1;      // Shift zero in from left
		}

		SBIT(PORTD,STX) = dout;
	}
}
