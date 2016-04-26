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
#define MT_START 0x08
#define MT_REPEAT_START 0x10
#define MT_ADDRESS_ACK 0x18
#define MT_ADDRESS_NACK 0x20
#define MT_BYTE_ACK 0x28
#define MT_BYTE_NACK 0x30
#define MT_ARBITRATION_LOST 0x38



/************************************************************************/
/*							Master Receive Mode                         */
/*								MR for short							*/
/************************************************************************/
#define MR_START 0x08
#define MR_REPEAT_START 0x10
#define MR_ADDRESS_ACK 0x40
#define MR_ADDRESS_NACK 0x48
#define MR_BYTE_ACK 0x50
#define MR_BYTE_NACK 0x58
#define MR_ARBITRATION_LOST 0x38

/************************************************************************/
/*									Misc.							    */
/************************************************************************/
#define MASK 0xF8


void TWI_Master_Init(void);






#endif /* TWI_MASTER_H_ */