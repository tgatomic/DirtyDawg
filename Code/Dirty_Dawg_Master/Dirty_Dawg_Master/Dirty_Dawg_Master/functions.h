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
#define FORWARD PORTB3
#define BACKWARD PORTD3
#define LEFT PORTD5
#define RIGHT PORTD6
#define PWM_FORWARD OCR2A
#define PWM_BACKWARD OCR2B
#define PWM_LEFT OCR0B
#define PWM_RIGHT OCR0A
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
/*								Datastruct                              */
/************************************************************************/
typedef struct data{

	// The value from the LDR
	int lightvalue;
	
	// State value
	uint8_t oldstate;
	uint8_t state;

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
	
	/************************************************************************/
	/*						BT Send Buffer									*/
	/*	Position 0 = Front sensor											*/
	/*	Position 1 = Back sensor											*/
	/*	Position 2 = Left sensor			 								*/
	/*	Position 3 = Right sensor											*/                                                               
	/************************************************************************/
	volatile uint8_t BT_send_buffer[20];
	
	/************************************************************************/
	/*						BT Receive Buffer								*/
	/*	Position 0 = status													*/
	/*	Position 1 = Speed													*/
	/*	Position 2 = Left													*/
	/*	Position 3 = Right													*/                                                                    
	/************************************************************************/
	volatile  uint8_t BT_recieve_buffer[20];
	volatile uint8_t ISR_Vect_Pos;
	
	volatile uint8_t TWI_Receive_Buffer[10];
	
	uint8_t control_status;
	
	
} *dataptn, DATA;

//Name of the main struct with all the data in for the different sensors and values
volatile DATA DirtyDawg;


void System_Init(void);
void Hardware_Init(void);

void INT_Crash(void);
void Lowrider_Mode(void);
void Sense_Light(void);






void Y_LED_On(void);
void Y_LED_Off(void);


#endif // FUNCTIONS_H_