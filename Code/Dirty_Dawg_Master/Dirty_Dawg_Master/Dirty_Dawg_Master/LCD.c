/*
 * LCD.c
 *
 * Created: 2016-05-04 11:05:46
 *  Author: Atomic
 */ 

#include <avr/io.h>
#include <util/delay.h>
//#include <avr/pgmspace.h>
//#include <inttypes.h>
#include "TWI_Master.h"
#include "LCD.h"


void LCD_Init(uint8_t addr){
	

	
	_delay_ms(8000);
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = 0x0; //8bits 
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);	
		
	_delay_ms(8000);
	

	/************************************************************************/
	/* Initial write to LCD i 8 bit                                         */
	/************************************************************************/
	
	uint8_t dataport = 0;
	

	
	dataport |= (1<<LCD_DATA1_PIN);
	dataport |= (1<<LCD_DATA0_PIN);
	
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(8000);
		

	/************************************************************************/
	/* Toggle pin					                                        */
	/************************************************************************/


	for(int i = 0; i<3; i++){	
		
		//Sends the start condition
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
		while(!TWI_Busy());
		if((TWSR & MASK) != START)Error(START);
		
		//Loads the slave address and set the R/W bit to 1
		TWDR = (addr<<1) | (1<<0);
		TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
		while(!TWI_Busy());
		if((TWSR & MASK) != MR_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
		
		//Sends the data to the slave
		TWDR = 1<<4; //8bits
		TWCR = (1<<TWINT) | (1<<TWEN);
		while(!TWI_Busy());
		if((TWSR & MASK) !=  MR_BYTE_NACK)Error(MR_BYTE_NACK);
		
		//Sends the stop condition
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
		_delay_ms(4000);
	
	
		//Sends the start condition
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
		while(!TWI_Busy());
		if((TWSR & MASK) != START)Error(START);
		
		//Loads the slave address and set the R/W bit to 1
		TWDR = (addr<<1) | (1<<0);
		TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
		while(!TWI_Busy());
		if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
		
		//Sends the data to the slave
		TWDR = (0<<4); //8bits
		TWCR = (1<<TWINT) | (1<<TWEN);
		while(!TWI_Busy());
		if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
		
		//Sends the stop condition
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		
		_delay_ms(4000);
	
	}

	/************************************************************************/
	/* Set for 4 bit instead		                                        */
	/************************************************************************/	
		
	dataport &= ~_BV(LCD_DATA0_PIN);	
		
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);	
		
	_delay_ms(8000);

				
	/************************************************************************/
	/* Toggle pin					                                        */
	/************************************************************************/
		
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
		
	//Sends the data to the slave
	TWDR = 1<<4; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error(MR_BYTE_NACK);
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		
		
	_delay_ms(4000);
		
		
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
		
	//Sends the data to the slave
	TWDR = (0<<4); //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error(MR_BYTE_NACK);
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		
	_delay_ms(8000);
		

		
		
		
		
		
		
		
		
	//Sends the data to the slave
	//TWDR = 0x28;
	//TWCR = (1<<TWINT) | (1<<TWEN);
	//while(!TWI_Busy());
	//if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	
	//Sends the data to the slave
	//TWDR = 0b00001110;
	//TWCR = (1<<TWINT) | (1<<TWEN);
	//while(!TWI_Busy());
	//if((TWSR & MASK) != MT_BYTE_ACK)Error(MT_BYTE_ACK);	
		
		
	//Sends the stop condition
	//TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
	
	
	
	//TWI_Send((0x27, LCD_DISPLAY_ON)



}

void LCD_Command(uint8_t command){
	
	
	uint8_t dataport = 0;
	
	dataport &= (0<<LCD_RS_PIN);
	dataport &= (0<<LCD_RW_PIN);
	

	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		
	_delay_ms(4000);
	
	dataport &= (0<<LCD_DATA3_PIN);
	dataport &= (0<<LCD_DATA2_PIN);
	dataport &= (0<<LCD_DATA1_PIN);
	dataport &= (0<<LCD_DATA0_PIN);
	if(command & 0x80) dataport |= (1<<LCD_DATA3_PIN);
	if(command & 0x40) dataport |= (1<<LCD_DATA2_PIN);
	if(command & 0x20) dataport |= (1<<LCD_DATA1_PIN);
	if(command & 0x10) dataport |= (1<<LCD_DATA0_PIN);
	
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	
	LCD_toggle();
	
	dataport &= (0<<LCD_DATA3_PIN);
	dataport &= (0<<LCD_DATA2_PIN);
	dataport &= (0<<LCD_DATA1_PIN);
	dataport &= (0<<LCD_DATA0_PIN);
	if(command & 0x08) dataport |= (1<<LCD_DATA3_PIN);
	if(command & 0x04) dataport |= (1<<LCD_DATA2_PIN);
	if(command & 0x02) dataport |= (1<<LCD_DATA1_PIN);
	if(command & 0x01) dataport |= (1<<LCD_DATA0_PIN);
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		
	_delay_ms(4000);
		
	LCD_toggle();
		
	dataport |= (1<<LCD_DATA0_PIN);
	dataport |= (1<<LCD_DATA1_PIN);
	dataport |= (1<<LCD_DATA2_PIN);
	dataport |= (1<<LCD_DATA3_PIN);
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
}

void LCD_toggle(void){
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
	
	//Sends the data to the slave
	TWDR = 1<<4; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error(MR_BYTE_NACK);
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
	_delay_ms(4000);
	
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = (0<<4); //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	

	
	
	
}

void LCD_Print(uint8_t command){
	
	uint8_t dataport = 0;
	
	dataport |= (1<<LCD_RS_PIN);
	dataport &= (0<<LCD_RW_PIN);
	

	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	
	dataport &= (0<<LCD_DATA3_PIN);
	dataport &= (0<<LCD_DATA2_PIN);
	dataport &= (0<<LCD_DATA1_PIN);
	dataport &= (0<<LCD_DATA0_PIN);
	if(command & 0x80) dataport |= (1<<LCD_DATA3_PIN);
	if(command & 0x40) dataport |= (1<<LCD_DATA2_PIN);
	if(command & 0x20) dataport |= (1<<LCD_DATA1_PIN);
	if(command & 0x10) dataport |= (1<<LCD_DATA0_PIN);
	
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	
	LCD_toggle();
	
	dataport &= (0<<LCD_DATA3_PIN);
	dataport &= (0<<LCD_DATA2_PIN);
	dataport &= (0<<LCD_DATA1_PIN);
	dataport &= (0<<LCD_DATA0_PIN);
	if(command & 0x08) dataport |= (1<<LCD_DATA3_PIN);
	if(command & 0x04) dataport |= (1<<LCD_DATA2_PIN);
	if(command & 0x02) dataport |= (1<<LCD_DATA1_PIN);
	if(command & 0x01) dataport |= (1<<LCD_DATA0_PIN);
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	
	LCD_toggle();
	
	dataport |= (1<<LCD_DATA0_PIN);
	dataport |= (1<<LCD_DATA1_PIN);
	dataport |= (1<<LCD_DATA2_PIN);
	dataport |= (1<<LCD_DATA3_PIN);
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (1<<0);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MR_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	
	
	
	
}