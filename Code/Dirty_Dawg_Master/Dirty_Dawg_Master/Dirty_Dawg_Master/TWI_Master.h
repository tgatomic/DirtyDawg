/*
 * TWI_Master.h
 *
 * Created: 2016-04-26 09:18:48
 *  Author: Atomic
 */ 


#ifndef TWI_MASTER_H_
#define TWI_MASTER_H_

/************************************************************************/
/*							Master Transmit Mode						*/
/*								MT for short							*/
/************************************************************************/
#define MT_ADDRESS_ACK 0x18
#define MT_ADDRESS_NACK 0x20
#define MT_BYTE_ACK 0x28
#define MT_BYTE_NACK 0x30
#define MT_ARBITRATION_LOST 0x38


/************************************************************************/
/*							Master Receive Mode                         */
/*								MR for short							*/
/************************************************************************/
#define MR_ADDRESS_ACK 0x40
#define MR_ADDRESS_NACK 0x48
#define MR_BYTE_ACK 0x50
#define MR_BYTE_NACK 0x58
#define MR_ARBITRATION_LOST 0x38

/************************************************************************/
/*									Misc.							    */
/************************************************************************/
#define MASK 0xF8
#define START 0x08
#define REPEAT_START 0x10

#define ATTINY1 0x1A
#define ATTINY2 0x06


void TWI_Master_Init(void);
int TWI_Busy(void);
void TWI_Send(uint8_t slaveAddress, uint8_t data);
void TWI_Receive(uint8_t slaveAddress, uint8_t nmr_bytes);
uint8_t TWI_Read_Ack(void);








#endif /* TWI_MASTER_H_ */

/*
TWI_Init_Slave(void){
	
	TWAR = addr;
	TWCR = (1<<TWEN);
		
	
}

ISR(TWI_vect){
	switch(twsr){
		case....
	}
}

*/