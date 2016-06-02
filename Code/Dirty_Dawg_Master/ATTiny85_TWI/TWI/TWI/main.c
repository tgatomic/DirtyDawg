
#include 	<stdlib.h>
#include 	<avr/io.h>
#include 	<avr/interrupt.h>
#include 	<avr/pgmspace.h>

//################################################################## USI-TWI-I2C

#include 	"usiTwiSlave.h"     		

// Note: The LSB is the I2C r/w flag and must not be used for addressing!
#define 	SLAVE_ADDR_ATTINY       0b00110100 //Correspond to the adress 0x1A

// Sets the clock to 8 MHz								        
#ifndef 	F_CPU
#define 	F_CPU 8000000UL
#endif

//####################################################################### Macros

#define uniq(LOW,HEIGHT)	((HEIGHT << 8)|LOW)			  // Create 16 bit number from two bytes
#define LOW_BYTE(x)        	(x & 0xff)					    // Get low byte from 16 bit number  
#define HIGH_BYTE(x)       	((x >> 8) & 0xff)			  // Get high byte from 16 bit number

#define sbi(ADDRESS,BIT) 	((ADDRESS) |= (1<<(BIT)))	// Set bit
#define cbi(ADDRESS,BIT) 	((ADDRESS) &= ~(1<<(BIT)))// Clear bit
#define	toggle(ADDRESS,BIT)	((ADDRESS) ^= (1<<BIT))	// Toggle bit

#define	bis(ADDRESS,BIT)	(ADDRESS & (1<<BIT))		  // Is bit set?
#define	bic(ADDRESS,BIT)	(!(ADDRESS & (1<<BIT)))		// Is bit clear?

//#################################################################### Variables

	uint16_t 	word=0;			// Counter
	uint8_t		byte1, byte2;
	uint16_t	buffer;
	uint8_t		high,low = 0;	// Variables used with uniq (high and low byte)


//################################################################# Main routine
int main(void)
{	 
  
	// Initiate the TWI for ATTiny
	cli();  // Disable interrupts
	usiTwiSlaveInit(SLAVE_ADDR_ATTINY);	// TWI slave init
	sei();  // Re-enable interrupts
	
	
	
	
	// The data you want to be sent to 328p is saved in txbuffer[]
	// Ex:
	txbuffer[0] = 0x53;
	
	while(1);
} 



