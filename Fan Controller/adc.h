/*
 * adc.h
 *
 *  Created on: May 4, 2023
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_


#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	INTERNAL_AREF_OFF,AVCC,RESERVED,INTERNAL_AREF
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_2,F_CPU_4 = 2,F_CPU_8 = 3,F_CPU_16 = 4,F_CPU_32 = 5,F_CPU_64 = 6,F_CPU_128 = 7
}ADC_Prescaler;


typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType *Config_ptr);

uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
