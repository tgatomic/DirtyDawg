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

/************************************************************************/
/*								Sensor                                  */
/************************************************************************/
#define LIGHTSENSOR PORTC0

/************************************************************************/
/*								Communication                           */
/************************************************************************/
#define RX PORTD0
#define TX PORTD1
#define BT121ADRESS 00033343A13F

/************************************************************************/
/*								Status                                 */
/************************************************************************/
#define MCU_STARTED 1<<0
#define UART_STARTED 1<<1
#define BT_STARTED 1<<2
#define BT_CONNECTED 1<<3
#define BUTTON 1<<4

/************************************************************************/
/*								Datastruct                              */
/************************************************************************/
typedef struct data{

	int left_sensor;
	int right_sensor;
	int front_sensor;
	int back_sensor;
	//Or Distsensor[4]	

	uint8_t accelerometer;
	uint8_t ECG;
	
	//Is one if the controller has prompted for the lights to be turned on
	uint8_t lights;
	
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
int BT_Init(void);
void BT_Connect(void);
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