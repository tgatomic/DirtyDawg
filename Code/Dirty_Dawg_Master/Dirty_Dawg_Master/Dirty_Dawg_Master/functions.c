
#include <avr/io.h>
#include <util/delay.h>
#include "functions.h"



void System_Init(void){
	
	status = 0;
	
	/*Setting ports - page 75*/
		
	DDRB = (1<<BRAKELIGHT) | (1<<HEADLIGHT) | (1<<RIGHT) | (1<<PORTB0); //PB0 is debug greenlight
	DDRD = (1<<FORWARD) | (1<<BACKWARD) | (1<<LEFT) | (1<<PORTD7); //PD7 is debug yellow
	
	//Turn on the front and backlights
	_delay_ms(8000);
	PORTB = (1<<BRAKELIGHT) | (1<<HEADLIGHT) | (1<<PORTB0);
	_delay_ms(8000);
	PORTB = (0<<BRAKELIGHT) | (0<<HEADLIGHT) | (0<<PORTB0);
	

	//Signs the status
	status = MCU_STARTED;
	
	
	//PORT is output register
	//Pin is input register
	
	
	
	
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

void Y_LED_On(void){
	PORTD |= (1<<PORTD7);
}
void Y_LED_Off(void){
	PORTD &= (0<<PORTD7);
}
	