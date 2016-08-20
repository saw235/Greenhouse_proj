#include "gb_common.h"
#include "gb_pwm.h"

void setup_gpio(void)
{
	//set GPIO18 to pwm mode
	INP_GPIO(18); SET_GPIO_ALT(18, 5);
}

void main(void)
{
	int s;
	setup_io();
	setup_gpio();
	setup_pwm();
	
	force_pwm0(0,PWM0_ENABLE);
	
	//value of s can be set to control the fan speed, where 0x100 is the lowest and 0x400 is the highest.
	//the fan continues to run by itself 
	for (s=0x100; s<=0x400; s+=0x10)
		{
			long_wait(6);
			set_pwm0(s);
		}
	for (s=0x400; s>=0x100; s-=0x10)
		{
			long_wait(6);
			set_pwm0(s);
		}

	
	set_pwm0(0x000);
	pwm_off();
	restore_io();

}
