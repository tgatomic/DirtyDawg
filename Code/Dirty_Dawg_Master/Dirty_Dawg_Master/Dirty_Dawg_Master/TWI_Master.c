/*
 * TWI_Master.c
 *
 * Created: 2016-04-26 09:18:32
 *  Author: Atomic
 */ 
#include <avr/io.h>
#include "TWI_Master.h"


void TWI_Master_Init (void){
	
	//Sets the power reduction register for TWI to 0.
	PRR &= ~(1<<PRTWI);
	
	//Sets the speed of TWI to 100khz
	TWBR = 0x20;
	
	/************************************************************************
	
		Sets the TWCR - aka Two Wire Control Register
		
		TWINT - Interrupt Flag
		TWEA - Enable Acknowledge Bit
		TWSTA - Start Condition Bit
		TWSTO - Stop Condition Bit
		TWWC - Write Collision Flag
		TWEN - Enable Bit


	************************************************************************/
	
	
	
	
	/*
	TWDR = oxFF
	TWCR = 1<<TWEN | 1<<TWIE | ~(1<<TWINT) | ~(1<<TWSTA) | ~(1<<TWSTO) | ~(1<<TWWC);
	
	
	*/


	//För en interrupt ska ske måste interrupt vara enabled dvs TWIEN och
	//TWINT ska vara satta till ett för interrupt 
	
	//1-bit i SRAM ska vara satt (sei()) tvingar till en interrupt. 
	
	//TWSR - STatus Register TTWPS0 TWPS1 Should be 0
	
	//TWBR - should be 32 with 100 khz speed and 8mhz oscilator
	
	
	
}