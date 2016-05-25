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
	while(!(DirtyDawg.status & BT_CONNECTED))
		BT_Connect();
	  
	while(TRUE)
		Green_LED_On();
	//Prints a message to tell the user that the controller is running
//	sputs("The DirtyDawg Is Awake!\n\r" );
/*
	uint8_t word, count = 0;
	for(;;){				// main loop
		sputchar( '-' );
		while( !kbhit() );			// wait until byte received
		word = sgetchar();
		LCD_Byte( word, LCD_CHR );		// sent byte + 
		BT_Send(word);
		if(count++ > 15){
			LCD_Byte(LCD_CLEAR,LCD_CMD);
			_delay_ms(150);
			count = 0;
		}
	}
*/

	while(TRUE){
		
		switch(DirtyDawg.state){
			
			case LCD_STATE:
				LCD_Update();
				break;
			
			case SEND_DATA_STATE:
				BT_Send_Data();
				break;

			case GET_DATA_STATE:
				BT_Recieve_Data();
				break;
				
			default:
				Yellow_LED_On();
				Error(0x53);
			
		}
	}	
}

ISR(PCINT2_vect){

}
/*
ISR(INT1_vect){
	BT_Connect();
}

*/

ISR(USART_RX_vect){
	LCD_Byte('*',LCD_CHR);
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
	}
}
