/*
 * Bluetooth.c
 *
 * Created: 2016-05-13 16:35:15
 *  Author: Atomic
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Bluetooth.h"
#include "functions.h"


int BT_Init(void){
	
	
	//Wait for 1 second to ensure the device has power
	_delay_ms(8000);

	//Sends command to enter command mode
	for(int i = 0; i<3; i++) BT_Send('$');

	//If it fails to go into command mode
	if(BT_Recieve() == 'E'){
		Error(0x01);
	}
	//Wait for 1 second to ensure the device has power
	_delay_ms(8000);
	
	Uart_Flush();
	
	unsigned char adress[12] = {'0','0','0','6','6','6','7','6','A','1','3','F'};
	
	BT_Send('c');
	BT_Send(',');
	for(int i = 0; i < 12;i++){
		BT_Send(adress[i]);
	}
	BT_Send(0x0A); //NL
	BT_Send(0x0D); //CR

	//Wait two seconds
	//_delay_ms(8000);
	_delay_ms(8000);
	
	for(int i = 0; i<6;i++){
		BT_Recieve();
	}
	
	
	if(BT_Recieve() == '%'){
		PORTB = (1<<PORTB1);
		Uart_Flush();
		return 1;
		/*
		if(BT_Recieve()=='C'){
			status |= BT_CONNECTED;
		}
		else if(BT_Recieve()=='E'){
			Error('E');
		}*/
	}
	return 0;
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
	UCSR0B = (1<<RXEN0) | (1<<TXEN0); //RXCIE och TXCIE for interrupt based UART.
	
	//Sets to 1 stop bit and 8 databits
	UCSR0C = (0<<USBS0) | (3<<UCSZ00);
	
	//Disables Parity
	UCSR0C |= (0<<UPM01) | (0<<UPM00);
	
	
	status |= UART_STARTED;
}


uint8_t BT_Recieve(void){
	
	//Wait for data to be received (wait for flag to be set)
	while(!(UCSR0A & (1<<RXC0)));
	
	//Returns the data from buffer
	return UDR0;
}


void BT_Send(unsigned char data){
	
	//PORTB = ~(1<<PORTB1);
	//_delay_ms(1000);
	//Waits for the transmit buffer to be empty (wait for flag)
	while(!(UCSR0A & (1<<UDRE0)));
	
	//Put data in buffer and sends it
	UDR0 = data;
	//PORTB = (1<<PORTB1);
	//_delay_ms(1000);
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

/*
Interrupt based UART
ISR(USART_RX_vect){
	BT_Recieve = UART;
}
*/