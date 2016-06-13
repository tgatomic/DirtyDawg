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
	
	Drive(L,255);
	_delay_ms(1000);
	Drive(L,0);
	Drive(R,255);
	_delay_ms(1000);
	Drive(R,0);
	Drive(L,0);


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
	DirtyDawg.control_status = 0;
	DirtyDawg.ISR_Vect_Pos = 0;
	flags = 0;
	
	
	for(;;){
					
		// Something thats needs to be done every pass???
		_delay_ms(1000);
		// MAYBECONNECTION TIMEOUT MESSAGE?
		
		// Runs only every 10th pass, not so time crucial.
		/*if(ticks++ == 20){
			// Saves the current state to another variable
			DirtyDawg.oldstate = DirtyDawg.state;
			
			// Changes the state
			DirtyDawg.state = LIGHT_STATE;
			ticks = 0;
		}*/
		if(!(flags & PAIRED)){
			DirtyDawg.state = PAIRING_STATE;
		}
		
		// Main state machine
		switch(DirtyDawg.state){
			case LIGHT_STATE:
				//Lights();
				DirtyDawg.state = BLUETOOTH_STATE;
				break;
			case BLUETOOTH_STATE:
				Bluetooth();
				break;
			case SENSOR_STATE:
				//Sensors();
				DirtyDawg.state = BLUETOOTH_STATE;
				break;
			case DRIVE_STATE:
				Vroom();
				break;
			case PAIRING_STATE:
				Pairing();
				break;
			
			// Activates if there is no state
			default:
				//LCD_String(NO_STATE_STR,8,NO_STATE_STR,8);
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

	if( DirtyDawg.control_status & LIGHTS || DirtyDawg.lightvalue < LIGHT_THRESHOLD ){
		PORTB |= (1<<BRAKELIGHT);
	} else {
		PORTB &= ~(1<<BRAKELIGHT);
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
int x = 0;

void Bluetooth(void){
	
	//unsigned char ascii[20];

	//LCD_Singlestring(LCD_LINE_1, "Sending: ");
	//itoa(i, ascii, 10);
	//for(int i = 0; i < 3; i++){
		//LCD_Byte(ascii[i], LCD_CHR);
	//}

	DirtyDawg.front_sensor = x++;
	DirtyDawg.back_sensor = x+1;
	DirtyDawg.left_sensor= x+2;
	DirtyDawg.right_sensor = x+3;
	
	if( x == 250){
		x = 0;
	}
		
	BT_Send(START_TRANSMIT);
	_delay_ms(50); //delay for 168 to catch up
	BT_Send(DirtyDawg.front_sensor);
	_delay_ms(50);
	BT_Send(DirtyDawg.back_sensor);
	_delay_ms(50);
	BT_Send(DirtyDawg.left_sensor);
	_delay_ms(50);
	BT_Send(DirtyDawg.right_sensor);
	_delay_ms(50);


	//If there is nothing in receive buffer
	//if(DirtyDawg.BT_recieve_buffer[0] == 0){
		//DirtyDawg.state = DRIVE_STATE;
		//return;
	//}
	
	if( DirtyDawg.BT_recieve_buffer[0] & STOP ){
		Stop_Moving();
		//DirtyDawg.state = BLUETOOTH_STATE;
		//return;
		} else {
		
		if(DirtyDawg.BT_recieve_buffer[0] & REVERSE){
			Drive(F,0x00);
			Drive(B, DirtyDawg.BT_recieve_buffer[1]);
			} else {
			Drive(B,0x00);
			Drive(F, DirtyDawg.BT_recieve_buffer[1]);
		}
		
	}
	
	if(DirtyDawg.BT_recieve_buffer[0] & TURN_LEFT){
		Drive(R, 0);
		Drive(L, 253);
	}
	else if(DirtyDawg.BT_recieve_buffer[0] & TURN_RIGHT){
		Drive(L, 0);
		Drive(R, 253);
		
		} else {
		Drive(R, 0);
		Drive(L, 0);
		
	}
	
	if((DirtyDawg.BT_recieve_buffer[0] & LIGHTS)){
		PORTB |= (1<<PORTB0);
		
		} else{
		PORTB &= ~(1<<PORTB0);
		
	}

	//Change state
	DirtyDawg.state = BLUETOOTH_STATE;

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

	if( DirtyDawg.control_status & STOP ){
		Stop_Moving();
		DirtyDawg.state = BLUETOOTH_STATE;
		return;		
	}

	if(DirtyDawg.forward > DirtyDawg.backward){
		Drive(F, DirtyDawg.forward);
	} else {
		Drive(B, DirtyDawg.backward);
	}
	
	if((DirtyDawg.control_status & TURN_LEFT)){
		Drive(R, 0);
		Drive(L, 253);
	}
	else if((DirtyDawg.control_status & TURN_RIGHT)){
		Drive(L, 0);
		Drive(R, 253);
	} else {
		Drive(R, 0);
		Drive(L, 0);
	}
	
	DirtyDawg.state = BLUETOOTH_STATE;
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
		
		Stop_Moving();
		//LCD_Byte(LCD_CLEAR, LCD_CMD);	
	
		// Waits here until it is paired
		//LCD_Byte(LCD_CLEAR, LCD_CMD);
		//LCD_Singlestring(LCD_LINE_1, "Connecting");
		//LCD_Byte(LCD_LINE_1+10, LCD_CMD);
		
		//DirtyDawg.BT_recieve_buffer[0] = 'S';
		int i = 0;
		while(!(flags & PAIRED)){
			PORTB |= (1<<PORTB0);
			_delay_ms(1000);
			if(i == 3){
				//LCD_Singlestring(LCD_LINE_1+10, "   ");
				//LCD_Byte(LCD_LINE_1+10, LCD_CMD);
				i = 0;
			}
			//LCD_Byte('.', LCD_CHR);
			PORTB &= ~(1<<PORTB0);
			_delay_ms(1000);
			i++;
		}
	}
	DirtyDawg.control_status = (1<<STOP); 
	DirtyDawg.BT_recieve_buffer[0] = DirtyDawg.control_status;
	DirtyDawg.BT_recieve_buffer[1] = 0;
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
			DirtyDawg.ISR_Vect_Pos = 0;
			//LCD_Byte(LCD_CLEAR, LCD_CMD);
			//LCD_Singlestring(LCD_LINE_1, "DISCONNECTED");
		}
		else if(data == 'C'){
			while(BT_Recieve() != '=');
			//DirtyDawg.BT_recieve_buffer[0] = '=';
			flags |= PAIRED;
			//LCD_Byte(LCD_CLEAR, LCD_CMD);
			//LCD_Singlestring(LCD_LINE_1, "CONNECTED");
			DirtyDawg.ISR_Vect_Pos = 0;
			DirtyDawg.state = BLUETOOTH_STATE;
		}
	}
	else{
		//DirtyDawg.BT_recieve_buffer[DirtyDawg.ISR_Vect_Pos++] = data;
		if(data < 22){
			DirtyDawg.BT_recieve_buffer[0] = data;
			DirtyDawg.BT_recieve_buffer[1] = BT_Recieve();
			return;
			
			if( DirtyDawg.BT_recieve_buffer[0] & STOP ){
				Stop_Moving();
				//DirtyDawg.state = BLUETOOTH_STATE;
				//return;
			} else {
				
				if(DirtyDawg.BT_recieve_buffer[0] & REVERSE){
					Drive(F,0x00);
					Drive(B, DirtyDawg.BT_recieve_buffer[1]);
				} else {
					Drive(B,0x00);
					Drive(F, DirtyDawg.BT_recieve_buffer[1]);
				}
				
			}
			
			if(DirtyDawg.BT_recieve_buffer[0] & TURN_LEFT){
				Drive(R, 0);
				Drive(L, 253);
			}
			else if(DirtyDawg.BT_recieve_buffer[0] & TURN_RIGHT){
				Drive(L, 0);
				Drive(R, 253);
					
				} else {
				Drive(R, 0);
				Drive(L, 0);
					
			}
			
			if((DirtyDawg.BT_recieve_buffer[0] & LIGHTS)){
				PORTB |= (1<<PORTB0);
				
			} else{
				PORTB &= ~(1<<PORTB0);
				
			}
			

			
			
		}
	}
	/*
	if(DirtyDawg.ISR_Vect_Pos >= 2){
		DirtyDawg.ISR_Vect_Pos = 0;
	}
	*/
	
	
	return;

}

void test(void){
	
	if( DirtyDawg.BT_recieve_buffer[0] & STOP ){
		Stop_Moving();
		//DirtyDawg.state = BLUETOOTH_STATE;
		//return;
		} else {
		
		if(DirtyDawg.BT_recieve_buffer[0] & REVERSE){
			Drive(F,0x00);
			Drive(B, DirtyDawg.BT_recieve_buffer[1]);
			} else {
			Drive(B,0x00);
			Drive(F, DirtyDawg.BT_recieve_buffer[1]);
		}
		
	}
	
	if(DirtyDawg.BT_recieve_buffer[0] & TURN_LEFT){
		Drive(R, 0);
		Drive(L, 253);
	}
	else if(DirtyDawg.BT_recieve_buffer[0] & TURN_RIGHT){
		Drive(L, 0);
		Drive(R, 253);
		
		} else {
		Drive(R, 0);
		Drive(L, 0);
		
	}
	
	if((DirtyDawg.BT_recieve_buffer[0] & LIGHTS)){
		PORTB |= (1<<PORTB0);
		
		} else{
		PORTB &= ~(1<<PORTB0);
		
	}
	
}