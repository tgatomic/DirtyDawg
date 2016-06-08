#ifndef  functions_Header_h   /* Include guard */
#define functions_Header_h

/************************************************************************/
/*								LIGHTS                                  */
/************************************************************************/
#define BRAKELIGHT PORTB1
#define HEADLIGHT PORTB2

/************************************************************************/
/*								Steering                                */
/************************************************************************/
/*
#define FORWARD PORTD3
#define BACKWARD PORTD5
#define LEFT PORTD6
#define RIGHT PORTB3
#define PWM_FORWARD OCR2B
#define PWM_BACKWARD OCR0B
#define PWM_LEFT OCR0A
#define PWM_RIGHT OCR2A
#define L 1
#define R 2
#define F 3
#define B 4
*/
/************************************************************************/
/*								Sensor                                  */
/************************************************************************/
#define LIGHTSENSOR PORTC0

/************************************************************************/
/*								Communication                           */
/************************************************************************/
#define RX PORTD0
#define TX PORTD1

/************************************************************************/
/*								Status                                 */
/************************************************************************/
#define MCU_STARTED 1<<0
#define UART_STARTED 1<<1
#define BT_STARTED 1<<2
#define BT_CONNECTED 1<<3
#define LIGHT_BUTTON 1<<4
#define REVERSE_BUTTON 1<<5

/************************************************************************/
/*							Tilt status                                 */
/************************************************************************/
#define TILT_CENTER 0
#define TILT_LEFT 1
#define TILT_RIGHT 2

/************************************************************************/
/*	                 Command flags for the car                          */
/************************************************************************/
#define LIGHT 1<<0
#define STOP 1<<1
#define REVERSE 1<<2
#define TURN_LEFT 1<<3
#define TURN_RIGHT 1<<4

/************************************************************************/
/*								Datastruct                              */
/************************************************************************/
typedef struct data{

	uint8_t left_sensor;
	uint8_t right_sensor;
	uint8_t front_sensor;
	uint8_t back_sensor;
	uint8_t accelerometer;
	uint8_t ECG;

	// Byte of commands to car
	uint8_t command;
	uint8_t status;
	uint8_t state; 
	
} *dataptn, DATA;

char front[3], back[3], right[3], left[3];

void System_Init(void);
void UART_Init(unsigned int);
void LCD_Update(void);
void Uart_Flush(void);
void Error(unsigned int);

// Functions for BlueSmirf
void BT_Init(void);
void BT_Connection_Check(void);
void BT_Connect(void);
void BT_Disconnect(void);
void BT_Send_Data(void);
void BT_Recieve_Data(void);
uint8_t BT_Recieve(void);
void BT_Send(uint8_t);

//Functions for debugging
void Yellow_LED_On(void);
void Yellow_LED_Off(void);
void Red_LED_On(void);
void Red_LED_Off(void);
void Green_LED_On(void);
void Green_LED_Off(void);


#endif // FUNCTIONS_H_