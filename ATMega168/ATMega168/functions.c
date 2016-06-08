
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"
#include "main.h"
#include "TWI_LCD.h"
#include "SWUART.H"


void System_Init(void){
	
	DirtyDawg.status = 0;
	DirtyDawg.front_sensor = 0;
	DirtyDawg.back_sensor = 0;
	DirtyDawg.left_sensor = 0;
	DirtyDawg.right_sensor = 0;
	
	// Enable global interrupt
	sei();
	// Enable interrupt on 
	// PCINT20 (pin 6 on AtMega 168P)
	// PCINT21 (pin 11 on AtMega 168P)
	EICRA = (1<<ISC11);
	EIMSK = (1<<INT1);
	PCICR = (1<<PCIE2);
	PCMSK2 = (1<<PCINT20) | (1<<PCINT21);
	
	/*Setting ports - page 75*/
		
	DDRB = (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB0); //PB0 is debug greenlight
	DDRD = (1<<PORTD3) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7); //PD7 is debug yellow
	
	//Turn on the front and backlights
	_delay_ms(2000);
	PORTB = (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB0);
	_delay_ms(2000);
	PORTB = (0<<PORTB1) | (0<<PORTB2) | (0<<PORTB0);
	

	//Signs the status
	DirtyDawg.status = MCU_STARTED;
	
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
	
	// Set status flag
	DirtyDawg.status |= UART_STARTED;
}

void LCD_Update(void){
	
	// Prints the distance to front obstacle
	LCD_Byte(LCD_LINE_1, LCD_CMD);
	LCD_String("F: ");
	for(int i = 0; i < 3; i++)
		LCD_Byte(front[i], LCD_CHR);
	
	// Prints the distance to back obstacle
	LCD_String("  B: ");
	for(int i = 0; i < 3; i++)
		LCD_Byte(back[i], LCD_CHR);

	// Prints the distance to left obstacle
	LCD_Byte(LCD_LINE_2, LCD_CMD);
	LCD_String("L: ");
	for(int i = 0; i < 3; i++)
		LCD_Byte(left[i], LCD_CHR);

	// Prints the distance to right obstacle
	LCD_String("  R: ");
	for(int i = 0; i < 3; i++)
		LCD_Byte(right[i], LCD_CHR);

	//Change state
	DirtyDawg.state = SEND_DATA_STATE;
}

void Uart_Flush(void){
	uint8_t dummy;
	while (UCSR0A & (1<<RXC0)) 
		dummy = UDR0;	
}

/************************************************************************/
/*                 Functions for the BlueSmirf                          */
/************************************************************************/
void BT_Init(void){
	
	//Wait for 1 second to ensure the device has power
	_delay_ms(1000);

	// Send "---" to ensure BlueSmirf is not in command mode
	for(int i = 0; i<3; i++) BT_Send('-');
	BT_Send(0x0A); //NL
	BT_Send(0x0D); //CR
	_delay_ms(1000);
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	_delay_ms(150);
	Uart_Flush();

}

void BT_Connection_Check(void){
	
	// Send command to end command mode
	for(int i = 0; i < 3; i++) BT_Send('-');

	BT_Send(LF); //Line feed
	BT_Send(CR); //Carriage return
	_delay_ms(1000);
	Uart_Flush();

	//Sends command to enter command mode
	for(int i = 0; i < 3; i++) BT_Send('$');

	// Ignore the message from BlueSmirf "CMD"
	while(BT_Recieve() != LF);

	// Check if connected
	BT_Send('G');
	BT_Send('K');
	BT_Send(LF);
	BT_Send(CR);

	if(BT_Recieve() == '1')
		DirtyDawg.status |= BT_CONNECTED;
	else
		DirtyDawg.status &= ~BT_CONNECTED;

	Uart_Flush();
	
	// End command mode
	for(int i = 0; i < 3; i++) BT_Send('-');

	BT_Send(LF); //Line feed
	BT_Send(CR); //Carriage return
	_delay_ms(1000);
	Uart_Flush();

}

void BT_Connect(void){

	//Wait for 1 second to ensure the device has power
	_delay_ms(1000);

	for(int i = 0; i < 3; i++) BT_Send('-');

	BT_Send(LF); //Line feed
	BT_Send(CR); //Carriage return
	_delay_ms(1000);
	LCD_Byte(LCD_LINE_2 + 1, LCD_CMD);
	LCD_Byte('*', LCD_CHR);
	LCD_Byte(LCD_LINE_2 + 14, LCD_CMD);
	LCD_Byte('*', LCD_CHR);
	Uart_Flush();

	//Sends command to enter command mode
	for(int i = 0; i < 3; i++) BT_Send('$');

	// Ignore the message from BlueSmirf "CMD"
	while(BT_Recieve() != LF);

	Uart_Flush();
		
	// Address to BlueSmirf in the car
	uint8_t adress[12] = {'0','0','0','6','6','6','7','6','A','0','A','A'};
		
	// Command to connect with BlueSmirf in the car
	BT_Send('c');
	BT_Send(',');
	for(int i = 0; i < 12;i++){
		BT_Send(adress[i]);
	}
	BT_Send(LF);
	BT_Send(CR);

	// Ignore the message from BlueSmirf "TRYING"
	while(BT_Recieve() != LF);

	// If a good connection, set status
	if(BT_Recieve() == '%')
		DirtyDawg.status |= BT_CONNECTED;

	// Ignore the message from BlueSmirf "CONNECTING"
	while(BT_Recieve() != LF);

	LCD_Byte(LCD_LINE_2 + 1, LCD_CMD);
	LCD_Byte(' ', LCD_CHR);
	LCD_Byte(LCD_LINE_2 + 14, LCD_CMD);
	LCD_Byte(' ', LCD_CHR);
	
}

void BT_Disconnect(void){

	//Wait for 1 second to ensure the device has power
	_delay_ms(1000);

	// Send "---" to ensure BlueSmirf is not in command mode
	for(int i = 0; i < 3; i++) BT_Send('-');

	BT_Send(LF); //Line feed
	BT_Send(CR); //Carriage return
	_delay_ms(1000);
	Uart_Flush();

	//Sends command to enter command mode
	for(int i = 0; i < 3; i++) BT_Send('$');

	// Ignore the message from BlueSmirf "CMD"
	while(BT_Recieve() != LF);

	Uart_Flush();
	
	// Command to disconnect with BlueSmirf in the car
	BT_Send('K');
	BT_Send(',');
	BT_Send(LF);
	BT_Send(CR);

	// Ignore the message from BlueSmirf "KILL"
	while(BT_Recieve() != LF);

	// If a good connection, set status
	if(BT_Recieve() == '%')
		DirtyDawg.status &= ~BT_CONNECTED;

	// Ignore the message from BlueSmirf "CONNECTING"
	Uart_Flush();	
}

uint8_t BT_Recieve(void){
	
	//Wait for data to be received (wait for flag to be set)
	while(!(UCSR0A & (1<<RXC0)));

	//Returns the data from buffer
	return UDR0;
}

void BT_Send(uint8_t data){
	
	//Waits for the transmit buffer to be empty (wait for flag)
	while(!(UCSR0A & (1<<UDRE0)));
	
	//Put data in buffer and sends it
	UDR0 = data;
}

void Error(unsigned int errorcode){
	
	//Flashes the red lights and send errorcode through Bluetooth
	unsigned long ticks = 0;
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	LCD_Byte(LCD_LINE_1 + 5, LCD_CMD);
	LCD_String("Error");
	for(;;){
		if(ticks%10000 == 0){
			Red_LED_On();
		}
		if(ticks%10000 == 50000){
			Red_LED_Off();
		}
		ticks++;
	}
}


void BT_Send_Data(void){
	
	uint8_t ECG_hi, ECG_lo;
	Green_LED_On();

//	sputchar( '-' );
//	while( !kbhit() );			// wait until byte received
	while(sgetchar() != 'S');

	DirtyDawg.accelerometer = sgetchar();
	ECG_hi = sgetchar();
	ECG_lo = sgetchar();

	if(DirtyDawg.accelerometer == TILT_LEFT)
		DirtyDawg.command |= TURN_LEFT;
	else if(DirtyDawg.accelerometer == TILT_RIGHT)
		DirtyDawg.command |= TURN_RIGHT;
	else
		DirtyDawg.command &= ~(TURN_LEFT | TURN_RIGHT);

	DirtyDawg.ECG = ECG_lo;
	BT_Send(DirtyDawg.command);
	BT_Send(DirtyDawg.ECG);
	// Clear flags
	// DirtyDawg.command = 0;

	//Change state
	DirtyDawg.state = GET_DATA_STATE;
}

void BT_Recieve_Data(void){
//	uint16_t timeout;
	uint8_t ch;
	Green_LED_Off();
//	timeout = 40000;
	ch = 0;
	Uart_Flush();
	// Wait for start command or timeout
	while((ch = BT_Recieve()) != 'S');
/*	while((ch != 'S') && (--timeout > 0)){
		if(UCSR0A & (1<<RXC0))
			ch = UDR0;
		if(timeout > 20000)
			Yellow_LED_On();
		else
			Yellow_LED_Off();
	}
*/
	// If start command received
	if(ch == 'S'){
		// Get IR sensor data from the car
		DirtyDawg.front_sensor = BT_Recieve();
		DirtyDawg.back_sensor = BT_Recieve();
		DirtyDawg.left_sensor = BT_Recieve();
		DirtyDawg.right_sensor = BT_Recieve();

		// Convert sensor value to ASCII
		front[0] = DirtyDawg.front_sensor / 100;
		front[1] = (DirtyDawg.front_sensor - (front[0] * 100 )) / 10;
		front[2] = (DirtyDawg.front_sensor - (front[0] * 100 )) - front[1] * 10;

		back[0] = DirtyDawg.back_sensor / 100;
		back[1] = (DirtyDawg.back_sensor - (back[0] * 100 )) / 10;
		back[2] = (DirtyDawg.back_sensor - (back[0] * 100 )) - back[1] * 10;

		left[0] = DirtyDawg.left_sensor / 100;
		left[1] = (DirtyDawg.left_sensor - (left[0] * 100 )) / 10;
		left[2] = (DirtyDawg.left_sensor - (left[0] * 100 )) - left[1] * 10;

		right[0] = DirtyDawg.right_sensor / 100;
		right[1] = (DirtyDawg.right_sensor - (right[0] * 100 )) / 10;
		right[2] = (DirtyDawg.right_sensor - (right[0] * 100 )) - right[1] * 10;

		for(int i = 0; i < 3; i++){
			front[i] += '0';
			back[i] += '0';
			left[i] += '0';
			right[i] += '0';
		}
	}
/*	// If timeout
	else if(timeout < 1){
		for(int i = 0; i < 3; i++){
			front[i] = '-';
			back[i] = '-';
			left[i] = '-';
			right[i] = '-';
		}
		
	} */

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
	