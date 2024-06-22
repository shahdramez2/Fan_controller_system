/*
 * PWM_driver.h
 * Author: SHAHD MOHAMED
 */

#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include"std_types.h"

/************************************************************************************
 *                              Definitions
 ************************************************************************************/
#define TIMER0_MAX_COUNT          255
#define OC0_PIN_ID                PIN3_ID
#define OC0_PORT_ID               PORTB_ID

/************************************************************************************
 *                             Functions Prototypes
 ************************************************************************************/

/*
 * Description:
 * The function responsible for trigger the Timer0 with the PWM Mode, to control
 * DC Motor speed.
 */

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_DRIVER_H_ */
