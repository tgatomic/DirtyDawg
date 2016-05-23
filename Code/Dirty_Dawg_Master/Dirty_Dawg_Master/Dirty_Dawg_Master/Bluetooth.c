/*
 * Bluetooth.c
 *
 * Created: 2016-05-13 16:35:15
 *  Author: Atomic
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Bluetooth.h"
#include "functions.h"
#include "Error_Codes.h"
#include "TWI_LCD.h"


void BT_Pair(void){
	
	//As long as the button is pressed
	while(1){
		//Sends command to enter command mode
		for(int i = 0; i<3; i++) BT_Send('$');

		//If it fails to go into command mode
		if(BT_Recieve() == 'E'){
			Error(CMD_FAIL);
		}
	
		Uart_Flush();
	
		unsigned char adress[12] = {'0','0','0','6','6','6','7','6','A','1','3','F'};
	
		BT_Send('c');
		BT_Send(',');
		for(int i = 0; i < 12;i++){
			BT_Send(adress[i]);
		}
		BT_Send(0x0A); //NL
		BT_Send(0x0D); //CR
	}
	
}


void UART_Init(unsigned int baud){
	
	//Set double speed
	UCSR0A = (1<<U2X0);
	
	//Set baudrate
	unsigned int baudrate;
	baudrate = 8000000/8/baud-1;
	//Double speed use frequency/8/baud
	
	//Set the baudrate in the registry
	UBRR0H = (unsigned char) (baudrate>>8);
	UBRR0L = (unsigned char) (baudrate);

	
	//Enables Receive and Transmit over UART
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0); 
	
	//Sets to 1 stop bit and 8 data bits
	UCSR0C = (0<<USBS0) | (3<<UCSZ00);
	
	//Disables Parity
	UCSR0C |= (0<<UPM01) | (0<<UPM00);
	

}


uint8_t BT_Recieve(void){
	
	//Wait for data to be received (wait for flag to be set)
	while(!(UCSR0A & (1<<RXC0)));
	
	//Returns the data from buffer
	return UDR0;
}


void BT_Send(unsigned char data){
	
	//Waits for the transmit buffer to be empty (wait for flag)
	while(!(UCSR0A & (1<<UDRE0)));
	
	//Put data in buffer and sends it
	UDR0 = data;

}


void Uart_Flush(void){
	unsigned char dummy;
	while (UCSR0A & (1<<RXC0)) dummy = UDR0;
}


void Error(unsigned int errorcode){
	
	//Flashes the red lights and send errorcode through Bluetooth
	unsigned long ticks = 0;
	for(;;){
		if(ticks%10000 == 0){
			PINB = (1<<BRAKELIGHT);
			BT_Send(errorcode);
		}
		if(ticks%10000 == 50000){
			PINB = (0<<BRAKELIGHT);
		}
		ticks++;
	}
}

//Interrupt for UART
ISR(USART_RX_vect){
	
	LCD_Byte(UDR0, LCD_CHR);
	
	_delay_ms(1000);
	LCD_Byte(0x01, LCD_CMD);
	_delay_ms(250);
	
	//int i;
	
	// Receives the total number of bytes
	//uint8_t nmbr_bytes = UDR0;
	
	// Saves it in the buffer
	//for( i = 0; i < nmbr_bytes; i++){
		//DirtyDawg->BT_recieve_buffer[i] = BT_Recieve();
	//}
	
	// Test with echoing back the packages
	//for( i = 0; i < nmbr_bytes; i++){
		///BT_Send(DirtyDawg->BT_recieve_buffer[i]);
	//}
	
}

//Activates if the pairing button is pressed
ISR(PCINT2_vect){
	BT_Pair();
}
