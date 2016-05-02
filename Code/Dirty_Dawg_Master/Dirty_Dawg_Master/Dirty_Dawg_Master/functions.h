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
#define BT121ADRESS 0x12345

/************************************************************************/
/*								Status                                 */
/************************************************************************/
#define MCU_STARTED 1<<0;
#define UART_STARTED 1<<1;
#define BT_STARTED 1<<2;
//#define LIGHT_ON 1<<3;
int status; //Delete later


/************************************************************************/
/*								Datastruct                              */
/************************************************************************/
typedef struct data{

	int lightvalue;

	int left_sensor;
	int right_sensor;
	int front_sensor;
	int back_sensor;
	//Or Distsensor[4]	

	//Is one if the controller has prompted for the lights to be turned on
	uint8_t lights;
	
	uint8_t status;
	
	uint8_t state; 
	
} *dataptn;



void System_Init(void);
void UART_Init(unsigned int baud);
void BT_Init(void);
void I2C_Init(void);
void BT_Connect(void);
void Connected(void);
void INT_Crash(void);
void Lowrider_Mode(void);
void Sense_Light(void);

uint8_t BT_Recieve(void);
void Uart_Flush(void);
void Error(unsigned int errorcode);


#endif // FUNCTIONS_H_