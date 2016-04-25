
#include "functions.h"
#include <avr/io.h>


void System_Init(void){
	
	status = 0;
	
	/*Setting ports - page 75*/
	PORTB = (1<<BRAKELIGHT) | (1<<HEADLIGHT);
	DDRB = (1<<BRAKELIGHT) | (1<<HEADLIGHT);
	
	PORTD = (1<<FORWARD) | (1<<BACKWARD) | (1<<LEFT) | (1<<RIGHT);
	DDRD = (1<<FORWARD) | (1<<BACKWARD) | (1<<LEFT) | (1<<RIGHT);
	
	PORTC = (1<<LIGHTSENSOR);
	
	status = MCU_STARTED;
}

void UART_Init(unsigned int baud){
	
		
	//Initiate in asynchronous mode
	UCSR0C &= ~(1<<7) & ~(1<<6);

	//Set baudrate
	unsigned int baudrate;
	baudrate = 8000000/16/baud;
	//Double speed use frequency/8/baud
	
	//Set the baudrate in the registry
	UBRR0H = (unsigned char) (baudrate>>8);
	UBRR0L = (unsigned char) (baudrate>>8);
	
	//Enables Receive and Transmit over UART
	UCSR0B = (1<<RXEN0) | (1<<TXEN0)
	
	//Sets to 1 stop bit and 8 databits
	UCSR0C &= ~(1<<USBS0) | (3<<UCSZ00);
	
	//Disables Parity
	UCSR0C &= ~(1<<UPM01) & ~(1<<UPM00);
	
	
	status |= UART_STARTED;
	
	
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
	
	//Put data in buffer ad sends it
	UDR0 = data;
}

void Uart_Flush(void){
	unsigned char dummy;
	while (UCSR0A & (1<<RXC0)) dummy = UDR0;	
}

void BT_Init(void){
	
	for(int i = 0; i<3; i++) BT_Send('$');
	if(BT_Recieve() == 'E'){
		Error(0x01);
	}
	BT_Send('C');
	BT_Send(',');
	BT_Send(BT121ADRESS);

}

void I2C_Init(void){
	
	
}

void BT_Connect(void){
	
	
}

void Connected(void){
	
	
}

void INT_Crash(void){
	
	
}

void Lowrider_Mode(void){
	
	
}

void Sense_Light(void){
	
	
}

void Error(unsigned int errorcode){
	
	//Flashes the red lights and send errorcode through Bluetooth
	unsigned long ticks = 0;
	for(;;){
		if(ticks%100000 = 0){
			PINB = (1<<BRAKELIGHT);
			BT_Send(errorcode);
		}
		if(ticks%100000 = 50000){
			PINB = ~(1<<BRAKELIGHT);
		}
		ticks++;
	}
}