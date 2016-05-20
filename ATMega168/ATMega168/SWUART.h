#ifdef _AVR_IOM8_H_
#define SRX     PB0     // ICP on Mega8
#define SRXPIN  PINB

#define STX     PB1     // OC1A on Mega8
#define STXDDR  DDRB

#elif _AVR_IOM644_H_

#define SRX		PD2 //INT0 pin
#define SRXPIN	PIND

#define STX		PD3 //INT1 pin
#define STXDDR	DDRD

#elif _AVR_IOM168P_H_

#define SRX		PORTD2
#define SRXPIN	PIND

#define STX		PORTD3
#define STXDDR	DDRD



#else
#error
#error Please add the defines:
#error
#error SRX, SRXPIN, STX, STXDDR
#error
#error for the new target !
#error
#endif

//Typedefs to make life easier
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

struct bits {
	u8 b0:1;
	u8 b1:1;
	u8 b2:1;
	u8 b3:1;
	u8 b4:1;
	u8 b5:1;
	u8 b6:1;
	u8 b7:1;
} __attribute__((__packed__));

#define SBIT_(port,pin) ((*(volatile struct bits*)&port).b##pin)
#define	SBIT(x,y)	SBIT_(x,y)
