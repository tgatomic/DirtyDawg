#ifndef SUART_H_
#define SRX     PB0     // ICP on Mega8
#define SRXPIN  PINB

#define STX     PB1     // OC1A on Mega8
#define STXDDR  DDRB

#define XTAL	8000000

#define	BAUD	57600


typedef unsigned char  u8;
typedef   signed char  s8;
typedef unsigned short u16;
typedef   signed short s16;
typedef unsigned long  u32;
typedef   signed long  s32;

extern volatile u8 srx_done;

#define kbhit()	(srx_done)	// true if byte received

void suart_init( void );
void sputchar( u8 val );
u8 sgetchar( void );
void sputs( u8 *txt );
void example_main( void );

#endif