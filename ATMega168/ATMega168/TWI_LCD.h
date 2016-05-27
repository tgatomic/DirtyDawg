/*
 * TWI_LCD.h
 *
 * Created: 2016-05-11 11:16:05
 *  Author: Atomic
 */ 


#ifndef TWI_LCD_H_
#define TWI_LCD_H_

#define LCD_CMD 0
#define LCD_CHR 1
#define LCD_ADDR 0x27

#define LCD_LINE_1 0x80
#define LCD_LINE_2 0xC0
#define LCD_CLEAR 0x01

#define LCD_BACKLIGHT 0x08 //ON, 0x00 = OFF
#define LCD_BACKLIGHT_OFF 0x00
#define ENABLE 0x04 //Enable bit 0b00000100

#define DELAY_MS 8 //Equals 1 ms
#define LCD_WRITE (0<<0)

#define LF 0x0A // Line feed
#define CR 0x0D // Carriage return

#endif

#ifndef ARR_SIZE(x)
#define ARR_SIZE(x)  (sizeof(x) / sizeof(x[0]))

void LCD_Init(void);
void LCD_Byte(uint8_t, uint8_t);
void LCD_Toggle_enable(uint8_t);
void LCD_String(uint8_t *);
void Write_Byte(uint8_t, uint8_t);

#endif /* TWI_LCD_H_ */