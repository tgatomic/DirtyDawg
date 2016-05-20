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

#define TRUE 1
#define FALSE 0
#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))


#define LCD_STATE 1
#define BT_STATE 2

uint8_t LCD_initiated = 0;


//Name of the main struct with all the data in for the different sensors and values
DATA DirtyDawg;

int main(void){

	// Sets the starting state
	DirtyDawg.state = 0;

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
	
	// Connect the Bluesmirf to the car
	BT_Connect();
	  
	//Prints a message to tell the user that the controller is running
	sputs("The DirtyDawg Is Awake!\n\r" );

	uint8_t word;
	for(;;){				// main loop
		sputchar( '-' );
		while( !kbhit() );			// wait until byte received
		word = sgetchar();
		LCD_Byte( word, LCD_CHR );		// sent byte + 
		BT_Send(word);
	}

	for(;;){
		
		
		switch(DirtyDawg.state){
			
			case LCD_STATE:
				LCD_Update();
				break;
			
			case BT_STATE:
				BT_Send_Data();
				break;
				
			

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

void LCD_Update(void){
	
	// Initiate the distance screen
	if(LCD_initiated){
		LCD_String(ROW1, ARR_SIZE(ROW1), ROW2, ARR_SIZE(ROW2))
		LCD_initiated = 1;
	}
	
	// Prints the distance to front obstacle
	LCD_Byte(place in screen, LCD_CMD);
	LCD_Byte(DirtyDawg.front_sensor, LCD_CHR);
	
	// Prints the distance to back obstacle
	LCD_Byte(place in screen, LCD_CMD);
	LCD_Byte(DirtyDawg.back_sensor, LCD_CHR);
	
	// Prints the distance to left obstacle
	LCD_Byte(place in screen, LCD_CMD);
	LCD_Byte(DirtyDawg.left_sensor, LCD_CHR);
	
	// Prints the distance to right obstacle
	LCD_Byte(place in screen, LCD_CMD);
	LCD_Byte(DirtyDawg.right_sensor, LCD_CHR);
	
	//Change state
}
void BT_Send_Data(void){
	
	BT_Send(DirtyDawg.accelerometer);
	BT_Send(DirtyDawg.ECG);
	
	//Change state
}