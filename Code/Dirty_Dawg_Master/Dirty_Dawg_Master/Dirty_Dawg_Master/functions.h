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
//#define LIGHT_ON 1<<3;
int status; //Delete later


/************************************************************************/
/*								Datastruct                              */
/************************************************************************/
typedef struct data{

	//The value from the LDR
	int lightvalue;

	//The distance values received on TWI-bus
	int left_sensor;
	int right_sensor;
	int front_sensor;
	int back_sensor;
	
	//Buffer for send and transmit
	uint8_t BT_send_buffer[20];
	uint8_t BT_recieve_buffer[20];
	
	//Statusflags to know what is set and not
	uint8_t status;
	#define LIGHTS (1<<0)
	#define STOP (1<<0)
	#define FORWARD (1<<0)
	
	
	uint8_t state; 
	
	
} *dataptn;

//Name of the main struct with all the data in for the different sensors and values
dataptn DirtyDawg;


#define F_CPU 8000000UL

void System_Init(void);



void INT_Crash(void);
void Lowrider_Mode(void);
void Sense_Light(void);





void Y_LED_On(void);
void Y_LED_Off(void);


#endif // FUNCTIONS_H_