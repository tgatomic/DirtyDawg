/*
 * Dirty_Dawg_Master.c
 *
 * Created: 2016-04-18 13:32:02
 * Author : Atomic
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "functions.h"
#include "TWI_Master.h"
#include "PWM.h"
#include "TWI_LCD.h"
#include "Bluetooth.h"
#include "ADC.h"

#define LIGHT_STATE 0
#define BLUETOOTH_STATE 1
#define SENSOR_STATE 2
#define DRIVE_STATE 3

#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))

void Lights(void);
void Bluetooth(void);
void Sensors(void);
void Vroom(void);


int main(void)
{

	// Initiate the hardware - Working
	System_Init();
	
	// Baud rate max is 19200 (double speed enabled) - Working
	UART_Init(19200);

	// Initiate TWI - Working
	TWI_Master_Init();
	
	// Initiate LCD - Working
	LCD_Init();

	// Initiate PWM - Working
	PWM_Init();
	
	Y_LED_On();
	while(1);
	
	// Initiate ADC - Not tested
	ADC_init();
	

	/************************************************************************/
	/*								States									*/
	/*	Read ADC - If lights it low it will turn on lights the headlights	*/
	/*  Read Bluetooth  - Reads the data to drive                           */
	/*	Send Bluetooth	- Sends the distance data to controller				*/
	/*  Drive - takes the input from controller                             */
	/*  Read distance - Reads the distance data on i2c bus                  */
	/*  Lights - Turns on the light if input is given from controller       */
	/*  Crash - Error or actual crash in wall                               */
	/*                                                                      */
	/************************************************************************/

	// Set the state to start in
	DirtyDawg->state = BLUETOOTH_STATE;
	
	int ticks = 0;
	
	for(;;){

		// Something thats needs to be done every pass???
		
		// Runs only every 10th pass, not so time crucial.
		if(ticks++ == 10){
			// Saves the current state to another variable
			DirtyDawg->oldstate = DirtyDawg->state;
			
			// Changes the state
			DirtyDawg->state = LIGHT_STATE;
			ticks = 0;
		}
		
		// Main state machine
		switch(DirtyDawg->state){
			case LIGHT_STATE:
				Lights();
				break;
			case BLUETOOTH_STATE:
				Bluetooth();
				break;
			case SENSOR_STATE:
				Sensors();
				break;
			case DRIVE_STATE:
				Vroom();
				break;
			
			// Activates if there is no state or error occured
			default:
				Error('S');
				break;
		}
	}
}

/************************************************************************/
/*							Lights state                                */
/*																		*/
/*	   Tasks:                                                           */
/*     - Checks to see if the lights flags i set                        */
/*     - Turns the Lights on if flag is set                             */
/*     - Turns the Lights off if flag is cleared                        */
/*     - Read Light sensor                                              */
/*     - Turn headlight on if it is dark                                */
/*                                                                      */
/************************************************************************/
void Lights(void){
	
	DirtyDawg->lightvalue = Read_ADC();

	if( status & LIGHTS || DirtyDawg->lightvalue < LIGHT_THRESHOLD ){
		PORTB |= (1<<HEADLIGHT);
	} else {
		PORTB &= ~(1<<HEADLIGHT);
	}
	
	DirtyDawg->state = DirtyDawg->oldstate;
	
}

/************************************************************************/
/*							Bluetooth State                             */
/*																		*/
/*	   Tasks:                                                           */
/*     -  Read the receive buffer				                        */
/*     -  Save the content of buffer in appropriate variables           */
/*     -  Read the send buffer											*/
/*     -  Sends the content of send buffer                              */
/*     -																*/
/*                                                                      */
/************************************************************************/
void Bluetooth(void){

	//If there is nothing in recieve buffer
	if(DirtyDawg->BT_recieve_buffer[0] != 0){
		DirtyDawg->state = DRIVE_STATE;
		return;
	}
	// Saves the speed data
	DirtyDawg->forward = DirtyDawg->BT_recieve_buffer[0];
	DirtyDawg->backward = DirtyDawg->BT_recieve_buffer[1];
	DirtyDawg->left= DirtyDawg->BT_recieve_buffer[2];
	DirtyDawg->right = DirtyDawg->BT_recieve_buffer[3];
	
	// Saves the button configuration
	status = DirtyDawg->BT_recieve_buffer[4];
	
	// Clears the receive buffer
	for(int i = 0; i < 5 ; i++){
		DirtyDawg->BT_recieve_buffer[i] = 0;
	}
	
	// Send the content in send buffer to controller
	for(int i = 0; i < 4; i++){
		BT_Send(DirtyDawg->BT_send_buffer[i]);
	}
	
	// Clears the content in send buffer
	for(int i = 0; i < 4 ; i++){
		DirtyDawg->BT_send_buffer[i] = 0;
	}
	
	
	DirtyDawg->state = DRIVE_STATE;

}

/************************************************************************/
/*							Sensors state	                            */
/*																		*/
/*	   Tasks:                                                           */
/*     -  Send command on TWI bus to collect distance data		        */
/*     -  Saves the distance data in buffer					            */
/*                                                                      */
/*                                                                      */
/************************************************************************/
void Sensors(void){




	//set state
	DirtyDawg->state = BLUETOOTH_STATE;
}

/************************************************************************/
/*							Vroom state  	                            */
/*																		*/
/*	   Tasks:                                                           */
/*     -  	Set the forward speed with PWM								*/
/*     -  	Set direction of car 										*/
/*       																*/
/*       																*/
/************************************************************************/
void Vroom(void){

	Drive(F, DirtyDawg->forward);
	Drive(B, DirtyDawg->backward);
	Drive(L, DirtyDawg->left);
	Drive(R, DirtyDawg->right);


	DirtyDawg->state = SENSOR_STATE;
}
