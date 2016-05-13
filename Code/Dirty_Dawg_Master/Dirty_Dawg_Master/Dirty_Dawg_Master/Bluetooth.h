/*
 * Bluetooth.h
 *
 * Created: 2016-05-13 16:35:28
 *  Author: Atomic
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

int BT_Init(void);
void UART_Init(unsigned int baud);

uint8_t BT_Recieve(void);
void Uart_Flush(void);

void Error(unsigned int errorcode);

#endif /* BLUETOOTH_H_ */