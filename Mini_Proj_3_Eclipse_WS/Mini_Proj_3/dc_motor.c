/*
 * File name: DC_Motor.c
 *
 *  Author: SHAHD MOHAMED
 */

#include"dc_motor.h"
#include"gpio.h"
#include"pwm.h"

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

/*
 * Description:
 *  1.The Function responsible for setup the direction for the two
 *  motor pins through the GPIO driver.
 *  2.Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	/* Setup DC_Motor two pins to be output pins */
	GPIO_setupPinDirection(DC_MOTOR_FIRST_BIN_PORT_ID, DC_MOTOR_FIRST_BIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_SECOND_BIN__PORT_ID, DC_MOTOR_SECOND_BIN_ID, PIN_OUTPUT);

	/*Stop DC_Motor at the beginning when calling the function */
	GPIO_writePin(DC_MOTOR_FIRST_BIN_PORT_ID, DC_MOTOR_FIRST_BIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_SECOND_BIN_ID, DC_MOTOR_SECOND_BIN_ID, LOGIC_LOW);
}

/*
 * Description:
 * 1.The function responsible for rotate the DC Motor CW/ or A-CW or
 *   stop the motor based on the state input state value.
 * 2.Send the required duty cycle to the PWM driver based on the
 *   required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*Set motor state to stop or rotate CW/ OR A-CW */
	switch(state)
	{
	case STOP:
		GPIO_writePin(DC_MOTOR_FIRST_BIN_PORT_ID, DC_MOTOR_FIRST_BIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_SECOND_BIN__PORT_ID, DC_MOTOR_SECOND_BIN_ID, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(DC_MOTOR_FIRST_BIN_PORT_ID, DC_MOTOR_FIRST_BIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_SECOND_BIN__PORT_ID, DC_MOTOR_SECOND_BIN_ID, LOGIC_HIGH);
		break;
	case A_CW:
		GPIO_writePin(DC_MOTOR_FIRST_BIN_PORT_ID, DC_MOTOR_FIRST_BIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_SECOND_BIN__PORT_ID, DC_MOTOR_SECOND_BIN_ID, LOGIC_HIGH);
		break;
	}

	/*Send the required duty cycle to the PWM driver based on the required speed value*/
	 PWM_Timer0_Start(speed);
}
