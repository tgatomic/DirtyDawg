/*
 * Dirty_Dawg_Master.c
 *
 * Created: 2016-04-18 13:32:02
 * Author : Atomic
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "functions.h"
#include "TWI_Master.h"
#include "PWM.h"
#include "TWI_LCD.h"
#include "Bluetooth.h"
#include "ADC.h"
#include "Error_Codes.h"
#include "main.h"

uint8_t state;
#define LIGHT_STATE 0x00
#define BLUETOOTH_STATE 0x01
#define SENSOR_STATE 0x02
#define DRIVE_STATE 0x03



#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))

void Lights(void);
void Bluetooth(void);
void Sensors(void);
void Vroom(void);


int main(void)
{
	
	//Placeholder for all the different init function
	System_Init();
	

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
	state = BLUETOOTH_STATE;
	
	uint8_t ticks = 0;
	control_status = 0;
	
	unsigned char test[20];
	int x = 0;
	int length = 1;
	
	LCD_Byte(LCD_CLEAR,LCD_CMD);
	
	
	while (1){
		LCD_Byte(LCD_LINE_1,LCD_CMD);
		itoa(x++, test, 10);
		for(int y = 0; y<=6; y++){
			LCD_Byte(test[y], LCD_CHR);
		}
		
		LCD_Byte(LCD_LINE_1+8,LCD_CMD);
		for(int y = 0; y<=6; y++){
			LCD_Byte(test[y], LCD_CHR);
		}
		
		LCD_Byte(LCD_LINE_2,LCD_CMD);
		for(int y = 0; y<=6; y++){
			LCD_Byte(test[y], LCD_CHR);
		}
		
		LCD_Byte(LCD_LINE_2+8,LCD_CMD);
		for(int y = 0; y<=6; y++){
			LCD_Byte(test[y], LCD_CHR);
		}

		
		
		
		
	}
	
	
	
	
	
	
	// Waits here until it is paired
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	LCD_Singlestring(LCD_LINE_1, "Connecting");
	LCD_Byte(LCD_LINE_1+10, LCD_CMD);
	
	DirtyDawg.BT_recieve_buffer[0] = 'S';
	int i = 0;
	while(DirtyDawg.BT_recieve_buffer[0] != '='){
		
			if(i == 3){
				LCD_Singlestring(LCD_LINE_1+10, "   ");
				LCD_Byte(LCD_LINE_1+10, LCD_CMD);
				i = 0;
			}
			LCD_Byte('.', LCD_CHR);
			_delay_ms(1000);
			i++;

	}
	
	
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	LCD_Singlestring(LCD_LINE_1, "Sending");
	
	
	
	for(;;){
					
		// Something thats needs to be done every pass???
		
		// Runs only every 10th pass, not so time crucial.
		if(ticks++ == 20){
			// Saves the current state to another variable
			DirtyDawg.oldstate = state;
			
			// Changes the state
			state = LIGHT_STATE;
			ticks = 0;
		}
		
		// Main state machine
		switch(state){
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
			
			// Activates if there is no state
			default:
				LCD_String(NO_STATE_STR,8,NO_STATE_STR,8);
				Error(NO_STATE);
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
	
	DirtyDawg.lightvalue = Read_ADC(LDR_Pin);

	if( control_status & LIGHTS || DirtyDawg.lightvalue < LIGHT_THRESHOLD ){
		PORTB |= (1<<HEADLIGHT);
	} else {
		PORTB &= ~(1<<HEADLIGHT);
	}
	
	state = DirtyDawg.oldstate;
	
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
	
	LCD_Byte(LCD_LINE_1+7, LCD_CMD);




	for (int i = 0; i<255; i++)
	{
		DirtyDawg.front_sensor = i;
		DirtyDawg.back_sensor = i+1;
		DirtyDawg.left_sensor= i+2;
		DirtyDawg.right_sensor = i+3;
		
		BT_Send(START_TRANSMIT);
		BT_Send(DirtyDawg.front_sensor);
		BT_Send(DirtyDawg.back_sensor);
		BT_Send(DirtyDawg.left_sensor);
		BT_Send(DirtyDawg.right_sensor);
		
		if(i==30){
			_delay_ms(2000);
		}
		

		if(i % 25 == 0){
			LCD_Byte('.', LCD_CHR);
		}
				
		if(i == 253){
			i = 0;
			LCD_Singlestring(LCD_LINE_1+7, "           ");
			LCD_Byte(LCD_LINE_1+7, LCD_CMD);
		}
		_delay_ms(500);
		
	}

	//If there is nothing in receive buffer
	if(DirtyDawg.BT_recieve_buffer[0] == 0){
		state = DRIVE_STATE;
		return;
	}
	
	// Saves the data form the receive buffer
	control_status = DirtyDawg.BT_recieve_buffer[0];
	
	// Checks and save if we want to drive forward or backwards
	if(control_status && F_OR_B){
		DirtyDawg.forward = DirtyDawg.BT_recieve_buffer[1];
		DirtyDawg.backward = 0x00;
		
	} else {
		DirtyDawg.backward = DirtyDawg.BT_recieve_buffer[1];
		DirtyDawg.forward = 0x00;
	}
	
	// Saves the direction
	DirtyDawg.left= DirtyDawg.BT_recieve_buffer[2];
	DirtyDawg.right = DirtyDawg.BT_recieve_buffer[3];

	
	// Clears the receive buffer
	for(int i = 0; i < 5 ; i++){
		DirtyDawg.BT_recieve_buffer[i] = 0;
	}
	

	

	
	/*
	//Make sure there is content in send buffer before sending
	if(DirtyDawg->BT_send_buffer[0] != 0 || DirtyDawg->BT_send_buffer[1] != 0){
		
		// Send the content in send buffer to controller
		for(int i = 0; i < 4; i++){
			BT_Send(DirtyDawg->BT_send_buffer[i]);
		}
			
		// Clears the content in send buffer
		for(int i = 0; i < 4 ; i++){
			DirtyDawg->BT_send_buffer[i] = 0;
		}
		
	}
	*/
	
	//Change state
	state = BLUETOOTH_STATE;

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

	DirtyDawg.front_sensor = TWI_Receive(ATTINY1);
	DirtyDawg.back_sensor = TWI_Receive(ATTINY1);
	DirtyDawg.left_sensor = TWI_Receive(ATTINY2);
	DirtyDawg.right_sensor = TWI_Receive(ATTINY2);


	//set state
	state = BLUETOOTH_STATE;
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

	if( control_status && STOP ){
		Stop_Moving();
		state = SENSOR_STATE;
		return;		
	}

	if(DirtyDawg.forward > DirtyDawg.backward){
		Drive(F, DirtyDawg.forward);
	} else {
		Drive(B, DirtyDawg.backward);
	}
	
	if(DirtyDawg.left > DirtyDawg.right){
		Drive(L, DirtyDawg.left);
	} else {
		Drive(R, DirtyDawg.right);
	}


	state = SENSOR_STATE;
}


//Interrupt for UART
ISR(USART_RX_vect){
	
	DirtyDawg.BT_recieve_buffer[0] = UDR0;
	//uint8_t data = UDR0;
	//Uart_Flush();
	
	//LCD_Byte(LCD_CLEAR, LCD_CMD);
	//LCD_Byte(DirtyDawg.BT_recieve_buffer[0], LCD_CHR);
	//LCD_Byte( data , LCD_CHR);
	
	//DirtyDawg.BT_recieve_buffer[0] = data;
	//LCD_Byte(DirtyDawg->BT_recieve_buffer[0] , LCD_CHR);
	
	/*
	
	LCD_Byte(UDR0, LCD_CHR);
	
	_delay_ms(1000);
	LCD_Byte(0x01, LCD_CMD);
	_delay_ms(250);
	*/
	//int i;
	
	// Receives the total number of bytes
	//uint8_t nmbr_bytes = UDR0;
	
	// Saves it in the buffer
	//for( i = 0; i < nmbr_bytes; i++){
		//DirtyDawg->BT_recieve_buffer[i] = BT_Recieve();
	//}
	
	// Test with echoing back the packages
	//for( i = 0; i < nmbr_bytes; i++){
		///BT_Send(DirtyDawg->BT_recieve_buffer[i]);
	//}
	
}