/*
 * Timer0.h
 *
 * Created: 16/04/2020 10:11:33 AM
 *  Author: M
 */ 
#include "header.h"

#ifndef TIMER0_H_
#define TIMER0_H_

void timer_normal_init();
void timer_compare_init();
void PWM_init_timer0_oc0();
void set_duty_oc0(uint8_t duty);


#endif /* TIMER0_H_ */