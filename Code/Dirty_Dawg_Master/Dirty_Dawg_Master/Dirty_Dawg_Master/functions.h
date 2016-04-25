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
#define RIGHT PORTD7

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
uint8_t status;

#define MCU_STARTED 1<<0;
#define UART_STARTED 1<<1;
#define BT_STARTED 1<<2;



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