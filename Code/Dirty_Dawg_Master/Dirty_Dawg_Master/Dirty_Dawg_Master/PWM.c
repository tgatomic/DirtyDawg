/*
 * PWM.c
 *
 * Created: 2016-04-28 09:53:56
 *  Author: Atomic
 */ 
#include <avr/io.h>
#include "PWM.h"
#include "functions.h"


void PWM_Init(void){
	
	/*The PRTIM0 bit in ”Minimizing Power Consumption on page 42 must be written to zero to enable
	Timer/Counter0 module.*/
	
	//, TCNT0 for accessing Timer/Counter0 counter value and so on.
	
	//A lower case n replaces the timer/counter number
	
	//Max 255, Min 0
	
	/************************************************************************/
	/*					Settings for both channels						    */
	/* Timer Clock = CPU Clock without prescaling							*/
	/* Mode = Fast PWM														*/
	/* PWM Output = Non inverted                                            */                         
	/************************************************************************/
	
	TCCR2A = (1<<WGM21) | (1<<WGM20) | (1<<COM2B1);
	TCCR2B = (1<<CS20); //Sets it to non inverted
	
	TCCR0A = (1<<WGM00) | (1<<WGM01) | (1<<COM0A1);
	TCCR0B = (1<<CS00); //Sets it to non inverted
	
	//Enables the pins = COM0A1 COM1A1
	//TCNT1 use for something???
	
}

void Stop_Moving(void){
	
	//Stops the car from moving
	//PWM_BACKWARD = 0;
	//PWM_FORWARD = 0;
	//PWM_LEFT = 0;
	//PWM_RIGHT = 0;
	
}

void Drive(uint8_t direction, uint8_t speed){
	
	switch(direction){
		case L:
			PWM_LEFT = speed;
			break;
		case R:
			PWM_RIGHT = speed;
			break;
		case F:
			PWM_FORWARD = speed;
			break;
		case B:
			PWM_BACKWARD = speed;
			break;
	}
}