/*
 * File name: functions.c
 *
 * Author: SHAHD MOHAMED
 */

#include"functions.h"
#include"dc_motor.h"

/*
 * Description:
 * Function to drive the speed of the fan according to temperature
 * measured from the sensor
 */
Motor_Power Set_MotorState(const uint8 temperature)
{
	Motor_Power state = ON;

	/* setting DcMotor state according to the range of the temperatur */
	if(FIRST_RANGE(temperature))
	{
		DcMotor_Rotate(STOP, ZERO_SPEED);
		state= OFF;
	}
	else if(SECOND_RANGE(temperature))
	{
		DcMotor_Rotate(CW, QUARTER_THE_MAX_SPEED);
	}
	else if(THIRD_RANGE(temperature))
	{
		DcMotor_Rotate(CW, HALF_THE_MAX_SPEED);
	}
	else if(FOURTH_RANGE(temperature))
	{
		DcMotor_Rotate(CW, THREE_QUARTERS_THE_MAX_SPEED);
	}
	else if(FIFTH_RANGE(temperature))
	{
		DcMotor_Rotate(CW, MAX_SPEED);
	}

	return state;
}


