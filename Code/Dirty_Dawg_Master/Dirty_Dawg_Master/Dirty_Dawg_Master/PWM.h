/*
 * PWM.h
 *
 * Created: 2016-04-28 09:54:08
 *  Author: Atomic
 */ 


#ifndef PWM_H_
#define PWM_H_

void PWM_Init(void);
void Stop_Moving(void);
void Drive(uint8_t direction, uint8_t speed);



#endif /* PWM_H_ */