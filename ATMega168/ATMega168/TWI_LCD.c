/*
 * TWI_LCD.c
 *
 * Created: 2016-05-11 11:15:44
 *  Author: Atomic
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "TWI_Master.h"
#include "TWI_LCD.h"


void LCD_Init(void){
	
	// Basic initialization
	LCD_Byte(0x33, LCD_CMD); 
	LCD_Byte(0x32, LCD_CMD);
	 
	// Entry mode, move cursor left to right 
	LCD_Byte(0x06, LCD_CMD); 
	
	// Display on, Cursor off, Blink off
	LCD_Byte(0x0C, LCD_CMD); 
	
	// Set to 4-bit operation, 2 lines and 5x7 dots
	LCD_Byte(0x28, LCD_CMD); 
	
	// Clears display and DDRAM
	LCD_Byte(0x01, LCD_CMD); 
	_delay_ms(5); //5 ms delay
	
}

void LCD_Byte(uint8_t bits, uint8_t mode){
	
	uint8_t bits_high, bits_low;
	
	//Divides the data in two 4 bit values
	bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT;
	bits_low = mode | ((bits<<4) & 0xF0) | LCD_BACKLIGHT;
	
	// Send the high bits
	Write_Byte(LCD_ADDR, bits_high);
	LCD_Toggle_enable(bits_high);
	
	// Send the low bits
	Write_Byte(LCD_ADDR, bits_low);
	LCD_Toggle_enable(bits_low);
	
}

void LCD_Toggle_enable(uint8_t bits){
	
	// Toggles the enable pin on the display to activate the code
	_delay_ms(5);
	Write_Byte(LCD_ADDR, (bits | ENABLE));
	_delay_ms(5);
	Write_Byte(LCD_ADDR, (bits & ~ENABLE));
	_delay_ms(5);
		
}

void Write_Byte(uint8_t addr, uint8_t bits){
			
	//Sends the start condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
		
	while(!TWI_Busy());
	if((TWSR & MASK) != START)Error(START);
		
	//Loads the slave address and set the R/W bit to 0
	TWDR = (addr<<1) | LCD_WRITE;
	TWCR = (1<<TWINT) | (1<<TWEN); 
		
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_ADDRESS_ACK)Error((TWSR & MASK));
		
	//Sends the data to the slave
	TWDR = bits; //4bits
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!TWI_Busy());
	if((TWSR & MASK) !=  MT_BYTE_ACK)Error((TWSR & MASK));
		
	//Sends the stop condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
}

void LCD_String(uint8_t *text){
	
	while(*text){
		LCD_Byte(*text++, LCD_CHR);
	}
}