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
	
	//0x27 address to LCD Display
	
	
	_delay_ms(8000);
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | LCD_WRITE;
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = 0x0; //8bits 
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);	
	
	
	_delay_ms(2000);
	

	
	/************************************************************************/
	/* Initial write to LCD i 8 bit                                         */
	/************************************************************************/
	

	dataport |= (1<<LCD_DATA1_PIN);
	dataport |= (1<<LCD_DATA0_PIN);
	
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (LCD_WRITE);
	TWCR = (1<<TWINT) | (1<<TWEN); 
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(8000);
		

	
	/************************************************************************/
	/* Toggle pin					                                        */
	/************************************************************************/

	LCD_toggle();
	_delay_ms(4000);
	LCD_toggle();
	_delay_ms(1000);
	LCD_toggle();
	_delay_ms(1000);
	


	/************************************************************************/
	/* Set for 4 bit instead		                                        */
	/************************************************************************/	
		
	dataport &= (0<<LCD_DATA0_PIN);
	
		
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (addr<<1) | (LCD_WRITE);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);	
		
		
	/************************************************************************/
	/* Toggle pin					                                        */
	/************************************************************************/
	_delay_ms(1000);
	LCD_toggle();
	_delay_ms(8000);


	LCD_Command(0x28); //4bit two line
	_delay_ms(8000);
	

			
			
	LCD_Command(0x08); //display off
	_delay_ms(8000);
	LCD_Command(0x01); //Clear screen

	_delay_ms(8000);
	uint8_t mode = 0;
	mode = (1<<LCD_ENTRY_MODE)|(1<<LCD_ENTRY_INC);
	LCD_Command(mode);//D MODE FEDAULT
	_delay_ms(8000);

	LCD_Command(0x0F); //Dispattr
	
												Y_LED_On();
												while(1);
	_delay_ms(8000);
	

	LCD_Print('S');
	




}

void LCD_Command(uint8_t command){

	
	dataport &= (0<<LCD_RS_PIN);
	dataport &= (0<<LCD_RW_PIN);
	

	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
	
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (LCD_WRITE);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
		
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_BYTE_ACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

	
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
	if((TWSR & MASK) != REPEAT_START)Error((TWSR & MASK));
	


	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (LCD_WRITE);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	

	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
	
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
	if((TWSR & MASK) != REPEAT_START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (LCD_WRITE);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
	

		
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
		
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
	if((TWSR & MASK) != REPEAT_START)Error(START);


	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | (LCD_WRITE);
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
	
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

	_delay_ms(4000);
}

void LCD_toggle(void){
	
	LCD_set_outputpinhigh();
	_delay_ms(4000);
	LCD_set_outputpinlow();
	
}

void LCD_Print(uint8_t command){
	

	
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
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
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
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
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
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error((TWSR & MASK));
	
	//Sends the data to the slave
	TWDR = dataport; //8bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MR_BYTE_NACK)Error((TWSR & MASK));
	
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	_delay_ms(4000);
	
	
	
	
}

void LCD_set_outputpinhigh(void){
	
		uint8_t b = 0;
		
		b |= (1<<LCD_E_PIN);
		
		//Sends the start condition
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
			
		while(!TWI_Busy());
		if((TWSR & MASK) != START)Error(START);
			
		//Loads the slave address and set the R/W bit to 1
		TWDR = (0x27<<1) | LCD_WRITE;
		TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
			
		while(!TWI_Busy());
		if((TWSR & MASK) != MT_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
			
		//Sends the data to the slave
		TWDR = b; //8bits
		TWCR = (1<<TWINT) | (1<<TWEN);
		while(!TWI_Busy());
		if((TWSR & MASK) !=  MT_BYTE_ACK)Error(MT_BYTE_ACK);
			
		//Sends the stop condition
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
}
LCD_set_outputpinlow(){
	
		uint8_t b = 0;
			
		b &= (0<<LCD_E_PIN);
			
		//Sends the start condition
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
			
		while(!TWI_Busy());
		if((TWSR & MASK) != START)Error(START);
			
		//Loads the slave address and set the R/W bit to 1
		TWDR = (0x27<<1) | LCD_WRITE;
		TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
			
		while(!TWI_Busy());
		if((TWSR & MASK) != MT_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
			
		//Sends the data to the slave
		TWDR = b; //8bits
		TWCR = (1<<TWINT) | (1<<TWEN);
		while(!TWI_Busy());
		if((TWSR & MASK) !=  MT_BYTE_ACK)Error(MR_BYTE_NACK);
			
		//Sends the stop condition
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
	
}
void LCD_Busy(void){
	
	
	
	

	
	
}

uint8_t LCD_Read(){
	
	dataport &= (0<<LCD_RS_PIN);	
	dataport |= (1<<LCD_RW_PIN);
	
	uint8_t data = 0;
	
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 1
	TWDR = (0x27<<1) | LCD_WRITE;
	TWCR = (1<<TWINT) | (1<<TWEN); //MAYBE 1<<TWEA also???
		
	while(!TWI_Busy());
	if((TWSR & MASK) != MT_ADDRESS_ACK)Error(MR_ADDRESS_ACK);
		
	//Sends the data to the slave
	TWDR = dataport;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error(MR_BYTE_NACK);
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
	LCD_set_outputpinhigh();
	_delay_ms(4000);
	

}