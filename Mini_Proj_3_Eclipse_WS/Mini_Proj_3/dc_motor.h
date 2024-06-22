/*
 * File name: DC_Motor.h
 *
 *      Author: SHAHD MOHAMED
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                          Types Declaration                                  *
 *******************************************************************************/
#define DC_MOTOR_FIRST_BIN_PORT_ID           PORTB_ID
#define DC_MOTOR_FIRST_BIN_ID                PIN0_ID
#define DC_MOTOR_SECOND_BIN__PORT_ID         PORTB_ID
#define DC_MOTOR_SECOND_BIN_ID               PIN1_ID

/*******************************************************************************
 *                          Types Declaration                                  *
 *******************************************************************************/
typedef enum
{
	STOP, CW, A_CW
}DcMotor_State;


/*******************************************************************************
 *                          Functions Prototypes                               *
 *******************************************************************************/

/*
 * Description:
 *  1.The Function responsible for setup the direction for the two
 *  motor pins through the GPIO driver.
 *  2.Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description:
 * 1.The function responsible for rotate the DC Motor CW/ or A-CW or
 *   stop the motor based on the state input state value.
 * 2.Send the required duty cycle to the PWM driver based on the
 *   required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
