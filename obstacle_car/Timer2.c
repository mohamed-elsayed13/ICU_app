/*
 * Timer2.c
 *
 * Created: 17/05/2020 5:14:03 AM
 *  Author: M
 */ 
#include "Timer2.h"
void timer2_normal_init(){
	TCCR2= (1<<FOC2)|(1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK |= 1<<TOIE2;
	sei();
}
void timer2_compare_init(){
	TCCR2= (1<<FOC2)|(1<<WGM21)|(1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK |= 1<<OCIE2;
	OCR2=200;
	sei();
}
void timer2_freq_gen_init(uint8_t value){
	SETBIT(DDRD,7);
	TCCR2= (1<<FOC2)|(1<<WGM21)|(1<<CS20)|(1<<COM20);
	OCR2=value;
	}
void PWM_init_timer2_oc2(){
	SETBIT(DDRD,7);
	TCCR2= (1<<COM21)|(1<<WGM20)|(1<<WGM21)|(1<<CS20);
}
void set_duty_oc2(uint8_t duty){
	OCR2=2.55*duty;
}
