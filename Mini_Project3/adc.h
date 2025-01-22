/*
 ============================================================================
 Name        : adc.h
 Author      : Menna Tullah Medhat
 Description : ADC will be used to read analog data from sensors such as the
 LM35 temperature sensor and the LDR in the SMART HOME PROJECT.
 Date        : 10/6/2024
 ============================================================================
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

/*The function is going to initialize the ADC by setting the reference
 * voltage to 2.56 and prescaler to F_CPU/128.*/
void ADC_init(void);

/*Reads analog data from a specific ADC channel and converts it to digital.*/
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
