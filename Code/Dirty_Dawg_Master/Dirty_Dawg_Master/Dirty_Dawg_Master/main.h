/*
 * main.h
 *
 * Created: 2016-05-24 16:02:12
 *  Author: Atomic
 */ 


#ifndef MAIN_H_
#define MAIN_H_

/************************************************************************/
/*								Status                                 */
/************************************************************************/

#define LIGHTS (1<<0)
#define STOP (1<<1)
#define REVERSE (1<<2)
#define TURN_LEFT (1<<3)
#define TURN_RIGHT (1<<4)


//If everything is 0, we will drive forward..


/************************************************************************/
/*								Messages                                */
/************************************************************************/

#define OK 0x06
#define START_TRANSMIT 0x53
#define NO_STATE_STR "No state"

/************************************************************************/
/*								Flags                                */
/************************************************************************/

uint8_t flags;
#define PAIRED (1<<0)

/************************************************************************/
/*							States & Functions					        */
/************************************************************************/

#define LIGHT_STATE 0x00
#define BLUETOOTH_STATE 0x01
#define SENSOR_STATE 0x02
#define DRIVE_STATE 0x03
#define PAIRING_STATE 0x04




#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))

void Lights(void);
void Bluetooth(void);
void Sensors(void);
void Vroom(void);
void Pairing(void);
void test(void);




#endif /* MAIN_H_ */