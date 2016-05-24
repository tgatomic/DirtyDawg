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

uint8_t control_status;

#define LIGHTS (1<<0)
#define STOP (1<<1)
#define F_OR_B (1<<2)


/************************************************************************/
/*								Messages                                */
/************************************************************************/

#define OK 0x06
#define START_TRANSMIT 0x53
#define NO_STATE_STR "No state"




#endif /* MAIN_H_ */