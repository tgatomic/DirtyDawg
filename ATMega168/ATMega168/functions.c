
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"
#include "main.h"
#include "TWI_LCD.h"

uint8_t LCD_initiated = FALSE;

void System_Init(void){
	
	status = 0;
	
	// Enable global interrupt
	sei();
	// Enable interrupt on PCINT20 (pin 6 on AtMega 168P)
	EICRA = (1<<ISC11);
	EIMSK = (1<<INT1);
	PCICR = (1<<PCIE2);
	PCMSK2 = (1<<PCINT20);
	
	/*Setting ports - page 75*/
		
	DDRB = (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB0); //PB0 is debug greenlight
	DDRD = (1<<PORTD3) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7); //PD7 is debug yellow
	
	//Turn on the front and backlights
	_delay_ms(8000);
	PORTB = (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB0);
	_delay_ms(8000);
	PORTB = (0<<PORTB1) | (0<<PORTB2) | (0<<PORTB0);
	

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
	UCSR0B = (1<<RXEN0) | (1<<TXEN0); //RXCIE and TXCIE for interrupt based UART.
	
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

	for(int i = 0; i<3; i++) BT_Send('-');
	BT_Send(0x0A); //NL
	BT_Send(0x0D); //CR
	_delay_ms(1000);
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	_delay_ms(150); //5 ms delay
	Uart_Flush();
	
	return 0;
}

void BT_Connect(void){

	//Wait for 1 second to ensure the device has power
	_delay_ms(8000);

	for(int i = 0; i < 3; i++) BT_Send('-');
	BT_Send(LF); //Line feed
	BT_Send(CR); //Carriage return
	_delay_ms(1000);
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	_delay_ms(150); //5 ms delay
	Uart_Flush();

	//Sends command to enter command mode
	for(int i = 0; i < 3; i++) BT_Send('$');

	//Sends response to LCD screen
	LCD_Byte(BT_Recieve(), LCD_CHR);
	LCD_Byte(BT_Recieve(), LCD_CHR);
	LCD_Byte(BT_Recieve(), LCD_CHR);

	Uart_Flush();
		
	// Adress to bluesmirf in the car
	unsigned char adress[12] = {'0','0','0','6','6','6','7','6','A','0','A','A'};
		
	// Command to connect with bluesmirf in the car
	BT_Send('c');
	BT_Send(',');
	for(int i = 0; i < 12;i++){
		BT_Send(adress[i]);
	}
	BT_Send(LF);
	BT_Send(CR);

	while(BT_Recieve() != LF);

	// Wait a second
	_delay_ms(1000);
	
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
			PINB = (1<<PORTB1);
			BT_Send(errorcode);
		}
		if(ticks%10000 == 50000){
			PINB = (0<<PORTB1);
		}
		ticks++;
	}
}

void LCD_Update(void){
	
	// Initiate the distance screen
	if(!LCD_initiated){
		LCD_String(ROW1, ARR_SIZE(ROW1), ROW2, ARR_SIZE(ROW2));
		LCD_initiated = TRUE;
	}
	
	itoa(DirtyDawg.front_sensor, front, 10);
	itoa(DirtyDawg.back_sensor, back, 10);
//	itoa(DirtyDawg.left_sensor, left, 10);
	left[0] = DirtyDawg.left_sensor / 100;
	left[1] = (DirtyDawg.left_sensor - (left[0] * 100 )) / 10;
	left[2] = (DirtyDawg.left_sensor - (left[0] * 100 )) - left[1] * 10;

	for(int i = 0; i < 3; i++)
		left[i] += '0';
		
	itoa(DirtyDawg.right_sensor, right, 10);
	// Prints the distance to front obstacle
	LCD_Byte(LCD_LINE_1 + 3, LCD_CMD);
	for(int i = 0; i < 3; i++)
	LCD_Byte(front[i], LCD_CHR);
	
	// Prints the distance to back obstacle
	LCD_Byte(LCD_LINE_1 + 11, LCD_CMD);
	for(int i = 0; i < 3; i++)
	LCD_Byte(back[i], LCD_CHR);

	// Prints the distance to left obstacle
	LCD_Byte(LCD_LINE_2 + 3, LCD_CMD);
	for(int i = 0; i < 3; i++)
	LCD_Byte(left[i], LCD_CHR);

	// Prints the distance to right obstacle
	LCD_Byte(LCD_LINE_2 + 11, LCD_CMD);
	for(int i = 0; i < 3; i++)
	LCD_Byte(right[i], LCD_CHR);
	_delay_ms(250);

	//Change state
	DirtyDawg.state = GET_DATA_STATE;
}
void BT_Send_Data(void){
	
	BT_Send(DirtyDawg.accelerometer);
	BT_Send(DirtyDawg.ECG);
	
	//Change state
}

void BT_Recieve_Data(void){
	// Get IR sensor data from the car
	BT_Send('X');
	BT_Send('J');
//	Yellow_LED_On();
/*	if(BT_Recieve() == 'S'){
		DirtyDawg.front_sensor = BT_Recieve();
		DirtyDawg.back_sensor = BT_Recieve();
		DirtyDawg.left_sensor = BT_Recieve();
		DirtyDawg.right_sensor = BT_Recieve();
	}*/
//	Yellow_LED_Off();
	BT_Send('O');
	BT_Send('B');
	BT_Send('E');
	BT_Send('Y');
	// Change state 
	DirtyDawg.state = LCD_STATE;
}

// Lights for debugging reason
void Yellow_LED_On(void){
	PORTD |= (1<<PORTD7);
}
void Yellow_LED_Off(void){
	PORTD &= (0<<PORTD7);
}

void Red_LED_On(void){
	PORTB |= (1<<PORTB1);
}
void Red_LED_Off(void){
	PORTB &= (0<<PORTB1);
}

void Green_LED_On(void){
	PORTD |= (1<<PORTD6);
}
void Green_LED_Off(void){
	PORTD &= (0<<PORTD6);
}
	