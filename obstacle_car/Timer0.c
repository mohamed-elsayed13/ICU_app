/*
 * Timer0.c
 *
 * Created: 16/04/2020 10:11:10 AM
 *  Author: M
 */ 
#include "Timer0.h"

void timer_normal_init(){
	TCCR0= (1<<FOC0) | (1<<CS02) | (1<<CS00);
	SETBIT(TIMSK,TOIE0);

}
void timer_compare_init(){
	TCCR0= (1<<FOC0) | (1<<CS02) | (1<<CS00) | (1<<WGM01);
	OCR0 =200;
	SETBIT(TIMSK,OCIE0);
	
}
void PWM_init_timer0_oc0(){
	SETBIT(DDRB,3);
	TCCR0= (1<<COM01)|(1<<WGM00)|(1<<WGM01)|(1<<CS00);
}
void set_duty_oc0(uint8_t duty){
	OCR0=2.55*duty;
}
