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

#define LIGHT_STATE 0
#define BLUETOOTH_STATE 1
#define SENSOR_STATE 2
#define DRIVE_STATE 3

#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))


//Name of the main struct with all the data in for the different sensors and values
dataptn DirtyDawg;

int main(void)
{


	System_Init(); //Checked - OK!
	//Baudrate max is 19200 (double speed enabled)

	UART_Init(19200); //Checked - OK!

	//Connects to BT device
	//while(BT_Init()==0);
	
	TWI_Master_Init();
	
	
	
	LCD_Init();
	uint8_t array1[] = {'H','E','L','L','O'};
	uint8_t array2[] = {'W','O','R','L','D', '!'};
	
	LCD_String(array1, ARR_SIZE(array1),array2, ARR_SIZE(array2));
	
	
	
	Y_LED_On();
	while(1);
	


	
	
	PWM_Init();
	ADC_init();
	BT_Init();
	
	


	//Wait here until we have a Bluetooth connection
	//while(!BT_Connect());

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

	DirtyDawg->state = BLUETOOTH_STATE;
	int ticks, oldstate = 0;
	
	for(;;){

		//Something thats needs to be done every pass???
		
		//Runs only every 10th pass, not so time crucial.
		if(ticks++ == 10){
			//Saves the current state to another variable
			oldstate = DirtyDawg->state;
			//DirtyDawg.state = LIGHT_STATE;
			ticks = 0;
		}
		
		//Main state machine
		switch(DirtyDawg->state){
			case LIGHT_STATE:
				Lights();
				DirtyDawg->state = oldstate;
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
	
	//If the controller prompted for the lights to be turned on and 
	//if(DirtyDawg->lights == 1 && !(DirtyDawg->status & LIGHT_ON)){
		
		
	
	

	//set state
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




	//set state
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




	//set state
}