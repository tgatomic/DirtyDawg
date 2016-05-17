/*
 * Error_Codes.h
 *
 * Created: 2016-05-17 16:06:30
 *  Author: Atomic
 */ 


#ifndef ERROR_CODES_H_
#define ERROR_CODES_H_

/************************************************************************/
/*	This is a spot for all the different UART errorcodes in this       */
/*	program.                                                            */
/************************************************************************/

#define BAD_VAL 0x01 // Received a value smaller than 0 or greater than 255
#define CMD_FAIL 0x02 // Failed to enter CMD mode in Bluesmirf
#define NO_STATE 0x03 // There was no state initiated







#endif /* ERROR_CODES_H_ */