/*
 * obstacle_car.c
 *
 * Created: 19/05/2020 12:42:56 AM
 *  Author: M
 */ 
#include "Timer2.h"
#include "Timer0.h"
void timer_on();
void timer_off();
void sensor_trig();
void get_display_distance();
uint16_t  total_time=0 , distance=0 ;
uint8_t timer_over_flow=0; 
uint8_t grd=0;
int main(void)
{
	TCCR1A=0;
	TIFR=(1<<ICF1); /*clear input caputre flag*/
	TCCR1B=0x41;	/*capture on rising flag*/
	timer_normal_init();
	PWM_init_timer2_oc2();
	SETBIT(DDRC,2);
    CLRBIT(DDRD,6);
	while(1)
    {
		sensor_trig();
		while (GETBIT(TIFR,ICF1)==0){}			
		timer_on();
		TIFR=(1<<ICF1); /*clear input capture flag*/
		TCCR1B=0x1;	/*capture on falling flag*/
		while (GETBIT(TIFR,ICF1)==0){}
		total_time=TCNT0*1024.0 /16.0;
		total_time=total_time+timer_over_flow*(16230);   // 16230us = 255*1024/16 refers to the ovf_value_for_timer0
		timer_off();
		timer_over_flow=0;
		get_display_distance();
		TIFR=(1<<ICF1); /*clear input caputre flag*/
		TCCR1B=0x41;	/*capture on rising flag*/
		
		if(distance<=400&&distance>10){
		set_duty_oc2(100);
						} 
		if(distance<=10&&distance>=0){
			set_duty_oc2(grd);
							}
		
		 _delay_ms(250);    
		     }
}
		
ISR(TIMER0_OVF_vect){
	timer_over_flow++;
	}
void timer_on(){
	TCNT0=0;
	SETBIT(TCCR0,CS02);
	SETBIT(TCCR0,CS00);
	
}
void timer_off(){
	CLRBIT(TCCR0,CS02);
	CLRBIT(TCCR0,CS00);	
}
void get_display_distance(){
	distance=0.01715*total_time;		// 2x=34300*t & to get time in seconds we multiplied by 10^-6
	}
	
void sensor_trig(){
		SETBIT(PORTC,2);
		_delay_us(10); // ultrasonic data sheet said 10 us pulse will be good for trigger the sensor
		CLRBIT(PORTC,2);
		/*
		c.c = (1/16Mhz)
		time t represent time of starting wave of ultrasonic sensor 
		TCNT0 multiplied by 1023 the brescaler and c.c to know the real time
		*/
}