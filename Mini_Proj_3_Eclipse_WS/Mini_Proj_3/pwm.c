/*
 * PWM_driver.c
 * Author: SHAHD MOHAMED
 */

#include  "pwm.h"
#include  "gpio.h"
#include <avr/io.h>

/************************************************************************************
 *                 Functions Definitions
 ************************************************************************************/

/*
 * Description:
 * The function responsible for trigger the Timer0 with the PWM Mode, to control
 * DC Motor speed according to temperature sensed by Temperature sensor.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*start counting from zero*/
	TCNT0 =0;

	/* calculate compare value from duty cycle percentage and put it in compare reg */
	OCR0 =(uint8)( (float)(duty_cycle/100.0) *(TIMER0_MAX_COUNT));

	/*set OC0 pin direction to be output pin */
	GPIO_setupPinDirection(OC0_PORT_ID, OC0_PIN_ID, PIN_OUTPUT);

	/*
	 * set WGMO1, WGM00 to one For Fast PWM mode
	 * set COM01 to one and COM00 to zero for non-inverting mode
	 * set CS01 to one and CS00,CS02 to zero for prescalar 8 (F_CPU/8)
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
