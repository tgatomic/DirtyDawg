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
	
	//Set the prescaler to 16 for a 500 KHz sample frequency
	ADCSRA |= (0<<ADPS0) |(0<<ADPS1) | (1<<ADPS2);
	
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
	//OR THIS ISTEAD
	//while(ADCSRA & (1<<ADIF));
	
	//Disable the ADC
	ADCSRA &= ~(1<<ADEN);
	
	return ADC;
}