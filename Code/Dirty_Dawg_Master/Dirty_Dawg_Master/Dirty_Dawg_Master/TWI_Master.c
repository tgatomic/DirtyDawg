/*
 * TWI_Master.c
 *
 * Created: 2016-04-26 09:18:32
 *  Author: Atomic
 */ 
#include <avr/io.h>
#include "TWI_Master.h"
#include "functions.h"


void TWI_Master_Init (void){
	
	//Sets the power reduction register for TWI to 0.
	PRR &= ~(1<<PRTWI);
	
	//Sets the prescaler to 1 by setting TWPS1 and 0 to 0
	TWSR &= ~(1<<TWPS1) & ~(1<<TWPS0); 
	
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
		TWIE - Interrupt Enable

	************************************************************************/
	TWDR = 0xFF;
	TWCR = ~(1<<TWINT) | ~(1<<TWSTA) | ~(1<<TWSTO) | ~(1<<TWWC) | (1<<TWIE) | (1<<TWEN);


	//För en interrupt ska ske måste interrupt vara enabled dvs TWIEN och
	//TWINT ska vara satta till ett för interrupt 
	
	//1-bit i SRAM ska vara satt (sei()) tvingar till en interrupt. 

}

int TWI_Busy(void){
	//Returns 0 if the MCU is busy
	return TWCR & (1<<TWINT);
}

void TWI_Send(uint8_t slaveAddress, uint8_t data){
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (slaveAddress<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error(MT_ADDRESS_ACK);
	
	//Sends the data to the slave
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_BYTE_ACK)Error(MT_BYTE_ACK);
	
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	

}

uint8_t TWI_Receive(uint8_t slaveAddress){
	
	uint8_t data;
	
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 0
	TWDR = (slaveAddress<<1) | (1<<0);
	TWCR = (1<<TWINT) & ~(1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
		
		
	//Receives the data
	data = TWDR;
	TWDR = MR_BYTE_NACK;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
		
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
	return data;
}