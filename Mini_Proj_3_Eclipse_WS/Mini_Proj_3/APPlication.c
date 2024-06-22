/*
 * File name: APPlication.c
 *Author: SHAHD MOHAMED
 */
#include"adc.h" /* to call ADC_init function */
#include"lcd.h"
#include"lm35_sensor.h"
#include"dc_motor.h"
#include"functions.h"


int main(void)
{
	uint8 temp; /* temp variable to hold value of temperature sensed by temperature sensor */
	ADC_init(&ADC_config); /* Initialize ADC driver */
	LCD_init(); /* Initialize LCD driver */
	DcMotor_Init(); /* Initialize DC_Motor driver */

	while(1)
	{
		/*get temperature from temperature sensor */
		temp=LM35_getTemperature();

		/* Setting Motor_State according to temperature value sensed by temperature sensor */
		if( Set_MotorState(temp) )
		{
			LCD_displayStringRowColumn(0, 4," Fan is ON ");
		}
		else
		{
			LCD_displayStringRowColumn(0,4," Fan is OFF");
		}

		LCD_displayStringRowColumn(1,4," temp= ");
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else if (temp>=10)
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two digits print one extra space*/
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is one digit print two extra space*/
			LCD_displayString("  ");
		}
	}
}


