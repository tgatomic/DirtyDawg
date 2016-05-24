
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"
#include "TWI_Master.h"
#include "TWI_LCD.h"
#include "Bluetooth.h"
#include "PWM.h"
#include "ADC.h"

void System_Init(void){
	
	// Initiate the hardware - Working
	Hardware_Init();

	// Baud rate max is 19200 (double speed enabled) - Working
	UART_Init(19200);
	
	// Initiate TWI - Working
	TWI_Master_Init();

	// Initiate LCD - Working
	LCD_Init();

	// Initiate PWM - Working Drive working as well
	PWM_Init();
			
	// Initiate ADC - Working
	ADC_init();

}

void Hardware_Init(void){
	
	
	/*Setting ports - page 75*/
		
	DDRB = (1<<BRAKELIGHT) | (1<<HEADLIGHT) | (1<<RIGHT) | (1<<PORTB0); //PB0 is debug green light
	DDRD = (1<<FORWARD) | (1<<BACKWARD) | (1<<LEFT) | (1<<PORTD7); //PD7 is debug yellow
	
	//Turn on the front and backlights
	_delay_ms(1000);
	PORTB = (1<<BRAKELIGHT) | (1<<HEADLIGHT) | (1<<PORTB0);
	_delay_ms(1000);
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
	