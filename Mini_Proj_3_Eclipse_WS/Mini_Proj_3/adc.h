/*
 * adc.h
 *
 *  Author: SHAHD MOHAMED
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include"std_types.h"

/************************************************************************************
 *                             Definitions
 ************************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/************************************************************************************
 *                            Types Declarations
 ************************************************************************************/

typedef enum
{
	EXTERNAL_VREF, AVCC, RESERVED, INTERNAL_AREF
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_,F_CPU_2 ,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/************************************************************************************
 *                            Functions Prototypes
 ************************************************************************************/

/*
 * Description:
 * Function to set Vref and Prescalar for ADC
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description:
 * Function to start the conversion and return digital value on the
 * chosen channel when conversion is done.
 */
uint16 ADC_readChannel(uint8 channel_num);


/************************************************************************************
 *                          Extern Declarations
 ************************************************************************************/

extern ADC_ConfigType ADC_config;

#endif /* ADC_DRIVER_H_ */
