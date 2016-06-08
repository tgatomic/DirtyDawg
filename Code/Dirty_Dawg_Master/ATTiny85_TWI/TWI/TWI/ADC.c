/*
 * ADC.c
 *
 * Created: 2016-04-28 14:03:18
 *  Author: Atomic
 */ 

#include <avr/io.h>
#include "ADC.h"


void ADC_init(void){
	
	
	
	//Enables the ADC
	ADCSRA = (1<<ADEN);
	
	//Set the prescaler to 16 for a 125 KHz sample frequency
	ADCSRA |= (0<<ADPS0) |(1<<ADPS1) | (1<<ADPS2);
	
	ADMUX |= (1 << ADLAR); 		// Left adjust ADC result to allow easy 8 bit reading 
	
	
}


uint16_t Read_ADC(uint8_t ADC_Channel){
	
	//Enables the ADC
	ADCSRA = (1<<ADEN);
	
	//Masks the ADC channel to read from
	ADMUX &= 0xF0;
	ADMUX |= ADC_Channel;
	
	//Starts conversion
	ADCSRA |= (1<<ADSC);
	//While the flag is set, wait
	while (ADCSRA & (1<<ADSC));
	
	//Disable the ADC
	ADCSRA &= ~(1<<ADEN);
	
	return ADCH;
}