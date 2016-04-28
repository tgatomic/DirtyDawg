/*
 * ADC.c
 *
 * Created: 2016-04-28 14:03:18
 *  Author: Atomic
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "functions.h"


void ADC_init(void){
	
	
	//Sid 237
	
	/*AVcc with external capacitor at AREF pin (page 248) Change the ADLAR bit to left 
	or right adjust the pin. Write a one to leftadjust.If we change adc channel, the mux
	must be set as well.*/
	ADMUX = (1<<REFS0);
	
	//Enables the ADC
	ADCSRA = (1<<ADEN);
	
	//Set the prescaler to 128 for a 62,5 Khz frequency
	ADCSRA = (1<<ADPS0) |(1<<ADPS1) | (1<<ADPS2);
	
}


uint16_t Read_ADC(void){
	
	//Starts conversion
	ADCSRA = (1<<ADSC);
	//While the flag is set, wait
	while (ADCSRA & (1<<ADSC));
	//OR THIS INTEAD
	//while(ADCSRA & (1<<ADIF));
	
	uint16_t analogval = 0;
	
	//Saves the first two bits in variable
	analogval = ADCH;
	//Shifts the value with 8
	analogval = (analogval<<8);
	//Saves the rest in the first 8 bits
	analogval += ADCL;
	

	return analogval;
}