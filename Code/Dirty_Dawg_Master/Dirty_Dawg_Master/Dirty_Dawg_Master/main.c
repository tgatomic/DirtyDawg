/*
 * Dirty_Dawg_Master.c
 *
 * Created: 2016-04-18 13:32:02
 * Author : Atomic
 */ 

#include <avr/io.h>
#include "functions.h"
#include "TWI_Master.h"
#include "PWM.h"

#define LIGHT_STATE 0
#define BLUETOOTH_STATE 1
#define SENSOR_STATE 2
#define DRIVE_STATE 3

//Name of the main struct with all the data in for the different sensors and values
dataptn DirtyDawg;

int main(void)
{
	System_Init();
	UART_Init(115200);
	TWI_Master_Init();
	PWM_Init();
	ADC_init();
	BT_Init();

	//Wait here until we have a Bluetooth connection
	while(!BT_Connect());

	/************************************************************************/
	/*								Tasks									*/
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

	for(;;){

		//Something thats needs to be done every pass???
		int ticks = 0;
		if(ticks++ == 10){
			DirtyDawg.state = LIGHT_STATE;
			ticks = 0;
		}
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
	
	
	

	//set state
}
/************************************************************************/
/*							Bluetooth State                             */
/*																		*/
/*	   Tasks:                                                           */
/*     -  Read the buffer                     */
/*     -  Save the content of buffer in appropriate variables                           */
/*     -                         */
/*     -                                              */
/*     -                                 */
/*                                                                      */
/************************************************************************/
void Bluetooth(void){


	//set state
}
void Sensors(void){

	//set state
}
void Vroom(void){


	//set state
}