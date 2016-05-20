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

#define TRUE 1
#define FALSE 0
#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))


//Name of the main struct with all the data in for the different sensors and values
DATA DirtyDawg;

int main(void){

	DirtyDawg.state = 0;
	//System_Init(); //Checked - OK!
	//Baud rate max is 19200 (double speed enabled)

	//UART_Init(19200); //Checked - OK!
	
	


	//Connects to BT device
	//while(BT_Init()==0);
	
	TWI_Master_Init();
	
	LCD_Init();
	
	UART_Init();
	
	suart_init();
	
	BT_Init();
	  
	sputs("The DirtyDawg Is Awake!\n\r" );

	for(;;){				// main loop
		sputchar( '-' );
		while( !kbhit() );			// wait until byte received
		LCD_Byte( sgetchar(), LCD_CHR );		// sent byte + 
	}


	
	Y_LED_Off();
	while(TRUE){
		if(DirtyDawg.state == FALSE)
			Y_LED_Off();
		else
			Y_LED_On();
	}
		
}

ISR(PCINT2_vect){
	if(DirtyDawg.state == FALSE)
		DirtyDawg.state = TRUE;
	else
		DirtyDawg.state = FALSE;
}

ISR(INT1_vect){
	if(DirtyDawg.state == FALSE)
	DirtyDawg.state = TRUE;
	else
	DirtyDawg.state = FALSE;
}

