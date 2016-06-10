/*
 * ATMega168.c
 *
 * Created: 2016-05-11 13:32:02
 * Author : Janne
 */ 
#define F_CPU 8000000UL


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "functions.h"
#include "TWI_Master.h"
#include "TWI_LCD.h"
#include "SWUART.H"
#include "main.h"

#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))
volatile uint8_t portbhistory = 0;     // default is high because the pull-up

int main(void){

	// Sets the starting state
	DirtyDawg.state = LCD_STATE;

	// Initiate the hardware
	System_Init();
	
	// Initiate the TWI bus as a master
	TWI_Master_Init();

	// Initiate the LCD Screen
	LCD_Init();
	
	// Initiate the hardware defined UART
	UART_Init(19200);
	
	// Initiate the software define UART
	suart_init();

	// Initiate/Clear the BlueSmirf from previous commands
	BT_Init();

	// Connect the BlueSmirf to the car
	LCD_Byte(LCD_LINE_1 + 3, LCD_CMD);
	LCD_String("DirtyDawg!");
	LCD_Byte(LCD_LINE_2 + 3, LCD_CMD);
	LCD_String("Connecting");
	BT_Connection_Check();
	while(!(DirtyDawg.status & BT_CONNECTED))
		BT_Connect();
	  
	// When active connection send '=' to car 
	BT_Send('=');

	// Prepare the LCD for distance data
	LCD_Byte(LCD_LINE_1, LCD_CMD);
	LCD_String(ROW1);
	LCD_Byte(LCD_LINE_2, LCD_CMD);
	LCD_String(ROW2);
	
	// Main loop
	while(TRUE){
		
		switch(DirtyDawg.state){
			
			// Put sensor data to LCD
			case LCD_STATE:
				LCD_Update();
				break;
			
			// Send commands to the car
			case SEND_DATA_STATE:
				BT_Send_Data();
				break;

			// Get sensor data from the car
			case GET_DATA_STATE:
				BT_Recieve_Data();
				break;
				
			default:
//				Yellow_LED_On();
				Error(0x53);
			
		}
//		_delay_ms(250);
	}	
}

ISR(PCINT2_vect){
    uint8_t changedbits;

    changedbits = PIND ^ portbhistory;
    portbhistory = PIND;

    // Interrupt PCINT20
	// Toggles light on and off
    if(changedbits & (1 << PIND4)){
		if(DirtyDawg.status & LIGHT_BUTTON){
			DirtyDawg.command ^= LIGHT;
			DirtyDawg.status &= ~LIGHT_BUTTON;
		}
		else{
			DirtyDawg.status |= LIGHT_BUTTON;
		}
    }

    // Interrupt PCINT21
	// Toggles reverse and forward
    if(changedbits & (1 << PIND5)){
		if(DirtyDawg.status & REVERSE_BUTTON){
			DirtyDawg.command ^= REVERSE;
			DirtyDawg.status &= ~REVERSE_BUTTON;
		}
		else{
			DirtyDawg.status |= REVERSE_BUTTON;
		}
    }
}
/*
ISR(INT1_vect){
	BT_Connect();
}

*/

ISR(USART_RX_vect){
	;
//	LCD_Byte(LCD_LINE_2 + 15, LCD_CMD);
//	LCD_Byte('I', LCD_CHR);
/*
	uint8_t data;
	data = BT_Recieve();
	
	// Ignore command response
	if(data == '%')
		while(BT_Recieve() != LF);
	
	// Get sensor data
	if(data == 'S'){
		DirtyDawg.front_sensor = BT_Recieve();
		DirtyDawg.back_sensor = BT_Recieve();
		DirtyDawg.left_sensor = BT_Recieve();
		DirtyDawg.right_sensor = BT_Recieve();
	} */
}
