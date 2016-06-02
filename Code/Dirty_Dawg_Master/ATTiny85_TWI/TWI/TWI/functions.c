
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"
#include "TWI_Master.h"
#include "TWI_LCD.h"




void System_Init(void){
	
	// Initiate the hardware - Working
	//Hardware_Init();

	// Baud rate max is 19200 (double speed enabled) - Working
	//UART_Init(19200);
	
	// Initiate TWI - Working
	//TWI_Master_Init();

	// Initiate LCD - Working
	//LCD_Init();

	// Initiate PWM - Working Drive working as well
	//PWM_Init();
			
	// Initiate ADC - Working
	//ADC_init();

}

void Hardware_Init(void){
	
	
	/*Setting ports - page 75*/



}


void INT_Crash(void){
	
	
}

void Lowrider_Mode(void){
	
	
}

void Sense_Light(void){
	
	
}


void Y_LED_On(void){
	//PORTD |= (1<<PORTD7);
}
void Y_LED_Off(void){
	//PORTD &= (0<<PORTD7);
}
	