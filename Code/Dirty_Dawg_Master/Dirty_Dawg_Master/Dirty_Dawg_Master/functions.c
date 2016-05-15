
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"



void System_Init(void){
	
	status = 0;
	
	/*Setting ports - page 75*/
		
	DDRB = (1<<BRAKELIGHT) | (1<<HEADLIGHT) | (1<<RIGHT) | (1<<PORTB0); //PB0 is debug green light
	DDRD = (1<<FORWARD) | (1<<BACKWARD) | (1<<LEFT) | (1<<PORTD7); //PD7 is debug yellow
	
	//Turn on the front and backlights
	_delay_ms(8000);
	PORTB = (1<<BRAKELIGHT) | (1<<HEADLIGHT) | (1<<PORTB0);
	_delay_ms(8000);
	PORTB = (0<<BRAKELIGHT) | (0<<HEADLIGHT) | (0<<PORTB0);
	
	
	// Enables global interrupt
	sei();


}


void INT_Crash(void){
	
	
}

void Lowrider_Mode(void){
	
	
}

void Sense_Light(void){
	
	
}


void Y_LED_On(void){
	PORTD |= (1<<PORTD7);
}
void Y_LED_Off(void){
	PORTD &= (0<<PORTD7);
}
	