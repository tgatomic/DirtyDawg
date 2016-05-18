#ifndef  functions_Header_h   /* Include guard */
#define functions_Header_h


/************************************************************************/
/*								LIGHTS                                  */
/************************************************************************/
#define BRAKELIGHT PORTB1
#define HEADLIGHT PORTB2
#define LDR_Pin 0

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
#define F 1
#define B 2
#define L 3
#define R 4

/************************************************************************/
/*							Sensor and Buttons                          */
/************************************************************************/
#define LIGHTSENSOR PORTC0
#define LIGHT_THRESHOLD 500 
#define BUTTON 
#define HIGH 1 
#define LOW 0

/************************************************************************/
/*								Communication                           */
/************************************************************************/
#define RX PORTD0
#define TX PORTD1
#define BT121ADRESS 00033343A13F

/************************************************************************/
/*								Status                                 */
/************************************************************************/

uint8_t status;

#define LIGHTS (1<<0)
#define STOP (1<<1)
#define F_OR_B (1<<2)



/************************************************************************/
/*								Datastruct                              */
/************************************************************************/
typedef struct data{

	// The value from the LDR
	int lightvalue;
	
	// State value
	int oldstate;

	// The distance values received on TWI-bus
	uint8_t  front_sensor;
	uint8_t  back_sensor;
	uint8_t  left_sensor;
	uint8_t  right_sensor;
	

	// The speed data for driving
	uint8_t forward;
	uint8_t backward;
	uint8_t left;
	uint8_t right;
	
	// Buffer for send and transmit
	uint8_t BT_send_buffer[20];
	uint8_t BT_recieve_buffer[20];
	
	// Keeps the record on what state we are in
	uint8_t state; 
	
	
} *dataptn;

//Name of the main struct with all the data in for the different sensors and values
dataptn DirtyDawg;


void System_Init(void);

void INT_Crash(void);
void Lowrider_Mode(void);
void Sense_Light(void);





void Y_LED_On(void);
void Y_LED_Off(void);


#endif // FUNCTIONS_H_