/*
 * Bluetooth.h
 *
 * Created: 2016-05-13 16:35:28
 *  Author: Atomic
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

void BT_Pair(void);
void UART_Init(unsigned int baud);

void BT_Send(unsigned char data);

uint8_t BT_Recieve(void);
void Uart_Flush(void);

void Error(unsigned int errorcode);

#endif /* BLUETOOTH_H_ */