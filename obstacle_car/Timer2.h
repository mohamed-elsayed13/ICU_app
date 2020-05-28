/*
 * Timer2.h
 *
 * Created: 17/05/2020 5:14:23 AM
 *  Author: M
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "header.h"
void timer2_normal_init();
void timer2_compare_init();
void timer2_freq_gen_init(uint8_t value);
void PWM_init_timer2_oc2();
void set_duty_oc2(uint8_t duty);
#endif /* TIMER2_H_ */