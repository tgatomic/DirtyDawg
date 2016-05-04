/*
 * LCD.h
 *
 * Created: 2016-05-04 11:05:59
 *  Author: Atomic
 */ 


#ifndef LCD_H_
#define LCD_H_


#define LCD_RS_PIN 6
#define LCD_RW_PIN 5
#define LCD_DATA0_PIN 0
#define LCD_DATA1_PIN 1
#define LCD_DATA2_PIN 2
#define LCD_DATA3_PIN 3
#define LCD_E_PIN 4
#define LCD_LED_PIN 7
#define LCD_ENTRY_MODE 2
#define LCD_ENTRY_INC 6
#define LCD_MODE_DEFAULT ((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC))


void LCD_Init(uint8_t addr);
void LCD_Command(uint8_t command);
void LCD_toggle(void);
void LCD_Print(uint8_t command);

	
	
	



#endif /* LCD_H_ */