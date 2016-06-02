/*
 * TWI_Master.c
 *
 * Created: 2016-04-26 09:18:32
 *  Author: Atomic
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include "TWI_Master.h"
#include "TWI_LCD.h"
#include "functions.h"
#include "Bluetooth.h"


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
	TWCR = (0<<TWINT) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWWC) | (1<<TWIE) | (1<<TWEN);


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
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error(MT_ADDRESS_ACK);
	
	//Sends the data to the slave
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_BYTE_ACK)Error(MT_BYTE_ACK);
	
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	/*
	In order to send many bytes we can save adress in the place 0 in the vector and then the data. 
	Start | | Addr+R |ACK| |DATA|ACK| |DATA|ACK|DATA|NACK| |STOP| 
	*/
	/*
	
	ISR(TWI)
		Switch(TWSR)
			case(START):
				Send address
				TWDR = DATA[0];
				TWCR = (1<<TWEN) | (1<<TWIE) | (1<<TWINT);
				
			case(ADDR_ACK):
				send data
				TWDR = DATA[1];
				TWCR = (1<<TWEN) | (1<<TWIE) | (1<<TWINT);
				
			case(Data_NACK):
				stop();
	*/
}

void TWI_Receive(uint8_t slaveAddress, uint8_t nmr_bytes){
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);

	//Loads the slave address and set the R/W bit to 1
	TWDR = (slaveAddress<<1) | (0<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???

	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error(MT_ADDRESS_ACK);


	//Tell the ATTiny that we want data from position 0 in buffer
	TWDR = 0x00;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_BYTE_ACK)Error(MT_BYTE_ACK);


	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) != REPEAT_START)Error(REPEAT_START);

	//Loads the slave address and set the R/W bit to 0
	TWDR = (slaveAddress<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN);

	//Waits and check the message back
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
	
	
	//Repeat the receive function as many times as nmr_bytes	
	int i = 0;
	if(nmr_bytes > 1){	
		for(; i < (nmr_bytes-1);){
			DirtyDawg.TWI_Receive_Buffer[i++] = TWI_Read_Ack();
		}
	}

	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	DirtyDawg.TWI_Receive_Buffer[i] = TWDR;
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
	
}

uint8_t TWI_Read_Ack(void){
	
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!TWI_Busy());
	
	return 	TWDR;
}	



/*

TWI with interrupt
TWI_read(){
	TWCR = (1<<TWEN) | (1<<TWIE) | (1<<TWINT) | (1<<TWEA)
}

ISR(TWI_vect){
	switch(TWSR)
	
	case (READ_ACK)
		Msg_load[0] = TWDR;
	case ...
	
	


*/