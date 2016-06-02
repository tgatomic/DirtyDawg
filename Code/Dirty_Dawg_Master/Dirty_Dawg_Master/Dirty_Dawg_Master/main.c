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


int main(void)
{
	
	//Placeholder for all the different init function
	System_Init();
	
	_delay_ms(1000);
	
	LCD_Byte(LCD_CLEAR, LCD_CMD);
	unsigned char ascii[20];
	
	while(1){
		PORTB |= (1<<PORTB0);
		
		LCD_Byte(LCD_CLEAR, LCD_CMD);
		LCD_Singlestring(LCD_LINE_1, "Received: ");
		
		TWI_Receive(ATTINY1,1);
		itoa(DirtyDawg.TWI_Receive_Buffer[0], ascii, 10);
		for(int i = 0; i < 3; i++){
			LCD_Byte(ascii[i], LCD_CHR);
		}
		_delay_ms(250);
		PORTB &= (0<<PORTB0);
		_delay_ms(250);
	}
	

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
	DirtyDawg.state = PAIRING_STATE;
	
	uint8_t ticks = 0;
	control_status = 0;
	DirtyDawg.ISR_Vect_Pos = 0;
	flags = 0;
	
	
	for(;;){
					
		// Something thats needs to be done every pass???
		
		// MAYBECONNECTION TIMEOUT MESSAGE?
		
		// Runs only every 10th pass, not so time crucial.
		if(ticks++ == 20){
			// Saves the current state to another variable
			DirtyDawg.oldstate = DirtyDawg.state;
			
			// Changes the state
			DirtyDawg.state = BLUETOOTH_STATE;
			ticks = 0;
		}
		if(!(flags & PAIRED)){
			DirtyDawg.state = PAIRING_STATE;
		}
		
		// Main state machine
		switch(DirtyDawg.state){
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
			case PAIRING_STATE:
				Pairing();
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
	
	DirtyDawg.state = DirtyDawg.oldstate;
	
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
int i = 0;

void Bluetooth(void){
	
	unsigned char ascii[20];

	LCD_Singlestring(LCD_LINE_1, "Sending: ");
	itoa(i, ascii, 10);
	for(int i = 0; i < 3; i++){
		LCD_Byte(ascii[i], LCD_CHR);
	}

	DirtyDawg.front_sensor = i++;
	DirtyDawg.back_sensor = i+1;
	DirtyDawg.left_sensor= i+2;
	DirtyDawg.right_sensor = i+3;
		
	BT_Send(START_TRANSMIT);
	BT_Send(DirtyDawg.front_sensor);
	BT_Send(DirtyDawg.back_sensor);
	BT_Send(DirtyDawg.left_sensor);
	BT_Send(DirtyDawg.right_sensor);
	
		
	if(i == 253){
		i = 0;
	}
	_delay_ms(500);
		
	//Change state
	DirtyDawg.state = BLUETOOTH_STATE;
/*
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
	
*/
	

	
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

	// Front sensor
	TWI_Receive(ATTINY1,1); 
	
	// Left and Right sensor
	TWI_Receive(ATTINY2,2);
	
	// Saving the data from buffer 0-255
	DirtyDawg.front_sensor = DirtyDawg.TWI_Receive_Buffer[0];
	DirtyDawg.back_sensor = 0;
	DirtyDawg.left_sensor = DirtyDawg.TWI_Receive_Buffer[1];
	DirtyDawg.right_sensor = DirtyDawg.TWI_Receive_Buffer[2];


	// Change state
	DirtyDawg.state = BLUETOOTH_STATE;
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
		DirtyDawg.state = SENSOR_STATE;
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


	DirtyDawg.state = SENSOR_STATE;
}

/************************************************************************/
/*							Pairing			                            */
/*																		*/
/*	   Tasks:                                                           */
/*     -  									*/
/*     -  											*/
/*       																*/
/*       																*/
/************************************************************************/

void Pairing(void){
	
	while (!(flags & PAIRED)){
		
		LCD_Byte(LCD_CLEAR, LCD_CMD);	
	
		// Waits here until it is paired
		LCD_Byte(LCD_CLEAR, LCD_CMD);
		LCD_Singlestring(LCD_LINE_1, "Connecting");
		LCD_Byte(LCD_LINE_1+10, LCD_CMD);
		
		//DirtyDawg.BT_recieve_buffer[0] = 'S';
		int i = 0;
		while(!(flags & PAIRED)){
			
			if(i == 3){
				LCD_Singlestring(LCD_LINE_1+10, "   ");
				LCD_Byte(LCD_LINE_1+10, LCD_CMD);
				i = 0;
			}
			LCD_Byte('.', LCD_CHR);
			_delay_ms(1000);
			i++;
		}
	}
	DirtyDawg.state = BLUETOOTH_STATE;
}


//Interrupt for UART
ISR(USART_RX_vect){
	
	uint8_t data = UDR0;
	
	
	if(data == '%'){
		
		data = BT_Recieve();
		
		if(data == 'D'){
			while(BT_Recieve() != 'T');
			flags &= ~PAIRED;
			LCD_Byte(LCD_CLEAR, LCD_CMD);
			LCD_Singlestring(LCD_LINE_1, "DISCONNECTED");
		}
		else if(data == 'C'){
			while(BT_Recieve() != '=');
			DirtyDawg.BT_recieve_buffer[0] = '=';
			flags |= PAIRED;
			LCD_Byte(LCD_CLEAR, LCD_CMD);
			LCD_Singlestring(LCD_LINE_1, "CONNECTED");
			DirtyDawg.state = BLUETOOTH_STATE;
		}
	}
	else{
		DirtyDawg.BT_recieve_buffer[DirtyDawg.ISR_Vect_Pos++] = data;
	}
	

	// If receive buffer is full ( the whole packet is recieved);
	if(DirtyDawg.ISR_Vect_Pos == 2){
		
		LCD_Byte(LCD_LINE_2,LCD_CMD);
		
		// Convert and print data from buffer
		unsigned char ascii[20];
		unsigned char ascii2[20];
		itoa(DirtyDawg.BT_recieve_buffer[0], ascii, 10);
		for(int i = 0; i < 3; i++){
			LCD_Byte(ascii[i], LCD_CHR);
		}
		
		LCD_Byte(' ', LCD_CHR);
		
		itoa(DirtyDawg.BT_recieve_buffer[1], ascii2, 10);
		for(int i = 0; i < 3; i++){
			LCD_Byte(ascii2[i], LCD_CHR);
		}
		
		LCD_Byte(LCD_LINE_1,LCD_CMD);
		// Zero vector
		DirtyDawg.ISR_Vect_Pos = 0;
	}
	
	DirtyDawg.BT_recieve_buffer[DirtyDawg.ISR_Vect_Pos++] = data;
	
	
}